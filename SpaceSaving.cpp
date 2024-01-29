// SpaceSaving.cpp
#include "SpaceSaving.h"
#include "PairHash.h"

SpaceSaving::SpaceSaving(double epsilon1, double epsilon2, double phi1, double phi2)
    : epsilon1(epsilon1), epsilon2(epsilon2), phi1(phi1), phi2(phi2) {
    initialize();
}

void SpaceSaving::initialize() {
    beta = 1 / (epsilon2 * phi1);
    gamma = (epsilon2 + phi2) / (epsilon2 * phi1);

    k1 = static_cast<int>(std::max(1 / epsilon1, gamma + std::sqrt(beta * gamma)));
    k2 = static_cast<int>(beta * k1 / (k1 - gamma));

    counterMapSp.clear();
    counterMapSt.clear();
    counterMapSp.reserve(static_cast<std::size_t>(k1));
    counterMapSt.reserve(static_cast<std::size_t>(k2));
}

void SpaceSaving::update(const std::pair<char, char>& tuple) {
    SpaceSavingUpdate(counterMapSp, tuple.first);
    SpaceSavingUpdate(counterMapSt, tuple);
}

void SpaceSaving::querySt() {
    std::unordered_set<char> primaryItems;

    // Calculate the total frequency in the primary stream summary (N)
    int totalFrequencySp = 0;
    for (const auto& entry : counterMapSp) {
        totalFrequencySp += entry.second;
    }

    // Step 1: Collect primary items and their frequencies from Sp
    for (const auto& entry : counterMapSp) {
        if (entry.second > phi1 * totalFrequencySp) {
            primaryItems.insert(entry.first);
        }
    }

    // Step 2: Check for correlated items in St
    for (const auto& entry : counterMapSt) {
        char r = entry.first.first;
        char s = entry.first.second;
        int frs = entry.second;

        // Check if r is a primary frequent item and if frs > phi2 * (fr - N/k1)
        if (primaryItems.count(r) && frs > phi2 * (counterMapSp.at(r) - totalFrequencySp / k1)) {
            // Correlated heavy hitter detected
            std::cout << "Correlated heavy hitter: (" << r << ", " << s << ", " << frs << ")" << std::endl;
        }
    }
}


void SpaceSaving::printCounts() const {
    std::cout << "S_p counts:" << std::endl;
    printMap(counterMapSp);
    std::cout << "S_t counts:" << std::endl;
    printMap(counterMapSt);
}

void SpaceSaving::SpaceSavingUpdate(std::unordered_map<char, int>& counterMap, const char& item) {
    auto it = counterMap.find(item);
    if (it != counterMap.end()) {
        it->second++;
    } else {
        if (counterMap.size() < k1) {
            counterMap.emplace(item, 1);
        } else {
            auto minCountItem = std::min_element(counterMap.begin(), counterMap.end(),
                                                 [](const auto& lhs, const auto& rhs) {
                                                     return lhs.second < rhs.second;
                                                 });
            counterMap.erase(minCountItem);
            counterMap.emplace(item, 1);
        }
    }
}

void SpaceSaving::SpaceSavingUpdate(std::unordered_map<std::pair<char, char>, int, PairHash>& counterMap, const std::pair<char, char>& tuple) {
    auto it = counterMap.find(tuple);
    if (it != counterMap.end()) {
        it->second++;
    } else {
        if (counterMap.size() < k2) {
            counterMap.emplace(tuple, 1);
        } else {
            auto minCountItem = std::min_element(counterMap.begin(), counterMap.end(),
                                                 [](const auto& lhs, const auto& rhs) {
                                                     return lhs.second < rhs.second;
                                                 });
            counterMap.erase(minCountItem);
            counterMap.emplace(tuple, 1);
        }
    }
}


void SpaceSaving::printMap(const std::unordered_map<char, int>& counterMap) const {
    for (const auto& entry : counterMap) {
        std::cout << "'" << entry.first << "' : " << entry.second << std::endl;
    }
}


void SpaceSaving::printMap(const std::unordered_map<std::pair<char, char>, int, PairHash>& counterMap) const {
    for (const auto& entry : counterMap) {
        std::cout << "('" << entry.first.first << "', '" << entry.first.second << "') : " << entry.second << std::endl;
    }
}

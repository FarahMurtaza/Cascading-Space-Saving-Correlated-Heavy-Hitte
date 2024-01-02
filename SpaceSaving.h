#ifndef SPACESAVING_H
#define SPACESAVING_H

#pragma once

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include "PairHash.h"

class SpaceSaving {
public:
    SpaceSaving(double epsilon1, double epsilon2, double phi1, double phi2);

    void initialize();

    void update(const std::pair<char, char>& tuple);

    int querySp(const char& item) const;

    // void querySt(std::vector<std::pair<std::pair<char, char>, int>>& correlatedPairs) const;
    void querySt();

    void printCounts() const;

private:
    double epsilon1, epsilon2, phi1, phi2, beta, gamma;
    int k1, k2;

    std::unordered_map<char, int> counterMapSp;
    std::unordered_map<std::pair<char, char>, int, PairHash> counterMapSt;  // Use custom hash function

    void SpaceSavingUpdate(std::unordered_map<char, int>& counterMap, const char& item);

    void SpaceSavingUpdate(std::unordered_map<std::pair<char, char>, int, PairHash>& counterMap, const std::pair<char, char>& tuple);

    void printMap(const std::unordered_map<char, int>& counterMap) const;
    void printMap(const std::unordered_map<std::pair<char, char>, int, PairHash>& counterMap) const;
};

#endif // SPACESAVING_H
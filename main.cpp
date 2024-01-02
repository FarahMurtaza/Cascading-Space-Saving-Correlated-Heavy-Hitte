#include <iostream>
#include <fstream>
#include "SpaceSaving.h"

int main() {
    // Read characters from the file
    std::ifstream inputFile("character.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }

    std::vector<char> inputStream;
    char character;
    while (inputFile >> character) {
        inputStream.push_back(character);
    }

    inputFile.close();

    SpaceSaving spaceSaving(0.4, 0.5, 0.1, 0.2);

    // Update: Loop through pairs
    for (std::size_t i = 0; i < inputStream.size() - 1; ++i) {
        std::pair<char, char> itemPair = {inputStream[i], inputStream[i + 1]};
        spaceSaving.update(itemPair);
    }

    spaceSaving.printCounts();

    spaceSaving.querySt();

    return 0;
}

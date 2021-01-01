#pragma once

#include <algorithm>
#include <string>
#include <sstream>
#include <vector>

void removeSpaces(std::string &inputLine, std::vector<std::string> &matchInputs) {
    std::istringstream inputLineStream(inputLine);

    std::string word;
    while (inputLineStream >> word) {
        matchInputs.push_back(word);
    }
}
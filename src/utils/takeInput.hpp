#pragma once

#include <fstream>
#include <vector>
#include <string>
#include <cctype>

#define RESET   "\033[0m"
#define RED     "\033[1m\033[31m"

bool hasOnlySpaces(std::string inputLine) {
    for(char c: inputLine) {
        if (!isspace(c)) {
            return false;
        }
    }
    return true;
}

// Read the file and fill the inputs vector with each separate line from file
void takeInputFromFile(std::string fileName ,std::vector<std::string> &inputs) {
    std::fstream readInputfile;
    readInputfile.open(fileName ,std::ios::in);

    if (readInputfile) {
        if (readInputfile.is_open()){
            std::string inputLine;
            while(std::getline(readInputfile, inputLine)){
                if (!inputLine.empty() && (!hasOnlySpaces(inputLine))) {
                    inputs.push_back(inputLine);        
                }
            }
            readInputfile.close();
        }
    }

    else {
        std::cout<<RED<<"File do not exist or is unable to open\n"<<RESET;
    }
}


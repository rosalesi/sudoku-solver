// Implementation of Utils
#include "headers/utils.h"
#include <sstream>

std::vector<std::string> Utils::split(std::string phrase) {
    std::string buf;
    std::stringstream ss(phrase);
    std::vector<std::string> tokens;
    while (ss >> buf) {
        tokens.push_back(buf);
    }
    return tokens;
}
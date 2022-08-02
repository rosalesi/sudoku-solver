// Implementation of Utils
#include "headers/utils.h"
#include <sstream>
#include <vector>

// Split string into string array
std::vector<std::string> Utils::split(std::string phrase) {
    std::string buf;
    std::stringstream ss(phrase);
    std::vector<std::string> tokens;
    while (ss >> buf) {
        tokens.push_back(buf);
    }
    return tokens;
}

// Collect the users sudoku to be solved
Sudoku Utils::promptSudoku() {
    std::vector<std::vector<std::string>> newSudokuVect;
    std::cout << "Welcome to the Sudoku Solver!" << std::endl;
    std::cout << "Please input an unsolved 9x9 Sudoku row by row using 0's as empty spaces" << std::endl;
    std::cout << "Ex. (0 0 0 4 0 0 5 0 0)" << std::endl;

    std::string rowString;
    std::vector<std::string> rowVect;
    for (int i = 0; i < 9; i++) {
        getline(std::cin, rowString);
        rowVect = split(rowString);
        newSudokuVect.push_back(rowVect);
    }

    return newSudokuVect;
}
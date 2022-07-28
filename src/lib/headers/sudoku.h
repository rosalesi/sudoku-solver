// Header for Sudoku
#pragma once
#include <vector>
#include <iostream>

class Sudoku {
    private:
        std::vector< std::vector<std::string> > puzzle;
    public:
        // Default constructor creates a 9x9 of 0's
        Sudoku();

        // Custom constructor for a Sudoku puzzle
        Sudoku(std::vector< std::vector<std::string> > aPuzzle);

        // Is the Sudoku puzzle solved?
        bool isSolved();
};
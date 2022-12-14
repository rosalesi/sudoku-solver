// Header for Sudoku
#pragma once
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <tuple>

class Sudoku {
    private:
        std::vector< std::vector<std::string> > puzzle;
    public:
        // Default constructor creates a 9x9 of 0's
        Sudoku();

        // Custom constructor for a Sudoku puzzle
        Sudoku(std::vector< std::vector<std::string> > aPuzzle);

        // Get puzzle
        std::vector< std::vector<std::string> > getPuzzle();
        
        // Is the Sudoku puzzle solved?
        bool isSolved();

        // Print Sudoku
        void printSudoku();

        // Solve the sudoku
        Sudoku solve();
};
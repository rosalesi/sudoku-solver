// Header for Sudoku
#pragma once
#include <vector>
#include <iostream>

class Sudoku {
    private:
        std::vector< std::vector<int> > puzzle;
    public:
        Sudoku();
        Sudoku(std::vector< std::vector<int> > aPuzzle);
        bool solved();
};
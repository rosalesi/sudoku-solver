// Implementation of Sudoku
#include "headers/sudoku.h"

Sudoku::Sudoku() {
    std::vector< std::vector<int> > defaultSudoku;
    std::vector< int > row;
    for (int i = 0; i < 9; i++) {
        row.push_back(0);
    }
    for (int i = 0; i < 9; i++) {
        defaultSudoku.push_back(row);
    }
    puzzle = defaultSudoku;
}

Sudoku::Sudoku(std::vector< std::vector<int> > aPuzzle) {
    puzzle = aPuzzle;
}

bool Sudoku::solved() {
    return true;
}
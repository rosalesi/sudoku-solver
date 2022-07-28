// Implementation of Sudoku
#include "headers/sudoku.h"

Sudoku::Sudoku() {
    std::vector<std::vector<std::string> > defaultSudoku {
                {"0", "0", "0", "0", "0", "0", "0", "0", "0"},
                {"0", "0", "0", "0", "0", "0", "0", "0", "0"},
                {"0", "0", "0", "0", "0", "0", "0", "0", "0"},
                {"0", "0", "0", "0", "0", "0", "0", "0", "0"},
                {"0", "0", "0", "0", "0", "0", "0", "0", "0"},
                {"0", "0", "0", "0", "0", "0", "0", "0", "0"},
                {"0", "0", "0", "0", "0", "0", "0", "0", "0"},
                {"0", "0", "0", "0", "0", "0", "0", "0", "0"},
                {"0", "0", "0", "0", "0", "0", "0", "0", "0"}
            };
    puzzle = defaultSudoku;
}

Sudoku::Sudoku(std::vector< std::vector<std::string> > aPuzzle) {
    puzzle = aPuzzle;
}

bool Sudoku::isSolved() {
    return true;
}
#include "headers/solver.h"

Solver::Solver(Sudoku aSudoku) {
    sudoku = aSudoku;
    solvedSudoku = sudoku.solve();
}

// Get solvedSudoku
Sudoku Solver::getSolvedSudoku() {
    return solvedSudoku;
}
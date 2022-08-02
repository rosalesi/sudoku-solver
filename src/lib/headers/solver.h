// Header for Solver
#include "sudoku.h"

class Solver {
    private:
        Sudoku sudoku;
        Sudoku solvedSudoku;
    public:

        // Constructor with Sudoku input
        Solver(Sudoku aSudoku);

        // Get solvedSudoku
        Sudoku getSolvedSudoku();
};
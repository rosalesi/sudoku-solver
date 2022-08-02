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

// getPuzzle
std::vector< std::vector<std::string> > Sudoku::getPuzzle() {
    return puzzle;
}

// isSolved
bool Sudoku::isSolved() {
    std::map<int, std::set<std::string> > ROWMAP;
    std::map<int, std::set<std::string> > COLMAP;
    std::map<std::tuple<int, int>, std::set<std::string> > GRIDMAP;
    for (int i = 0; i < 9; i++) {
        ROWMAP.insert(std::pair<int, std::set<std::string> >(i, std::set<std::string>()));
        COLMAP.insert(std::pair<int, std::set<std::string> >(i, std::set<std::string>()));
        GRIDMAP.insert(std::pair<std::tuple<int, int>, std::set<std::string>>(std::make_tuple(i/3, i/3), std::set<std::string>()));
    }

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            std::string cell = puzzle[i][j];
            if (cell == "0"
                || ROWMAP[i].find(cell) != ROWMAP[i].end()
                || COLMAP[j].find(cell) != COLMAP[j].end()
                || GRIDMAP[std::make_tuple(i/3, j/3)].find(cell) != GRIDMAP[std::make_tuple(i/3, j/3)].end()) {
                return false;
            }
            ROWMAP[i].insert(cell);
            COLMAP[j].insert(cell);
            GRIDMAP[std::make_tuple(i/3, j/3)].insert(cell);
        }
    }
    return true;
}

// Print Sudoku
void Sudoku::printSudoku() {
    for (std::vector<std::string> vec : puzzle) {
        for (std::string num : vec) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
}

// Solve the sudoku
Sudoku Sudoku::solve() {
    std::vector<std::vector<std::string>> ansPuzzle = puzzle;

    auto isPresentInBox = [&](int boxStartRow, int boxStartCol, std::string num) {
        for (int row = 0; row < 3; row++)
            for (int col = 0; col < 3; col++)
                if (ansPuzzle[row+boxStartRow][col+boxStartCol] == num)
                    return true;
        return false;
    };

    auto isPresentInCol = [&](int col, std::string num) {
        for (int row = 0; row < 9; row++)
            if (ansPuzzle[row][col] == num)
                return true;
        return false;
    };

    auto isPresentInRow = [&](int row, std::string num) {
         for (int col = 0; col < 9; col++)
            if (ansPuzzle[row][col] == num)
                return true;
        return false;
    };

    auto isValidPlace = [&](int row, int col, std::string num) {
        return !isPresentInRow(row, num) && !isPresentInCol(col, num) && !isPresentInBox(row - row%3 ,col - col%3, num);
    };

    auto findEmptyPlace = [&](int &row, int &col) {
        for (row = 0; row < 9; row++)
            for (col = 0; col < 9; col++)
                if (ansPuzzle[row][col] == "0") //marked with 0 is empty
                    return true;
        return false;
    };

    auto solve_sudoku = [&](auto&& solve_sudoku) {
        int row, col;
        if (!findEmptyPlace(row, col))
            return true;
        for (int num = 1; num <= 9; num++){
            if (isValidPlace(row, col, std::to_string(num))){
                ansPuzzle[row][col] = std::to_string(num);
                if (solve_sudoku(solve_sudoku))
                    return true;
                ansPuzzle[row][col] = "0";
            }
        }
        return false;
    };

    Sudoku hopefullySolved = Sudoku(ansPuzzle);
    hopefullySolved.printSudoku();
    if(solve_sudoku(solve_sudoku) == true) {
        return Sudoku(ansPuzzle);
    } else {
        std::cout << "No solution" << std::endl;
        return Sudoku(ansPuzzle);
    }
}
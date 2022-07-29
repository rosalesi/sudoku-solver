// Implementation of Sudoku
#include "headers/sudoku.h"
#include <map>
#include <set>
#include <tuple>

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
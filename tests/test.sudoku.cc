#include "gtest/gtest.h"
#include "src/lib/headers/sudoku.h"

// Tests for the class Sudoku
class SudokuTest : public::testing::Test {
    protected:
        std::vector< std::vector<std::string> > defaultSudoku;
        std::vector< std::vector<std::string> > secondVec;

        Sudoku firstPuzzle;
        Sudoku secondPuzzle;
        Sudoku thirdPuzzle;
        Sudoku fourthPuzzle;
        Sudoku fifthPuzzle;
        Sudoku fifthSolved;
        Sudoku firstSolved;
        void SetUp() override {
            defaultSudoku = {
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
            secondVec = {
                {"8", "2", "7", "1", "5", "4", "3", "9", "6"},
                {"9", "6", "5", "3", "2", "7", "1", "4", "8"},
                {"3", "4", "1", "6", "8", "9", "7", "5", "2"},
                {"5", "9", "3", "4", "6", "8", "2", "7", "1"},
                {"4", "7", "2", "5", "1", "3", "6", "8", "9"},
                {"6", "1", "8", "9", "7", "2", "4", "3", "5"},
                {"7", "8", "6", "2", "3", "5", "9", "1", "4"},
                {"1", "5", "4", "7", "9", "6", "8", "2", "3"},
                {"2", "3", "9", "8", "4", "1", "5", "6", "7"}
            };
            std::vector<std::vector<std::string> > thirdVec {
                {"4", "3", "5", "2", "6", "9", "7", "8", "1"},
                {"6", "8", "2", "5", "7", "1", "4", "9", "3"},
                {"1", "9", "7", "8", "3", "4", "5", "6", "2"},
                {"8", "2", "6", "1", "9", "5", "3", "4", "7"},
                {"3", "7", "4", "6", "8", "2", "9", "1", "5"},
                {"9", "5", "1", "7", "4", "3", "6", "2", "8"},
                {"5", "1", "9", "3", "2", "6", "8", "7", "4"},
                {"2", "4", "8", "9", "5", "7", "1", "3", "6"},
                {"7", "6", "3", "4", "1", "8", "2", "5", "9"}
            };
            std::vector<std::vector<std::string> > fourthVec {
                {"4", "3", "2", "5", "6", "9", "7", "8", "1"},
                {"6", "8", "2", "5", "7", "1", "4", "9", "3"},
                {"1", "9", "7", "8", "3", "4", "5", "6", "2"},
                {"8", "2", "6", "1", "9", "5", "3", "4", "7"},
                {"3", "7", "4", "6", "8", "2", "9", "1", "5"},
                {"9", "5", "1", "7", "4", "3", "6", "2", "8"},
                {"5", "1", "9", "3", "2", "6", "8", "7", "4"},
                {"2", "4", "8", "9", "5", "7", "1", "3", "6"},
                {"7", "6", "3", "4", "1", "8", "2", "5", "9"}
            };
            std::vector<std::vector<std::string> > fifthVec {
                {"4", "0", "5", "7", "0", "8", "0", "0", "0"},
                {"9", "0", "7", "0", "0", "5", "0", "1", "0"},
                {"3", "0", "0", "4", "1", "0", "5", "2", "0"},
                {"0", "0", "0", "2", "9", "0", "3", "8", "6"},
                {"0", "0", "8", "0", "4", "7", "0", "9", "2"},
                {"1", "0", "2", "0", "3", "0", "0", "7", "0"},
                {"2", "6", "0", "1", "0", "0", "0", "0", "9"},
                {"0", "5", "0", "6", "7", "0", "0", "0", "0"},
                {"0", "4", "0", "0", "0", "2", "6", "0", "8"}
            };

            firstPuzzle = Sudoku();
            secondPuzzle = Sudoku(secondVec);
            thirdPuzzle = Sudoku(thirdVec);
            fourthPuzzle = Sudoku(fourthVec);
            fifthPuzzle = Sudoku(fifthVec);
            fifthSolved = fifthPuzzle.solve();
            firstSolved = firstPuzzle.solve();
        }
};

// Tests for the constructor Methods on a Sudoku
TEST_F(SudokuTest, testConstructorsAndGetPuzzle) {
    EXPECT_EQ(firstPuzzle.getPuzzle(), defaultSudoku);
    EXPECT_EQ(secondPuzzle.getPuzzle(), secondVec);
}

// Tests for the method isSolved on a Sudoku
TEST_F(SudokuTest, testIsSolved) {
    EXPECT_EQ(firstPuzzle.isSolved(), false);
    EXPECT_EQ(secondPuzzle.isSolved(), true);
    EXPECT_EQ(thirdPuzzle.isSolved(), true);
    EXPECT_EQ(fourthPuzzle.isSolved(), false);
}

// Tests for the method solve on a Sudoku
TEST_F(SudokuTest, testSolve) {
    EXPECT_EQ(fifthSolved.isSolved(), true);
    EXPECT_EQ(firstSolved.isSolved(), true);
}
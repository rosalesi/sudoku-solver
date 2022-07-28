#include "gtest/gtest.h"
#include "src/lib/headers/sudoku.h"

// Tests for the class Sudoku
class SudokuTest : public::testing::Test {
    protected:
        Sudoku firstPuzzle;
        Sudoku secondPuzzle;
        Sudoku thirdPuzzle;
        Sudoku fourthPuzzle;
        void SetUp() override {
            std::vector<std::vector<std::string> > secondVec {
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

            firstPuzzle = Sudoku();
            secondPuzzle = Sudoku(secondVec);
            thirdPuzzle = Sudoku(thirdVec);
            fourthPuzzle = Sudoku(fourthVec);
        }
};

// Tests for the method isSolved on a Sudoku
TEST_F(SudokuTest, testIsSolved) {
    EXPECT_FALSE(firstPuzzle.isSolved());
    EXPECT_TRUE(secondPuzzle.isSolved());
    EXPECT_TRUE(thirdPuzzle.isSolved());
    EXPECT_FALSE(fourthPuzzle.isSolved());
}
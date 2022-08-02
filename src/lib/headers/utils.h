// Header for Utils
#include <sstream>
#include <vector>
#include "src/lib/headers/sudoku.h"

class Utils {
    public:
        // Split a string into an array of strings
        std::vector<std::string> split(std::string phrase);

        // Collect the users sudoku to be solved
        Sudoku promptSudoku();
};
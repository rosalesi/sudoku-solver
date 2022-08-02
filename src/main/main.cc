#include "src/lib/headers/solver.h"
#include "src/lib/headers/utils.h"

int main() {
    Utils utils = Utils();
    Solver solver = Solver(utils.promptSudoku());

    std::cout << "Solution:" << std::endl;

    solver.getSolvedSudoku().printSudoku();

    return 0;
}
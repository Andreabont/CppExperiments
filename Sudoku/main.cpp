#include <iostream>
#include "sudoku.h"

int main () {
    
    sudoku schema = {
        {0,0,5,0,0,0,0,0,0},
        {0,0,2,4,0,1,0,7,0},
        {3,0,4,0,0,0,5,6,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,7,9,8,4},
        {8,0,0,0,9,0,0,1,0},
        {0,0,0,2,0,0,1,0,0},
        {0,9,0,0,7,0,0,0,2},
        {0,1,8,3,0,0,0,4,0}
    };
    
    std::cout << schema << std::endl;

    std::cout << "Is valid? " << std::boolalpha <<  schema.check() << std::endl;
    
    std::cout << "Solution..." << std::endl;
    
    if(schema.solve()) {
        std::cout << schema << std::endl;
    } else {
        std::cout << "No solution found!" << std::endl;
    }
    
}


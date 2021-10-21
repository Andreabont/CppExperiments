#include <iostream>

#include "SpMatrix.h"

int main(int argc, char **argv) {   
    
    SpMatrix<int> test = {
        {1,2},
        {3,4,5}
    };
    
    std::cout << "(" << test.getX() << "," << test.getY() << ")" << std::endl;
    std::cout << test.getStr() << std::endl;

    return 0;
}

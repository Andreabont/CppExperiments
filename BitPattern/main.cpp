#include <iostream>
#include "bitpattern.h"

int main() {
    
    if(0b1101010u == BitPattern("11*1**0")) {
        std::cout << "Match!" << std::endl;
    }
    
}

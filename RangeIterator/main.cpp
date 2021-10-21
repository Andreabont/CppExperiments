#include <iostream>
#include <sstream>
#include <chrono>

#include "RangeIterator.h"

int main(int argc, char **argv) {    

    for(int i : Range(10)) {
        std::cout << i << std::endl;
    }

    return 0;
}

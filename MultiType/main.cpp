#include <iostream>
#include <sstream>
#include <chrono>

#include "MultiType.h"

int main(int argc, char **argv) {    

    Node test;
    
    test.setData<double>(10.1);
    
    std::cout << test.getData<double>() << std::endl;

    test.setData<double>(20.2);
    
    std::cout << test.getData<double>() << std::endl;
    
    test.setData<int>(3);
    
    std::cout << test.getData<int>() << std::endl;
    
    return 0;
}

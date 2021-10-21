#include <iostream>
#include <sstream>
#include <chrono>
#include <memory>

#include "TraceAllocator.h"

int main(int argc, char **argv) {    
        
    auto a = std::unique_ptr<TraceAllocator>(new TraceAllocator);
    auto b = new TraceAllocator;
    
    for(auto i : pointer_list) {
        std::cout << "Pointer: " << std::hex << i << std::endl;
    }
    
    delete b;
    
    for(auto i : pointer_list) {
        std::cout << "Pointer: " << std::hex << i << std::endl;
    }
    
    return 0;
}

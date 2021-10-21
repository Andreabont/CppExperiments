#include <iostream>
#include <vector>

#include "PoolAllocator.h"

int main(int argc, char **argv) {    

    PoolAllocator<int, 10> pool;
    
    std::cout << "Test allocate..." << std::endl;
    
    int* i = pool.allocate();    
    int* j = pool.allocate();

    *i = 1;
    *j = 2;
    
    std::cout << "Test dump..." << std::endl;
    pool.dump();
    
    std::cout << "Test deallocate..." << std::endl;
    pool.deallocate(i);
    pool.deallocate(j);
    
    std::cout << "Test bad alloc..." << std::endl;
    
    for(int i = 0; i < 11; i++) {
        pool.allocate();
    }
    
    return 0;
    
}

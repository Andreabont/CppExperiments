#include <iostream>
#include "TopologicalSorting.h"

int main() {
    
    DependencyTree a;
    
    a.insertDependency(1,2);
    a.insertDependency(1,3);
    a.insertDependency(2,4);
    a.insertDependency(3,4);

    for(auto &i : a.getOrder()) {
        std::cout << i << std::endl;
    }
    
}

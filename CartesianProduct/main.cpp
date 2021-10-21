#include <iostream>
#include <cstdint>
#include <vector>
#include <set>
#include "cartesian_product.h"

int main() {

    std::vector<int> a = {1,2,3,4};
    std::set<char> b = {'a','b'};
   
    for(auto i : cartesian_product(a,b)) {
        std::cout << "(" << i.first << ", " << i.second << ")" << std::endl;
    }
    
}

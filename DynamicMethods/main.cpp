#include <iostream>
#include <cstdint>
#include "dynamicMethods.h"

using namespace std;

void* hello (dynamicMethods *thisPtr, std::vector<std::string> param) {
    std::cout << "hello "  << thisPtr << endl;
    std::cout << "hello "  << param[0] << endl;
    return (void*)100;
}

int main() {
    dynamicMethods test;
    test.addMethod("hello", hello);
    auto res = test.callMethod<intptr_t>("hello", {"ciao"});
    cout << "Ritorno: " << res << endl;    
}

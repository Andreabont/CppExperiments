#include <iostream>
#include <sstream>
#include <chrono>

#include "EventManager.h"

int main(int argc, char **argv) {    

    EventManager manager;
    
    manager.eventRegister("mioEvento", [](EventInfo info){
        std::cout << "1 - " << info.eventName << std::endl;
    });
    
    manager.eventRegister("mioEvento", [](EventInfo info){
        std::cout << "2 - " << info.eventName << std::endl;
    });
    
    manager.eventDispatch("mioEvento");

    return 0;
}

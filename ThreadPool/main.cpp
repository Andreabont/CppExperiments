#include <iostream>
#include <sstream>
#include <chrono>

#include "ThreadPool.h"

int main(int argc, char **argv) {    

    ThreadPool test(2);
    
    for(int i = 0; i < 10; i++) {
        test.addJob([i](){
            std::this_thread::sleep_for(std::chrono::seconds(1));
            std::stringstream a;
            a << "[" << std::this_thread::get_id() << "] Eseguo job " << i << std::endl;
            std::cout << a.str();
        });
    }
    
    std::this_thread::sleep_for(std::chrono::seconds(10));

    return 0;
}

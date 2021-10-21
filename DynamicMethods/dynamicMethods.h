#ifndef LIBDYNMET_H
#define LIBDYNMET_H

#include <functional>
#include <map>
#include <list>
#include <string>
#include <vector>

class dynamicMethods {
    
private:
    std::map<std::string, std::function<void*(std::vector<std::string>)>> publicMethods;
    
public:
    void addMethod(std::string name, std::function<void*(dynamicMethods *thisPtr, std::vector<std::string> param)> functionPtr);
    void* callMethod(std::string name, std::vector<std::string> param);
    
    template <typename T>
    T callMethod(std::string name, std::vector< std::string > param) {
        if(this->publicMethods.find(name) == this->publicMethods.end()) {
            throw std::logic_error("Method " + name + " not found");
        }
        return reinterpret_cast<T>(this->publicMethods[name](param));
    }
    
};

#endif //LIBIMPLICANT_H
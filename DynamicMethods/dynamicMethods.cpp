#include <exception>
#include "dynamicMethods.h"

void dynamicMethods::addMethod(std::string name, std::function<void*(dynamicMethods *thisPtr, std::vector<std::string> param)> functionPtr) {
    this->publicMethods[name] = [this, functionPtr](std::vector<std::string> param){return functionPtr(this,param);};
}

void* dynamicMethods::callMethod(std::string name, std::vector< std::string > param) {
    if(this->publicMethods.find(name) == this->publicMethods.end()) {
        throw std::logic_error("Method " + name + " not found");
    }
    return this->publicMethods[name](param);
}


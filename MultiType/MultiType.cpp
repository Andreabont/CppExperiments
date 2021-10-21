#include "MultiType.h"

Node::Node() {
    this->myType = Type::NIL;
}

Node::~Node()
{

}

Type Node::getTypeFromHash(const std::type_info& hash) {
    
    if(hash == typeid(char)) {
        return Type::CHAR;
    } else if(hash == typeid(int)) {
        return Type::INT;
    } else if(hash == typeid(double)) {
        return Type::DOUBLE;
    } else if(hash == typeid(bool)) {
        return Type::BOOL;
    } else if(hash == typeid(std::string)) {
        return Type::STRING;
    } else {
        throw new std::logic_error("Type error");
    }
    
}

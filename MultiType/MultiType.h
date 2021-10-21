#ifndef MULTI_H
#define MULTI_H

#include <string>
#include <stdexcept>
#include <typeinfo>

enum Type { NIL, CHAR, INT, DOUBLE, BOOL, STRING };

class Node {
    
private:
    // TYPE TAG
    Type myType;
    
    // DATA
    union {
        char c;
        int i;
        double d;
        bool b;
    };
    
    Type getTypeFromHash(const std::type_info &hash);
    
public:
    
    Node();
    ~Node();
    
    template<typename TYPE>
    TYPE getData() {
        
        if(this->getTypeFromHash(typeid(TYPE)) != this->myType) {
            throw new std::logic_error("Type error");
        }
        
        switch(this->myType) {
            case Type::CHAR:
                return c;
                break;
            case Type::INT:
                return i;
                break;
            case Type::DOUBLE:
                return d;
                break;
            case Type::BOOL:
                return b;
                break;
            default:
                throw new std::logic_error("Type error");
        }
        
    }
    
    template<typename TYPE>
    void setData(TYPE data) {
        
        if(this->myType != Type::NIL && this->myType != this->getTypeFromHash(typeid(TYPE))) {
            throw new std::logic_error("Type error");
        }
        
        this->myType = this->getTypeFromHash(typeid(TYPE));
        
        switch(this->myType) {
            case Type::CHAR:
                c = data;
                break;
            case Type::INT:
                i = data;
                break;
            case Type::DOUBLE:
                d = data;
                break;
            case Type::BOOL:
                b = data;
                break;
            default:
                throw new std::logic_error("Type error");
        }
        
    }
    
};

#endif // MULTI_H

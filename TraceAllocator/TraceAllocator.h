#ifndef TRACEALLO_H
#define TRACEALLO_H

#include <iterator>
#include <iostream>
#include <list>

class TraceAllocator;

std::list<TraceAllocator*> pointer_list = {};

class TraceAllocator {
    
public:
           
    static void* operator new(std::size_t size) throw(std::bad_alloc) {
        void* pointer = ::operator new(size);
        pointer_list.push_back(static_cast<TraceAllocator*>(pointer));
        std::cout << "Allocati " << size << " byte all'indirizzo " << std::hex << pointer << std::endl;
        return pointer;
    }
    
    static void operator delete(void *pointer) throw() {
        ::operator delete(pointer);
        pointer_list.remove(static_cast<TraceAllocator*>(pointer));
        std::cout << "Deallocato l'indirizzo " << std::hex << pointer << std::endl;
    }
    
};

#endif // TRACEALLO_H

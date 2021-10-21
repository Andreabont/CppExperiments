#ifndef POOL_H
#define POOL_H

#include <assert.h>
#include <iostream>

template <typename T, int DIM>
class PoolAllocator {

private:
    
    template<typename Q>
    union alloc_t {
        Q type;
        alloc_t* next;
    };
    
    alloc_t<T>* _pool = nullptr;
    alloc_t<T>* _head = nullptr;
    
public:
    
    PoolAllocator() {
        
        // Allocate pool
        
        _pool = (alloc_t<T>*) malloc((DIM * sizeof(alloc_t<T>))+1);
        _head = _pool;
        
        // Init free list
                
        for(int i = 0; i < DIM; i++) {
            _pool[i].next = &_pool[i+1];
        }
        
        _pool[DIM].next = nullptr;
        
    }
    
    ~PoolAllocator() {
        free(_pool);
    }
    
    T* allocate() {
        if(_head->next == nullptr) throw std::bad_alloc();
        alloc_t<T>* pointer = _head;
        _head = pointer->next;
        std::cout << "Allocated " << pointer << std::endl;
        return (T*) pointer;
    }
    
    void deallocate(T* p) {
        alloc_t<T>* pointer = (alloc_t<T>*) p;
        pointer->next = _head;
        _head = pointer;
        std::cout << "Deallocated " << p << std::endl;
    }
    
    void dump() {
        for(int i = 0; i < DIM; i++) {
            std::cout << "[" << (T*) &_pool[i] << "] " << (T) _pool[i].type << std::endl;
        }
    }
    
};

#endif // POOL_H

#include "RangeIterator.h"

Range::Range(int a, int b) {

    if(a < b) {
        this->startn = a;
        this->endn = b;
    } else {
        this->startn = b;
        this->endn = a;
    }
    
}


Range::MyIterator Range::begin() {
    return MyIterator(this->startn);
}

Range::MyIterator Range::end() {
    return MyIterator(this->endn);
    
}

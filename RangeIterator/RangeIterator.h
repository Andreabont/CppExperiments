#ifndef RANGEITER_H
#define RANGEITER_H

#include <iterator>

class Range {
    
private:
        int startn, endn;
        
public:
        
    class MyIterator : public std::iterator<std::input_iterator_tag, int> {
        private:
            int n;
        public:
            MyIterator(int x) :n(x) {}
            MyIterator(const MyIterator& mit) : n(mit.n) {}
            MyIterator& operator++() {++n;return *this;}
            MyIterator operator++(int) {MyIterator tmp(*this); operator++(); return tmp;}
            bool operator==(const MyIterator& rhs) {return this->n == rhs.n;}
            bool operator!=(const MyIterator& rhs) {return this->n != rhs.n;}
            int operator*() {return n;}
    }; 
    
    // Metodi Range
    Range(int a, int b = 0);
    MyIterator begin();
    MyIterator end();
    
};

#endif // RANGEITER_H

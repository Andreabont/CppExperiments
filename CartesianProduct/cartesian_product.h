#ifndef LIBCART_H
#define LIBCART_H

#include <utility>

template <typename TYPE_A, typename TYPE_B>
class cartesian_product {

friend class iterator;
   
private:
    TYPE_A *a;
    TYPE_B *b;

public:

    class iterator {
       
    private:
        int count, count_a, count_b;
        typename TYPE_A::iterator iterator_a;
        typename TYPE_B::iterator iterator_b;
        cartesian_product *cp;
       
    public:
       
        /* ITERATOR TRAITS */
        using difference_type = int;
        using value_type = int;
        using pointer = std::pair<typename TYPE_A::value_type, typename TYPE_B::value_type>;
        using reference = std::pair<typename TYPE_A::value_type, typename TYPE_B::value_type>;
        using iterator_category = std::input_iterator_tag;
       
        /* ITERATOR METHODS */
       
        iterator(int count, cartesian_product* cp) : count(count), cp(cp) {
            this->iterator_a = std::begin(*(cp->a));
            this->iterator_b = std::begin(*(cp->b));
            this->count_a = count / (cp->size() / cp->a->size());
            this->count_b = count % cp->b->size();
            for(int i = 0; i < this->count_a; i++) this->iterator_a++;
            for(int i = 0; i < this->count_b; i++) this->iterator_b++;
        }
       
        iterator(const iterator& mit) : iterator(mit.count, mit.cp) {}
       
        iterator& operator++() {
           
            ++count;
            int new_count_a = count / (cp->size() / cp->a->size());
            this->count_b = count % cp->b->size();
           
            if(this->count_a != new_count_a) {
                this->iterator_a++;
                this->count_a = new_count_a;
            }
           
            if(this->count_b == 0) {
                this->iterator_b = std::begin(*(cp->b));
            } else {
                this->iterator_b++;
            }
                       
            return *this;
           
        }
       
        iterator operator++(int) {
            iterator tmp(*this);
            operator++();
            return tmp;
        }
       
        bool operator==(const iterator& rhs) {
            return count == rhs.count;
        }
       
        bool operator!=(const iterator& rhs) {
            return count != rhs.count;
        }
       
       std::pair<typename TYPE_A::value_type, typename TYPE_B::value_type> operator*() {
            return std::make_pair(*(iterator_a), *(iterator_b));
       }
       
    };
   
    cartesian_product(TYPE_A &a, TYPE_B &b) : a(&a) , b(&b) {}

    int size() {
        return a->size() * b->size();
    }
   
    iterator begin() {
        return iterator(0, this);
    }

    iterator end() {
        return iterator(this->size(), this);
    }
   
};

#endif //LIBCART_H

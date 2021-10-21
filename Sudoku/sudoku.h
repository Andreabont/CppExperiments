#ifndef LIBSUDOKU_H
#define LIBSUDOKU_H

#include <array>
#include <iostream>
#include <algorithm>
#include <tuple>

class sudoku {

private:
    
    std::array<std::array<int, 9>, 9> board;
    
public:
    
    class iterate_sudoku : public std::iterator<std::input_iterator_tag, int> {
        
    protected:
        std::array<std::array<int, 9>, 9> &ref;
        int x, y;
        
    public:
        
        iterate_sudoku(std::array<std::array<int, 9>, 9> &ref, int x, int y) : ref(ref), x(x), y(y) {}
        iterate_sudoku(const iterate_sudoku& mit) : ref(mit.ref), x(mit.x), y(mit.y) {}
        iterate_sudoku& operator++() {
            if(x == 8) {
                x = 0;
                ++y;
            } else {
                ++x;
            }
            return *this;
        }
        bool operator==(const iterate_sudoku& rhs) {return x==rhs.x && y==rhs.y;}
        bool operator!=(const iterate_sudoku& rhs) {return x!=rhs.x || y!=rhs.y;}
        int& operator*() {return ref[y][x];}
        
    }; 
    
    iterate_sudoku begin() {return iterate_sudoku(board, 0, 0);}
    iterate_sudoku end() {return iterate_sudoku(board, 0, 9);}
    
    sudoku();
        
    sudoku(const sudoku& ref);

    sudoku(std::initializer_list<std::initializer_list<int>> list);
    
    bool check();
    
    bool is_safe(int x, int y, int candidate);
    
    bool solve();

private:
    
    class iterate_row : public iterate_sudoku {
    public:
        iterate_row(std::array<std::array<int, 9>, 9> &ref, int x, int y) : iterate_sudoku(ref, x, y) {}
        iterate_row& operator++() {++x;return *this;}
        
    }; 
    
    class iterate_column : public iterate_sudoku {
    public:
        iterate_column(std::array<std::array<int, 9>, 9> &ref, int x, int y) : iterate_sudoku(ref, x, y) {}
        iterate_column& operator++() {++y;return *this;}
        
    };
    
    class iterate_subgrid : public iterate_sudoku {
    public:
        iterate_subgrid(std::array<std::array<int, 9>, 9> &ref, int x, int y) : iterate_sudoku(ref, x, y) {}
        iterate_subgrid& operator++() {
            ++x;
            if(x % 3 == 0) {
                x -= 3;
                ++y;
                if(y % 3 == 0) {
                    x = 9;
                    y = 9;
                }
            }
            return *this;
        }        
    };
    
    template <class iterate_sudoku>
    bool check_subset(iterate_sudoku start, iterate_sudoku end, int candidate = 0) {
        
        std::array<bool, 9> count;
        std::fill(std::begin(count), std::end(count), false);
        if(candidate != 0) count[candidate-1] = true;

        for (iterate_sudoku it = start; it != end; ++it) {
            if(*it == 0) continue;
            if(count[(*it)-1]) return false;
            count[(*it)-1] = true;
        }
        
        return true;
        
    }
    
    std::tuple<int, int> get_first_free_cell();
    
};

std::ostream& operator<< (std::ostream& os, sudoku& obj);

#endif //LIBCART_H

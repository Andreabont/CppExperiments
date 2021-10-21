#include <array>
#include "sudoku.h"

sudoku::sudoku() {
    for(int y = 0; y < 9; ++y) {
        for(int x = 0; x < 9; ++x) {
            board[y][x] = 0;
        }
    }    
}

sudoku::sudoku(const sudoku& ref) {
    board = ref.board;
}

sudoku::sudoku(std::initializer_list<std::initializer_list<int>> list) {
    int y = 0;
    for(auto sublist : list) {
        int x = 0;
        for(auto i : sublist) {
            board[y][x] = i;
            ++x;
        }
        for(;x < 9; ++x) {
            board[y][x] = 0;
        }
        ++y;
    }
    for(; y < 9; ++y) {
        for(int x = 0; x < 9; ++x) {
            board[y][x] = 0;
        }
    }  
}


bool sudoku::check() {
    

    // Check row
    for(int i = 0; i < 9; ++i) {
        if(!check_subset(iterate_row(board, 0, i), iterate_row(board, 9, i))) return false;
    }
    
    // Check column
    for(int i = 0; i < 9; ++i) {
        if(!check_subset(iterate_column(board, i, 0), iterate_column(board, i, 9))) return false;
    }
    
    // Check subgrid
    for(int i = 0; i < 9; ++i) {
        if(!check_subset(iterate_subgrid(board, (i%3)*3, (i/3)*3), iterate_subgrid(board, 9, 9))) return false;
    }
    
    return true;
    
}

bool sudoku::is_safe(int x, int y, int candidate)
{
    return check_subset(iterate_row(board, 0, y), iterate_row(board, 9, y), candidate) &&
    check_subset(iterate_column(board, x, 0), iterate_column(board, x, 9), candidate) &&
    check_subset(iterate_subgrid(board, x - x % 3, y - y % 3), iterate_subgrid(board, 9, 9), candidate);
}

std::tuple<int, int> sudoku::get_first_free_cell()
{

    for(int y = 0; y < 9; ++y) {
        for(int x = 0; x < 9; ++x) {
            if(board[y][x] == 0) return {x, y};
        }
    }    
    
    return {9, 9};
    
}


bool sudoku::solve() {

    auto [x, y] = this->get_first_free_cell();
    
    if(x == 9 && y == 9) return true;
    
    for (int candidate = 1; candidate <= 9; candidate++) { 
        if (is_safe(x, y, candidate)) { 
            board[y][x] = candidate; 
            if (solve()) return true; 
            board[y][x] = 0; 
        } 
    } 

    return false; 
    
}

std::ostream& operator<< ( std::ostream& os, sudoku& obj )
{
    int x = 0, y = 0;
    for ( sudoku::iterate_sudoku it = obj.begin(); it != obj.end(); ++it ) {
        if(*it == 0) {
            os << ". ";
        }else {
            os << *it << " ";
        }
        if ( x == 8 ) {
            x = 0;
            ++y;
            if ( y != 9 ) {
                os << std::endl;
                if ( y % 3 == 0 ) {
                    os << std::endl;
                }
            }
        } else {
            ++x;
            if ( x % 3 == 0 ) {
                os << " ";
            }
        }
    }
    return os;
}

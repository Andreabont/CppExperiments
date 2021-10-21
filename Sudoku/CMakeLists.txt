cmake_minimum_required(VERSION 2.6)
project(sudoku)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

add_executable(sudoku main.cpp sudoku.cpp sudoku.h)

install(TARGETS sudoku RUNTIME DESTINATION bin)


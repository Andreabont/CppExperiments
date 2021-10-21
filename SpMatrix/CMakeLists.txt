cmake_minimum_required(VERSION 3.7)
project(rangeiterator)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(spmatrix main.cpp SpMatrix.h)

install(TARGETS spmatrix RUNTIME DESTINATION bin)

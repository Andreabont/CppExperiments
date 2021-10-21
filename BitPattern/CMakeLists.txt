cmake_minimum_required(VERSION 2.6)
project(bitpattern)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

add_executable(bitpattern main.cpp bitpattern.h)

install(TARGETS bitpattern RUNTIME DESTINATION bin)

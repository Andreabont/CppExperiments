cmake_minimum_required(VERSION 2.0)
project(topologicalsorting)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(topsorting main.cpp TopologicalSorting.h TopologicalSorting.cpp)

install(TARGETS topsorting RUNTIME DESTINATION bin)


cmake_minimum_required(VERSION 2.6)
project(cartesianproduct)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

add_executable(cartesianproduct main.cpp cartesian_product.h)

install(TARGETS cartesianproduct RUNTIME DESTINATION bin)

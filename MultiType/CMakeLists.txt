cmake_minimum_required(VERSION 2.6)
project(multitype)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(multitype main.cpp MultiType.cpp MultiType.h)

install(TARGETS multitype RUNTIME DESTINATION bin)

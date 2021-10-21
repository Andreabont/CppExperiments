cmake_minimum_required(VERSION 2.6)
project(rangeiterator)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(traceallocator main.cpp TraceAllocator.h)

install(TARGETS traceallocator RUNTIME DESTINATION bin)

cmake_minimum_required(VERSION 3.1)
project(poolallocator)
set (CMAKE_CXX_STANDARD 17)

add_executable(poolallocator main.cpp PoolAllocator.h)

install(TARGETS poolallocator RUNTIME DESTINATION bin)

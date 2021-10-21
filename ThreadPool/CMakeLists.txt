cmake_minimum_required(VERSION 2.6)
project(threadpool)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(threadpool main.cpp ThreadPool.cpp ThreadPool.h)

find_package (Threads)
target_link_libraries (threadpool ${CMAKE_THREAD_LIBS_INIT})

install(TARGETS threadpool RUNTIME DESTINATION bin)

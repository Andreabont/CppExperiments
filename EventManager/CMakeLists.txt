cmake_minimum_required(VERSION 2.6)
project(eventmanager)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(eventmanager main.cpp EventManager.cpp EventManager.h)

install(TARGETS eventmanager RUNTIME DESTINATION bin)

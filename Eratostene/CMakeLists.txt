cmake_minimum_required(VERSION 2.6)
project(rangeiterator)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(eratostene main.cpp eratostene.cpp eratostene.h)

set(BOOST_LIBS program_options)
find_package(Boost COMPONENTS ${BOOST_LIBS} REQUIRED)

target_link_libraries(eratostene ${Boost_LIBRARIES})


install(TARGETS eratostene RUNTIME DESTINATION bin)

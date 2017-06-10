cmake_minimum_required(VERSION 3.3)
project(AsInfection)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/main.cpp src/grid.cpp )
add_executable(AsInfection ${SOURCE_FILES})
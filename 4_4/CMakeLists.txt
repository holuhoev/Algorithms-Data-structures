cmake_minimum_required(VERSION 3.7)
project(4_4)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES src/main.cpp src/hashset.cpp src/dictionary.cpp)
add_executable(4_4 ${SOURCE_FILES})
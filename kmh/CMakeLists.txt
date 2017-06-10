cmake_minimum_required(VERSION 3.6)
project(kmh)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp kmp.cpp kmp.h)
add_executable(kmh ${SOURCE_FILES})
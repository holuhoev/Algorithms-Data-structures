cmake_minimum_required(VERSION 3.6)
project(DZ_4_1)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp JournalNetActivity.h JournalNetActivity.hpp NetActivity.cpp NetActivity.h TimeStamp.h TimeStamp.cpp SkipList.hpp SkipList.h OrderedList.hpp OrderedList.h)
add_executable(DZ_4_1 ${SOURCE_FILES})
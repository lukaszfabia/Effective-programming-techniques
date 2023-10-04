cmake_minimum_required(VERSION 3.25)
project(Effective_programming_techniques)

set(CMAKE_CXX_STANDARD 98)

add_executable(Effective_programming_techniques
        Lab1/main.cpp Lab1/CTable.cpp
        Lab1/CTable.h
        Lab1/CTableFunctions.cpp
        Lab1/CTableFunctions.h)

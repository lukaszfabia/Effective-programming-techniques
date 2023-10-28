cmake_minimum_required(VERSION 3.25)
project(Effective_programming_techniques)

set(CMAKE_CXX_STANDARD 98)

add_executable(Effective_programming_techniques Lab3/CTree.cpp
        Lab3/CTree.h Lab3/main.cpp Lab3/CInterface.cpp Lab3/CInterface.h Lab3/Tools/CNode.cpp
        Lab3/Tools/CNode.h Lab3/Tools/CPreprocessExpression.cpp Lab3/Tools/CPreprocessExpression.h)

#add_executable(Effective_programming_techniques Lab2/CNumber.h Lab2/CNumber.cpp Lab2/main.cpp Lab2/CTestsForOperators.cpp Lab2/CTestsForOperators.h Lab2/CHelpFunctions.h Lab2/CHelpFunctions.cpp Lab2/CEffectivityTestClass.h Lab2/CEffectivityTestClass.cpp)

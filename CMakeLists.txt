cmake_minimum_required(VERSION 3.25)
project(Effective_programming_techniques)

set(CMAKE_CXX_STANDARD 98)

#add_executable(Effective_programming_techniques Lab3/main.cpp Lab3/utilities/Type.h
#        Lab3/utilities/Operators.h Lab3/utilities/Node.h Lab3/Tree.h Lab3/utilities/Tools.h Lab3/utilities/Tools.cpp
#        Lab3/Tree.cpp Lab3/Interface.h Lab3/Interface.cpp)

#add_executable(Effective_programming_techniques Lab2/CNumber.h Lab2/CNumber.cpp Lab2/main.cpp Lab2/CTestsForOperators.cpp Lab2/CTestsForOperators.h Lab2/CHelpFunctions.h Lab2/CHelpFunctions.cpp Lab2/CEffectivityTestClass.h Lab2/CEffectivityTestClass.cpp)

add_executable(Effective_programming_techniques Lab4/main.cpp Lab4/utilities/Node.h
        Lab4/utilities/Type.h Lab4/utilities/Operators.h Lab4/Tree.h
        Lab4/utilities/Tools.h Lab4/Interface.h)
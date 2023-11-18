cmake_minimum_required(VERSION 3.25)
project(Effective_programming_techniques)

set(CMAKE_CXX_STANDARD 98)

#add_executable(Effective_programming_techniques Lab3/Tree.cpp
#        Lab3/Tree.h Lab3/main.cpp Lab3/CInterface.cpp Lab3/CInterface.h Lab3/Utilities/CNode.cpp
#        Lab3/Utilities/CNode.h Lab3/Utilities/CPreprocessExpression.cpp Lab3/Utilities/CPreprocessExpression.h Lab3/Utilities/CTreesUtility.h Lab3/Utilities/CTreesUtility.cpp Lab3/Utilities/CScan.h Lab3/Utilities/CScan.cpp
#        Lab3/Utilities/CFixExpression.cpp
#        Lab3/Utilities/CFixExpression.h)

#add_executable(Effective_programming_techniques Lab2/CNumber.h Lab2/CNumber.cpp Lab2/main.cpp Lab2/CTestsForOperators.cpp Lab2/CTestsForOperators.h Lab2/CHelpFunctions.h Lab2/CHelpFunctions.cpp Lab2/CEffectivityTestClass.h Lab2/CEffectivityTestClass.cpp)

add_executable(Effective_programming_techniques Lab4/Interface.cpp Lab4/Interface.h Lab4/main.cpp
        Lab4/Tree.h Lab4/tools/Node.h ../Lab3/Utilities/CPreprocessExpression.h ../Lab3/Utilities/CPreprocessExpression.cpp Lab4/tools/Operators.h)
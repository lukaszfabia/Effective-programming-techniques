//
// Created by ufabi on 04.10.2023.
//

#include "CTestsForOperators.h"
#include "CEffectivityTestClass.h"
#include <iostream>

void v_start_test(const char *c_name_of_test) {
    std::cout << "Test for " << c_name_of_test << " started" << std::endl;
    CTestsForOperators *c_tests;
    c_tests = new CTestsForOperators();

    std::cout << "Test for substraction: " << c_tests->b_test_for_substracting() << std::endl;
    std::cout << "Test for adding: " << c_tests->b_test_for_adding() << std::endl;
    std::cout << "Test for multiplication: " << c_tests->b_test_for_multiplication() << std::endl;
    std::cout << "Test for dividing: " << c_tests->b_test_for_dividing() << std::endl;
    delete c_tests;
}

void v_start_effectivity_tests(){
    CEffectivityTestClass *testClass = new CEffectivityTestClass();
    testClass->v_effectivity_test_for_factorial("factoring", 123);
//    testClass->v_effectivity_test_for_multiplying("multiplying", 12312, 999);
//    testClass->v_effectivity_test_for_adding("adding", INT_MAX/1234, 12);
//    testClass->v_effectivity_test_for_substracting("substracting", INT_MAX, INT_MAX);
//    testClass->v_effectivity_test_for_dividing("dividing", 256, INT_MAX-1);
    delete testClass;
}

int main() {
//    v_start_test("Test for lab2 operators");
    v_start_effectivity_tests();


    return 0;
}



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

void v_start_effectivity_tests() {
    CEffectivityTestClass *testClass;
    testClass = new CEffectivityTestClass();
    testClass->v_effectivity_test_for_dividing("dividing", 256, INT_MAX-1);
    testClass->v_effectivity_test_for_substracting("substracting", INT_MAX, INT_MAX);
    testClass->v_effectivity_test_for_factorial("factoring", 140);
    testClass->v_effectivity_test_for_multiplying("multiplying", 100, 10);
    testClass->v_effectivity_test_for_adding("adding", 30000, INT_MAX);
    testClass->v_effectivity_test_for_dividing("dividing", 12213, 123);
    delete testClass;
}

int main() {
    v_start_test("Test for lab2 operators");
    v_start_effectivity_tests();
    CNumber c1 , c2 , c3;
    c1 = 1;
    c2 = 2;
    c3 = c1 + c2;
    c1.v_information();
    c2.v_information();
    c3.v_information();


    return 0;
}
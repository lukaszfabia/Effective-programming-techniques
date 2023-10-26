//
// Created by ufabi on 04.10.2023.
//

#include "CTestsForOperators.h"
#include <iostream>
#include <ctime>

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

void v_effectivity_test(const char *c_name_of_test, const int i_iterations, const int ui_value, const int i_start_sum) {
    std::cout << "Test for " << c_name_of_test << " started" << std::endl;
    std::clock_t start = std::clock();
    CNumber *c_num_0 = new CNumber();
    CNumber *c_res = new CNumber();
    *c_num_0 = ui_value;
    *c_res = i_start_sum;
    for (int i = 0; i < i_iterations; i++) {
        *c_res = *c_res + *c_num_0;
    }

    std::clock_t end = std::clock();
    c_res->v_information();
    delete c_num_0;
    delete c_res;
    std::cout << "Time: " << static_cast<double>(end - start) / static_cast<double> (CLOCKS_PER_SEC / 1000) << " ms"
              << std::endl;
}

int main() {
    v_start_test("Test for lab2 operators");
//    std::cout << INT_MAX << std::endl;
//    v_effectivity_test("effectivity (xD)", 123, 1, 0);
    CNumber c_num_0, c_num_1, c_res;
    c_num_0 = 12;
    c_num_1 = 4;
    c_res = c_num_0 / c_num_1;
    c_res.v_information();
    return 0;
}



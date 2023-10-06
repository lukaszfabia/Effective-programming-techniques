//
// Created by ufabi on 04.10.2023.
//

#include "CTestsForOperators.h"
#include <iostream>

void v_start_test(const char *c_name_of_test) {
    std::cout << "Test for " << c_name_of_test << " started" << std::endl;
    CTestsForOperators *c_tests;
    c_tests = new CTestsForOperators();

    std::cout << "Test for substraction: " << c_tests->b_test_for_substracting() << std::endl;
    std::cout << "Test for bigger func: " << c_tests->b_test_for_is_bigger() << std::endl;
    std::cout << "Test for adding: " << c_tests->b_test_for_adding() << std::endl;
    std::cout << "Test for multiplication: " << c_tests->b_test_for_multiplication() << std::endl;

    delete c_tests;
}

int main() {
    v_start_test("Test for lab2 operators");
//    CNumber c_num_0, c_num_1, c_res;
//    c_num_0 = -123;
//    c_num_1 = 456;
//    c_res = c_num_0 * c_num_1;
//    c_res.v_show_array();
    return 0;
}



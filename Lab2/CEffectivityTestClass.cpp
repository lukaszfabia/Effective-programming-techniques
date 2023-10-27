//
// Created by ufabi on 26.10.2023.
//

#include <iostream>
#include <ctime>
#include "CEffectivityTestClass.h"

CEffectivityTestClass::CEffectivityTestClass() {
    c_res = new CNumber();
    c_num_0 = new CNumber();
    c_num_1 = new CNumber();
}

CEffectivityTestClass::~CEffectivityTestClass() {
    delete c_res;
    delete c_num_0;
    delete c_num_1;
}

void CEffectivityTestClass::v_effectivity_test_for_adding(const char *c_name_of_test, int i_iterations,
                                                          int i_value) {
    std::cout << "Test for " << c_name_of_test << " started" << std::endl;
    std::clock_t start = std::clock();
    *c_num_0 = i_value;
    *c_res = 0;
    for (int i = 0; i < i_iterations; i++) {
        *c_res = *c_res + *c_num_0;
    }

    std::clock_t end = std::clock();
    c_res->v_information();
    std::cout << "Time: " << static_cast<double>(end - start) / static_cast<double> (CLOCKS_PER_SEC / 1000) << " ms"
              << std::endl;
}

void CEffectivityTestClass::v_effectivity_test_for_substracting(const char *c_name_of_test, int i_sub_value,
                                                                int i_value) {
    std::cout << "Test for " << c_name_of_test << " started" << std::endl;
    std::clock_t start = std::clock();
    *c_num_0 = i_value;
    *c_num_1 = i_sub_value;
    *c_res = i_value - i_sub_value;
    std::clock_t end = std::clock();
    c_res->v_information();
    std::cout << "Time: " << static_cast<double>(end - start) / static_cast<double> (CLOCKS_PER_SEC / 1000) << " ms"
              << std::endl;
}

void CEffectivityTestClass::v_effectivity_test_for_dividing(const char *c_name_of_test, int i_divider,
                                                            int i_value) {
    std::cout << "Test for " << c_name_of_test << " started" << std::endl;
    std::clock_t start = std::clock();
    *c_num_0 = i_value;
    *c_num_1 = i_divider;
    if (i_value < i_divider) {
        std::cout << "Attention, you re trying to divide smaller number by bigger" << std::endl;
    }
    *c_res = *c_num_0 / *c_num_1;
    std::clock_t end = std::clock();
    c_res->v_information();
    std::cout << "Time: " << static_cast<double>(end - start) / static_cast<double> (CLOCKS_PER_SEC / 1000) << " ms"
              << std::endl;
}

void CEffectivityTestClass::v_effectivity_test_for_multiplying(const char *c_name_of_test, int i_iterations,
                                                               int i_value) {
    std::cout << "Test for " << c_name_of_test << " started" << std::endl;
    std::clock_t start = std::clock();
    *c_num_0 = i_value;
    *c_res = 1;

    for (int i = 0; i < i_iterations; i++) {
        *c_res = *c_res * *c_num_0;
    }

    std::clock_t end = std::clock();
    c_res->v_information();
    std::cout << "Time: " << static_cast<double>(end - start) / static_cast<double> (CLOCKS_PER_SEC / 1000) << " ms"
              << std::endl;
}

void CEffectivityTestClass::v_effectivity_test_for_factorial(const char *c_name_of_test, int i_value) {
    std::cout << "Test for " << c_name_of_test << " started" << std::endl;
    std::clock_t start = std::clock();
    *c_num_0 = i_value;
    *c_res = !*c_num_0;

    std::clock_t end = std::clock();
    c_res->v_information();
    std::cout << "Time: " << static_cast<double>(end - start) / static_cast<double> (CLOCKS_PER_SEC / 1000) << " ms"
              << std::endl;
}


//
// Created by ufabi on 26.10.2023.
//

#ifndef EFFECTIVE_PROGRAMMING_TECHNIQUES_CEFFECTIVITYTESTCLASS_H
#define EFFECTIVE_PROGRAMMING_TECHNIQUES_CEFFECTIVITYTESTCLASS_H

#include "CNumber.h"

class CEffectivityTestClass {
private:
    CNumber *c_num_0;
    CNumber *c_num_1;
    CNumber *c_res;
public:
    CEffectivityTestClass();

    ~CEffectivityTestClass();

    void v_effectivity_test_for_adding(const char *c_name_of_test, int i_iterations, int i_value);

    void v_effectivity_test_for_substracting(const char *c_name_of_test, int i_sub_value, int i_value);

    void v_effectivity_test_for_dividing(const char *c_name_of_test, int i_divider, int i_value);

    void v_effectivity_test_for_multiplying(const char *c_name_of_test, int i_iterations, int i_value);

    void v_effectivity_test_for_factorial(const char *c_name_of_test, int i_value);

};


#endif //EFFECTIVE_PROGRAMMING_TECHNIQUES_CEFFECTIVITYTESTCLASS_H

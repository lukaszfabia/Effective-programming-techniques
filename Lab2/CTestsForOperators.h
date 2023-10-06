//
// Created by ufabi on 05.10.2023.
//

#ifndef EFFECTIVE_PROGRAMMING_TECHNIQUES_CTESTSFOROPERATORS_H
#define EFFECTIVE_PROGRAMMING_TECHNIQUES_CTESTSFOROPERATORS_H


#include "CNumber.h"

class CTestsForOperators {
public:
    bool b_test_for_substracting();

    bool b_test_for_adding();

    bool b_test_for_is_bigger();

    bool b_test_for_multiplication();

private:
    CNumber c_num_0, c_num_1, c_res;
};


#endif //EFFECTIVE_PROGRAMMING_TECHNIQUES_CTESTSFOROPERATORS_H

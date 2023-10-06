//
// Created by ufabi on 05.10.2023.
//

#include "CTestsForOperators.h"
#include <iostream>

bool CTestsForOperators::b_test_for_substracting() {
    /// when first number is bigger than second
    /// + +
    c_num_0 = 936;
    c_num_1 = 541;
    c_res = c_num_0 - c_num_1;
    bool b_sign_result = !c_res.get_is_negative();
    bool b_value =
            c_res.get_i_numbers()[c_res.get_size() - 1] == 5 && c_res.get_i_numbers()[c_res.get_size() - 2] == 9 &&
            c_res.get_i_numbers()[c_res.get_size() - 3] == 3 && c_res.get_i_numbers()[c_res.get_size() - 4] == 0;

    bool b_result_for_sub_test1 = b_sign_result && b_value;
//    std::cout<<b_result_for_sub_test1<<std::endl;

    /// + -
    c_num_0 = 936;
    c_num_1 = -541;
    c_res = c_num_0 - c_num_1;
    b_sign_result = !c_res.get_is_negative();
    b_value = c_res.get_i_numbers()[c_res.get_size() - 1] == 7 && c_res.get_i_numbers()[c_res.get_size() - 2] == 7 &&
              c_res.get_i_numbers()[c_res.get_size() - 3] == 4 && c_res.get_i_numbers()[c_res.get_size() - 4] == 1 &&
              c_res.get_i_numbers()[c_res.get_size() - 5] == 0;

    bool b_result_for_sub_test2 = b_sign_result && b_value;
//    std::cout<<b_result_for_sub_test2<<std::endl;

    /// - +
    c_num_0 = -936;
    c_num_1 = 541;
    c_res = c_num_0 - c_num_1;
    b_sign_result = c_res.get_is_negative();
    b_value = c_res.get_i_numbers()[c_res.get_size() - 1] == 7 && c_res.get_i_numbers()[c_res.get_size() - 2] == 7 &&
              c_res.get_i_numbers()[c_res.get_size() - 3] == 4 && c_res.get_i_numbers()[c_res.get_size() - 4] == 1 &&
              c_res.get_i_numbers()[c_res.get_size() - 5] == 0;

    bool b_result_for_sub_test3 = b_sign_result && b_value;
//    std::cout<<b_sign_result<<std::endl;

    /// - -
    c_num_0 = -936;
    c_num_1 = -541;
    c_res = c_num_0 - c_num_1;
    b_sign_result = c_res.get_is_negative();

    b_value = c_res.get_i_numbers()[c_res.get_size() - 1] == 5 && c_res.get_i_numbers()[c_res.get_size() - 2] == 9 &&
              c_res.get_i_numbers()[c_res.get_size() - 3] == 3 && c_res.get_i_numbers()[c_res.get_size() - 4] == 0;

    bool b_result_for_sub_test4 = b_sign_result && b_value;
//    std::cout<<b_result_for_sub_test4<<std::endl;

    /// when second number is bigger than first
    /// + +
    c_num_0 = 541;
    c_num_1 = 936;
    c_res = c_num_0 - c_num_1;
    b_sign_result = c_res.get_is_negative();

    b_value = c_res.get_i_numbers()[c_res.get_size() - 1] == 5 && c_res.get_i_numbers()[c_res.get_size() - 2] == 9 &&
              c_res.get_i_numbers()[c_res.get_size() - 3] == 3 && c_res.get_i_numbers()[c_res.get_size() - 4] == 0;

    bool b_result_for_sub_test5 = b_sign_result && b_value;
//    std::cout<<b_result_for_sub_test5<<std::endl;

    /// + -
    c_num_0 = 541;
    c_num_1 = -936;
    c_res = c_num_0 - c_num_1;
    b_sign_result = !c_res.get_is_negative();

    b_value = c_res.get_i_numbers()[c_res.get_size() - 1] == 7 && c_res.get_i_numbers()[c_res.get_size() - 2] == 7 &&
              c_res.get_i_numbers()[c_res.get_size() - 3] == 4 && c_res.get_i_numbers()[c_res.get_size() - 4] == 1 &&
              c_res.get_i_numbers()[c_res.get_size() - 5] == 0;

    bool b_result_for_sub_test6 = b_sign_result && b_value;
//    std::cout<<b_result_for_sub_test6<<std::endl;

    /// - +
    c_num_0 = -541;
    c_num_1 = 936;
    c_res = c_num_0 - c_num_1;
    b_sign_result = c_res.get_is_negative();

    b_value = c_res.get_i_numbers()[c_res.get_size() - 1] == 7 && c_res.get_i_numbers()[c_res.get_size() - 2] == 7 &&
              c_res.get_i_numbers()[c_res.get_size() - 3] == 4 && c_res.get_i_numbers()[c_res.get_size() - 4] == 1 &&
              c_res.get_i_numbers()[c_res.get_size() - 5] == 0;

    bool b_result_for_sub_test7 = b_sign_result && b_value;
//    std::cout<<b_result_for_sub_test7<<std::endl;

    /// - -
    c_num_0 = -541;
    c_num_1 = -936;
    c_res = c_num_0 - c_num_1;
    b_sign_result = !c_res.get_is_negative();

    b_value = c_res.get_i_numbers()[c_res.get_size() - 1] == 5 && c_res.get_i_numbers()[c_res.get_size() - 2] == 9 &&
              c_res.get_i_numbers()[c_res.get_size() - 3] == 3 && c_res.get_i_numbers()[c_res.get_size() - 4] == 0;

    bool b_result_for_sub_test8 = b_sign_result && b_value;
//    std::cout<<b_result_for_sub_test8<<std::endl;

    return b_result_for_sub_test1 && b_result_for_sub_test2 && b_result_for_sub_test3 && b_result_for_sub_test4 &&
           b_result_for_sub_test5 && b_result_for_sub_test6 && b_result_for_sub_test7 && b_result_for_sub_test8;
}

bool CTestsForOperators::b_test_for_adding() {
    /// when both numbers are positive
    c_num_0 = 888;
    c_num_1 = 999;
    c_res = c_num_0 + c_num_1;
    bool b_sign_result = !c_res.get_is_negative();
    bool b_value = c_res.get_i_numbers()[c_res.get_size() - 1] == 7 && c_res.get_i_numbers()[c_res.get_size() - 2] == 8 &&
                   c_res.get_i_numbers()[c_res.get_size() - 3] == 8 && c_res.get_i_numbers()[c_res.get_size() - 4] == 1 && c_res.get_i_numbers()[c_res.get_size() - 5] == 0;

    bool b_result_for_add_test1 = b_sign_result && b_value;
//    std::cout << b_result_for_add_test1 << std::endl;

    /// when first number is bigger then second
    /// + -
    c_num_0 = 123;
    c_num_1 = -456;
    c_res = c_num_0 + c_num_1;
    b_sign_result = c_res.get_is_negative();
    b_value = c_res.get_i_numbers()[c_res.get_size() - 1] == 3 && c_res.get_i_numbers()[c_res.get_size() - 2] == 3 &&
              c_res.get_i_numbers()[c_res.get_size() - 3] == 3 && c_res.get_i_numbers()[c_res.get_size() - 4] == 0;

    bool b_result_for_add_test2 = b_sign_result && b_value;
//    std::cout << b_result_for_add_test2 << std::endl;

    // - +
    c_num_0 = -123;
    c_num_1 = 456;
    c_res = c_num_0 + c_num_1;
    b_sign_result = !c_res.get_is_negative();
    b_value = c_res.get_i_numbers()[c_res.get_size() - 1] == 3 && c_res.get_i_numbers()[c_res.get_size() - 2] == 3 &&
              c_res.get_i_numbers()[c_res.get_size() - 3] == 3 && c_res.get_i_numbers()[c_res.get_size() - 4] == 0;

    bool b_result_for_add_test3 = b_sign_result && b_value;
//    std::cout << b_result_for_add_test3 << std::endl;

    // - -
    c_num_0 = -123;
    c_num_1 = -456;
    c_res = c_num_0 + c_num_1;
    b_sign_result = c_res.get_is_negative();
    b_value = c_res.get_i_numbers()[c_res.get_size() - 1] == 9 && c_res.get_i_numbers()[c_res.get_size() - 2] == 7 &&
              c_res.get_i_numbers()[c_res.get_size() - 3] == 5 && c_res.get_i_numbers()[c_res.get_size() - 4] == 0;

    bool b_result_for_add_test4 = b_sign_result && b_value;
//    std::cout << b_result_for_add_test4 << std::endl;

    /// when second number is bigger then first
    /// + -
    c_num_0 = 456;
    c_num_1 = -123;
    c_res = c_num_0 + c_num_1;
    b_sign_result = !c_res.get_is_negative();
    b_value = c_res.get_i_numbers()[c_res.get_size() - 1] == 3 && c_res.get_i_numbers()[c_res.get_size() - 2] == 3 &&
              c_res.get_i_numbers()[c_res.get_size() - 3] == 3 && c_res.get_i_numbers()[c_res.get_size() - 4] == 0;

    bool b_result_for_add_test5 = b_sign_result && b_value;
//    std::cout << b_result_for_add_test5 << std::endl;

    // - +
    c_num_0 = -456;
    c_num_1 = 123;
    c_res = c_num_0 + c_num_1;
    b_sign_result = c_res.get_is_negative();
    b_value = c_res.get_i_numbers()[c_res.get_size() - 1] == 3 && c_res.get_i_numbers()[c_res.get_size() - 2] == 3 &&
              c_res.get_i_numbers()[c_res.get_size() - 3] == 3 && c_res.get_i_numbers()[c_res.get_size() - 4] == 0;

    bool b_result_for_add_test6 = b_sign_result && b_value;
//    std::cout << b_result_for_add_test6 << std::endl;


    return b_result_for_add_test1 && b_result_for_add_test2 && b_result_for_add_test3 && b_result_for_add_test4 &&
           b_result_for_add_test5 && b_result_for_add_test6;
}

bool CTestsForOperators::b_test_for_is_bigger() {
    c_num_0 = 123;
    c_num_1 = 456;
    bool b_result_for_is_bigger_test1 = !c_num_0.b_is_bigger(c_num_1);

    c_num_0=-123;
    c_num_1=456;
    bool b_result_for_is_bigger_test2 = !c_num_0.b_is_bigger(c_num_1);

    c_num_0=123;
    c_num_1=-456;
    bool b_result_for_is_bigger_test3 = c_num_0.b_is_bigger(c_num_1);

    c_num_0=-123;
    c_num_1=-456;
    bool b_result_for_is_bigger_test4 = c_num_0.b_is_bigger(c_num_1);

    return b_result_for_is_bigger_test1 && b_result_for_is_bigger_test2 && b_result_for_is_bigger_test3 && b_result_for_is_bigger_test4;
}

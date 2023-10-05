//
// Created by ufabi on 04.10.2023.
//

#include <iostream>
#include "CNumber.h"

int main() {
    CNumber c_num_0, c_num_1, c_res;
    c_num_0 = 0;
    c_num_1 = 0;
    c_num_0.v_show_array();
    c_num_1.v_show_array();
    c_res = c_num_1 - c_num_0;
    c_res.v_show_array();

    return 0;
}

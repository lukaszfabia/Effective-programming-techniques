//
// Created by ufabi on 04.10.2023.
//

#include <iostream>
#include "CNumber.h"

int main() {
    CNumber *c_num_0 = new CNumber();
    CNumber *c_num_1 = new CNumber();
    c_num_0->operator=(2131231241);
    c_num_0->operator=(123);
    c_num_0->v_show_array();
    std::cout<<c_num_0->get_size()<<std::endl;
    c_num_1->v_show_array();

    delete c_num_0;
    delete c_num_1;
    return 0;
}

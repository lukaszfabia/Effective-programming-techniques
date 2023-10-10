#include <iostream>
#include "CTableFunctions.h"
#include "CTableTest.h"

//cmake executable code
//add_executable(Effective_programming_techniques
//Lab1/main.cpp Lab1/CTable.cpp
//        Lab1/CTable.h
//        Lab1/CTableFunctions.cpp
//        Lab1/CTableFunctions.h)


void v_test_for_alloc_functions() {
    CTableFunctions::v_alloc_table_fill_34(5);
    CTableFunctions::v_alloc_table_fill_34(0);
    CTableFunctions::v_alloc_table_fill_34(-5);

    int **pi_table;
    std::cout << CTableFunctions::b_alloc_table_2_dim(&pi_table, 5, 5) << std::endl;
    std::cout << CTableFunctions::b_dealloc_table_2_dim(pi_table, 5) << std::endl;
}

void v_set_of_tests_for_CTable() {
    CTableTest::v_test_for_default_constructor();
    std::cout << std::endl;
    CTableTest::v_test_for_parametrized_constructor();
    std::cout << std::endl;
    CTableTest::v_test_for_copy_constructor();
    std::cout << std::endl;
    CTableTest::v_test_for_destructor();
    std::cout << std::endl;
    CTableTest::v_test_for_set_name();
    std::cout << std::endl;
    CTableTest::v_test_for_set_new_size();
    std::cout << std::endl;
    CTableTest::v_test_for_clone();
    std::cout << std::endl;
}

int main() {
    //v_test_for_alloc_functions();
    std::cout << std::endl;
    //v_set_of_tests_for_CTable();
    int **pi_table;
    CTableFunctions::b_alloc_table_2_dim_other_way(&pi_table, 5, 3);

    return 0;
}


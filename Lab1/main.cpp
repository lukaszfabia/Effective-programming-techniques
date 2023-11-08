#include <iostream>
#include <sstream>
#include "CTableFunctions.h"
#include "CTableTest.h"
#include "CTable.h"


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

void v_test_for_array_CTable(int i_size) {
    CTable *pi_CTable = new CTable[i_size];
    std::stringstream ss_my_num;

    for (int i = 0; i < i_size; i++) {
        ss_my_num.str("");  // Wyczyść strumień
        ss_my_num << "CTable" << "_" << i + 1;
        pi_CTable[i] = *new CTable(ss_my_num.str(), i + 1);
    }

    std::cout << std::endl;
    for (int i = 0; i < i_size; i++) {
        (pi_CTable + i)->vShow();
    }

    delete[] pi_CTable;
}

int main() {
    v_test_for_alloc_functions();
    std::cout << std::endl;
   v_set_of_tests_for_CTable();
    int **pi_table;
    CTableFunctions::b_alloc_table_2_dim_other_way(&pi_table, 5, 3);
    CTableFunctions::b_dealloc_table_2_dim_other_way(pi_table, 5);


//    v_test_for_array_CTable(5);
    return 0;
}


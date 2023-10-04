#include <iostream>
#include "CTableFunctions.h"
#include "CTable.h"

//cmake executable code
//add_executable(Effective_programming_techniques
//Lab1/main.cpp Lab1/CTable.cpp
//        Lab1/CTable.h
//        Lab1/CTableFunctions.cpp
//        Lab1/CTableFunctions.h)


void ex1(){
    CTableFunctions::v_alloc_table_fill_34(5);
    int **pi_table;
    std::cout<<CTableFunctions::b_alloc_table_2_dim(&pi_table, 5, 5)<<std::endl;
    std::cout<<CTableFunctions::b_dealloc_table_2_dim(pi_table, 5)<<std::endl;

    delete pi_table;
}

void ex2(){
    CTable *pcTab = new CTable();
    pcTab->vSetName("Dynamic object");
    v_mod_tab(pcTab, 20);
    std::cout<<"In main: "<<pcTab->getTableLength()<<std::endl;
    delete pcTab;


//    creating static object
//    CTable tab;
//    v_mod_tab(tab, 20);
//    std::cout<<"In main: "<<tab.getTableLength()<<std::endl;
}

int main()
{
    ex2();
    return 0;
}


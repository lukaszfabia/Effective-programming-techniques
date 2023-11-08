//
// Created by ufabi on 04.10.2023.
//

#include "CTable.h"
#include <iostream>

CTable::CTable() {
    std::cout << "bezp: '" << DEFAULT_NAME << "'" << std::endl;
    s_name = DEFAULT_NAME;
    i_table_length = DEFAULT_LENGTH;
    pi_table = new int[i_table_length];
}

CTable::CTable(std::string sName, int iTableLen) {
    s_name = sName;
    i_table_length = iTableLen;
    pi_table = new int[i_table_length];
    std::cout << "parametr: '" << s_name << "'" << std::endl;
}

CTable::CTable(CTable &pcOther) {
    s_name = pcOther.s_name + "_copy";
    i_table_length = pcOther.i_table_length;
    pi_table = new int[i_table_length];
    for (int i = 0; i < i_table_length; i++) {
        pi_table[i] = pcOther.pi_table[i];
    }
    std::cout << "kopiuj: '" << s_name << "'" << std::endl;
}

CTable::~CTable() {
    delete[]pi_table;
    std::cout << "usuwam: '" << s_name << "'" << std::endl;
}

void CTable::vSetName(std::string sName) {
    s_name = sName;
}

bool CTable::bSetNewSize(int iTableLen) {
    if (iTableLen > 0) {
        int *pi_new_table = new int[iTableLen];
        delete[]pi_table;
        pi_table = pi_new_table;
        i_table_length = iTableLen;
        return true;
    } else {
        return false;
    }
}

CTable *CTable::pcClone() {
    return new CTable(*this);
}

void CTable::vShow() {
    std::cout << "Name: " << s_name << std::endl;
    std::cout << "Length: " << i_table_length << std::endl;
    std::cout << std::endl;
}

void v_mod_tab(CTable *pcTab, int iNewSize) {
    pcTab->bSetNewSize(iNewSize);
}

void v_mod_tab(CTable cTab, int iNewSize) {
    cTab.bSetNewSize(iNewSize);
}

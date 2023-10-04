//
// Created by ufabi on 04.10.2023.
//

#ifndef TEP_CTABLE_H
#define TEP_CTABLE_H


#include <string>

class CTable {
public:
    CTable();
    CTable (std::string sName, int iTableLen);
    CTable (CTable &pcOther);
    ~CTable();

    void vSetName(std::string sName);
    bool bSetNewSize(int iTableLen);
    CTable *pcClone();
    int getTableLength() const { return i_table_length; }
private:
    std::string s_name;
    int *pi_table;
    int i_table_length;
};

void v_mod_tab(CTable *pcTab, int iNewSize);
void v_mod_tab(CTable cTab, int iNewSize);

#endif //TEP_CTABLE_H

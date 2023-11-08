//
// Created by ufabi on 04.10.2023.
//

#include "CTableTest.h"
#include "CTable.h"
#include <iostream>

void CTableTest::v_test_for_default_constructor() {
    CTable *pcTab = new CTable();
    v_mod_tab(pcTab, 20);
    delete pcTab;

    std::cout<<"----------------------------\n";

    CTable tab;
    v_mod_tab(tab, 20);
}

void CTableTest::v_test_for_parametrized_constructor() {
    CTable *pcTab = new CTable("Dynamic object", 10);
    v_mod_tab(pcTab, 20);
    delete pcTab;

    std::cout<<"----------------------------\n";

    CTable tab("Static object", 10);
    v_mod_tab(tab, 20);
}

void CTableTest::v_test_for_copy_constructor() {
    CTable *pcTab = new CTable("Dynamic object", 10);
    CTable *pcTab2 = new CTable(*pcTab);
    v_mod_tab(pcTab2, 20);
    delete pcTab;
    delete pcTab2;

    std::cout<<"----------------------------\n";

    CTable tab("Static object", 10);
    CTable tab2(tab);
    v_mod_tab(tab2, 20);
}

void CTableTest::v_test_for_destructor() {
    CTable *pcTab = new CTable("Dynamic object", 10);
    delete pcTab;

    std::cout<<"----------------------------\n";

    CTable tab("Static object", 10);
}

void CTableTest::v_test_for_set_name() {
    CTable *pcTab = new CTable("Dynamic object", 10);
    pcTab->vSetName("My dynamic object");
    delete pcTab;

    std::cout<<"----------------------------\n";

    CTable tab("Static object", 10);
    tab.vSetName("My static object");
}

void CTableTest::v_test_for_set_new_size() {
    CTable *pcTab = new CTable("Dynamic object", 10);
    pcTab->bSetNewSize(20);
    delete pcTab;

    std::cout<<"----------------------------\n";

    CTable tab("Static object", 10);
    tab.bSetNewSize(20);
}

void CTableTest::v_test_for_clone() {
    CTable *pcTab = new CTable("Dynamic object", 10);
    CTable *cloneTab = pcTab->pcClone();
    cloneTab->vSetName("Clone of dynamic object");

    std::cout << "----------------------------\n";

    CTable tab("Static object", 10);
    CTable *cloneTab2 = tab.pcClone();
    cloneTab2->vSetName("Clone of static object");
    delete pcTab;
    delete cloneTab;
    delete cloneTab2;
}


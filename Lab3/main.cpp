//
// Created by ufabi on 20.10.2023.
//
#include <iostream>
#include "Tools/CPreprocessExpression.h"
#include "CTree.h"

int main() {
    CPreprocessExpression *ex = new CPreprocessExpression("+ * a x * + c");
    CTree *tree = new CTree(ex);
    tree->buildTree();
    std::cout<<tree->printVars()<<std::endl;
    std::cout<<tree->print()<<std::endl;
    delete tree;
    delete ex;
    return 0;
}
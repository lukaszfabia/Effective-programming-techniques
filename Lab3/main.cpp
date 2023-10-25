//
// Created by ufabi on 20.10.2023.
//
#include <iostream>
#include "Tools/CPreprocessExpression.h"
#include "CTree.h"

int main() {
    CPreprocessExpression *ex = new CPreprocessExpression("+ * 5 sin x * + a b 8");
    CTree *tree = new CTree(ex);
    tree->buildTree();
//    std::cout << tree->printVars() << std::endl;
    delete ex;
    delete tree;
    return 0;
}
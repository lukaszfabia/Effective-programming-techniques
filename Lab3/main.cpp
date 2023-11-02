//
// Created by ufabi on 20.10.2023.
//
#include <iostream>
#include "Utilities/CPreprocessExpression.h"
#include "CTree.h"
#include "Utilities/CScan.h"
#include "CInterface.h"

int main() {
//    CPreprocessExpression *expression = new CPreprocessExpression("+ +");
//    CPreprocessExpression *expression1 = new CPreprocessExpression("- a");
//    CTree *tree = new CTree(expression->getElements());
//    CTree *tree1 = new CTree(expression1->getElements());
//    CTree *tree2 = new CTree();
//    tree->buildTree();
//    tree1->buildTree();
//
//    *tree = *tree + *tree1;
//    std::cout << tree->printNormalExpression() << std::endl;
//
    CInterface interface;
    interface.run();
    return 0;
}

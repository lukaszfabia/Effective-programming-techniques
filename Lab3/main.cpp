//
// Created by ufabi on 20.10.2023.
//
#include <iostream>
#include "Utilities/CPreprocessExpression.h"
#include "CTree.h"
#include "Utilities/CScan.h"
#include "CInterface.h"

int main() {
//    CTree tree(new CPreprocessExpression("+ * a x * - c"));
//    CTree tree1(new CPreprocessExpression("+ a b"));
//    CTree tree2;
//    tree2 = tree + tree1;
//    std::cout << tree2.printNormalExpression() << std::endl;

    CInterface interface;
    interface.run();
    return 0;
}

/*
 + a b

 */
//
// Created by ufabi on 20.10.2023.
//
#include <iostream>
#include "Utilities/CPreprocessExpression.h"
#include "CTree.h"
#include "Utilities/CScan.h"
#include "CInterface.h"

int main() {
    CTree tree(new CPreprocessExpression("- + - 12"));
    std::cout << tree.printNormalExpression() << std::endl;

//    CInterface interface;
//    interface.run();
    return 0;
}

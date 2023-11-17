//
// Created by ufabi on 20.10.2023.
//
#include "CInterface.h"
#include "Utilities/CPreprocessExpression.h"

int main() {
    CInterface *interface = new CInterface();
    interface->run();
    delete interface;
    return 0;
}
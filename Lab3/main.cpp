//
// Created by ufabi on 20.10.2023.
//
#include "CInterface.h"

int main() {
    CInterface *interface = new CInterface();
    interface->run();
    delete interface;
    return 0;
}
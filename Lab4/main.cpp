#ifdef _WIN32
#define CLEAR system("cls")
#else
#define CLEAR system("clear")
#endif


#include <iostream>
#include <vector>
#include "Tools.h"
#include "Tree.h"
#include "Interface.h"

enum VariableType {
    INT = '1',
    DOUBLE = '2',
    STRING = '3'
};

void run() {
    std::string choice;
    std::cout << "1. int\n"
                 "2. double\n"
                 "3. string\n" "Choose type of variables:";

    std::getline(std::cin, choice);
    std::cout << choice[0] << std::endl;
    CLEAR;
    switch (choice[0]) {
        case INT: {
            Interface<int> interface;
            interface.run();
            break;
        }
        case DOUBLE: {
            Interface<double> interface;
            interface.run();
            break;
        }
        case STRING: {
            Interface<std::string> interface;
            interface.run();
            break;
        }
        default: {
            std::cout << "Wrong choice!\n";
            break;
        }
    }
}


int main() {
    run();
    return 0;
}

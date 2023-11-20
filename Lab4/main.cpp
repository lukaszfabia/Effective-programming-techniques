#ifdef _WIN32
#define CLEAR system("cls")
#else
#define CLEAR system("clear")
#endif
#define MENU "1. int\n"\
            "2. double\n"\
            "3. string\n" \
            "Choose type of variables: ";
#define WRONG "Wrong choice!\n"

#include <iostream>
#include "Interface.h"

enum VariableType {
    INT = '1',
    DOUBLE = '2',
    STRING = '3'
};

void run() {
    std::string choice;
    std::cout << MENU;

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
            std::cout << WRONG;
        }
    }
}


int main() {
    run();
    return 0;
}

#include <iostream>
#include "Interface.h"
#include "MySmartPointer.h"

#ifdef _WIN32
#define CLEAR system("cls")
#else
#define CLEAR system("clear")
#endif
#define MENU "1. int\n"\
            "2. double\n"\
            "3. string\n" \
            "Choose type of variables: "
#define WRONG "Wrong choice! type 'y' to exit\n"

enum VariableType {
    INT = '1',
    DOUBLE = '2',
    STRING = '3'
};

void run() {
    bool isOnExit = false;
    std::string choice;
    while (!isOnExit){
        std::cout << MENU;

        std::getline(std::cin, choice);
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
            case 'y': {
                isOnExit = true;
                break;
            }
            default: {
                std::cout << WRONG;
                break;
            }
        }
    }
}


int main() {
//    run();
    MySmartPointer<int> a(5);
    std::cout<<*a<<std::endl;
    return 0;
}

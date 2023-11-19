//
// Created by ufabi on 19.11.2023.
//

#ifndef TEMPLATES_INTERFACE_H
#define CMD "tree>"
#define HELP  "Commands:\n"\
             "enter <expression> - enter expression\n"\
             "join <expression> - join expression\n"\
             "comp <expression> - compute expression\n"\
             "print - print expression\n"\
             "vars - print variables\n"\
             "norm - normalize expression\n"\
             "help - print help\n"\
             "exit - exit\n"
#define TEMPLATES_INTERFACE_H
#define UNKNOWN "unknown command"

#include <iostream>
#include <string>
#include <vector>
#include "Tree.h"
#include "FixExpression.h"

template<class T>
class Interface {
private:
    Tree<T> *tree;
    Tree<T> *subtree;

    bool menu(const std::string &lane);

    void enter(const std::string &lane);

    void join(const std::string &lane);

    void comp(const std::string &lane);

    void print();

    void info();

    void vars();

    void norm();

    void unknownCommand();

public:
    void run();
};

template<class T>
bool Interface<T>::menu(const std::string &lane) {
    if (lane.substr(0, 4) == "exit") {
        return true;
    } else if (lane.substr(0, 5) == "enter") {
        enter(lane);
    } else if (lane.substr(0, 4) == "join") {
        join(lane);
    } else if (lane.substr(0, 4) == "comp" || lane.substr(0, 4) == "calc") {
        comp(lane);
    } else if (lane.substr(0, 5) == "print") {
        print();
    } else if (lane.substr(0, 4) == "info" || lane.substr(0, 4) == "help") {
        info();
    } else if (lane.substr(0, 4) == "vars") {
        vars();
    } else if (lane.substr(0, 4) == "norm") {
        norm();
    } else {
        unknownCommand();
    }
    return false;
}

template<class T>
void Interface<T>::enter(const std::string &lane) {
    tree = new Tree<T>(FixExpression<T>::fix(Tools<T>::createVector(lane.substr(5))));
    std::cout << "expression was interpreted as: " << tree->print() << std::endl;
}

template<class T>
void Interface<T>::join(const std::string &lane) {
    subtree = new Tree<T>(FixExpression<T>::fix(Tools<T>::createVector(lane.substr(4))));
    *tree = *tree + *subtree;
    std::cout << "expression was interpreted as: " << tree->print() << std::endl;
}

template<class T>
void Interface<T>::comp(const std::string &lane) {
    std::string tmp = lane.substr(4);
    std::stringstream ss;
    int amountOfVars = Tools<T>::getAmountOfVariables(tree->vars());

    if (tmp.empty() && amountOfVars != 0) {
        std::cout << "amount of variables and res is not equal\n";
    } else if (amountOfVars == 0) {
        ss << tree->comp();
        std::cout << "result: " + ss.str() << std::endl;
    } else if (amountOfVars == Tools<T>::getAmountOfValues(lane.substr(5)) && !tmp.empty()) {
        tree->setMap(
                Tools<T>::createMap(lane.substr(5), tree->vars()));
        ss << tree->comp();
        std::cout << "result: " + ss.str() << std::endl;
    } else {
        std::cout << "too many or too little args\n";
    }
}

template<class T>
void Interface<T>::print() {
    std::cout << "prefix expression: " << tree->print() << std::endl;
}

template<class T>
void Interface<T>::info() {
    std::cout << HELP << std::endl;
}

template<class T>
void Interface<T>::vars() {
    std::cout << "vars: " + tree->vars() << std::endl;
}

template<class T>
void Interface<T>::norm() {
    std::cout << "normal expression: " << tree->norm() << std::endl;
}

template<class T>
void Interface<T>::unknownCommand() {
    std::cout << UNKNOWN << std::endl;
}

template<class T>
void Interface<T>::run() {
    bool isExit = false;
    while (!isExit) {
        std::string lane;
        std::cout << CMD;
        std::getline(std::cin, lane);
        isExit = menu(lane);
    }
}

#endif //TEMPLATES_INTERFACE_H

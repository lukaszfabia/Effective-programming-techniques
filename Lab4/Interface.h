//
// Created by ufabi on 19.11.2023.
//

#ifndef TEMPLATES_INTERFACE_H
#define CMD "tree>"
#define HELP  std::cout<<"Commands:\n"\
             "enter <expression> - enter expression\n"\
             "join <expression> - join expression\n"\
             "comp <expression> - compute expression\n"\
             "print - print expression\n"\
             "vars - print variables\n"\
             "norm - normalize expression\n"\
             "help - print help\n"\
             "exit - exit\n"<<std::endl


#define INTERPRETED(expression) std::cout << "expression was interpreted" << expression << std::endl
#define WRONG_AMOUNT_OF_ARGS std::cout << "wrong amount of args" << std::endl
#define RESULT_(str) std::cout << "result: " << str << std::endl
#define TEMPLATES_INTERFACE_H
#define PREFIX(str) std::cout << "prefix expression: " << str << std::endl
#define NORMAL(str) std::cout << "normal expression: " << str << std::endl
#define VARS(str) std::cout<< "vars: " << str << std::endl
#define UNKNOWN std::cout << "unknown command" << std::endl

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
        PREFIX(tree->print());
    } else if (lane.substr(0, 4) == "info" || lane.substr(0, 4) == "help") {
        HELP;
    } else if (lane.substr(0, 4) == "vars") {
        VARS(tree->vars());
    } else if (lane.substr(0, 4) == "norm") {
        NORMAL(tree->norm());
    } else {
        UNKNOWN;
    }
    return false;
}

template<class T>
void Interface<T>::enter(const std::string &lane) {
    tree = new Tree<T>(FixExpression<T>::fix(Tools<T>::createVector(lane.substr(5))));
    INTERPRETED(tree->print());
}

template<class T>
void Interface<T>::join(const std::string &lane) {
    subtree = new Tree<T>(FixExpression<T>::fix(Tools<T>::createVector(lane.substr(4))));
    *tree = *tree + *subtree;
    INTERPRETED(tree->print());
}

template<class T>
void Interface<T>::comp(const std::string &lane) {
    std::string tmp = lane.substr(4);
    std::stringstream ss;
    int amountOfVars = Tools<T>::getAmountOfVariables(tree->vars());

    if (tmp.empty() && amountOfVars != ZERO) {
        WRONG_AMOUNT_OF_ARGS;
    } else if (amountOfVars == ZERO) {
        ss << tree->comp();
        RESULT_(ss.str());
    } else if (amountOfVars == Tools<T>::getAmountOfValues(lane.substr(5)) && !tmp.empty()) {
        tree->setMap(
                Tools<T>::createMap(lane.substr(5), tree->vars()));
        ss << tree->comp();
        RESULT_(ss.str());
    } else {
        WRONG_AMOUNT_OF_ARGS;
    }
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

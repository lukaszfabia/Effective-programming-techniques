//
// Created by ufabi on 21.11.2023.
//

#ifndef TREE_INTERFACE_H

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


#define INTERPRETED(expression) std::cout << "expression was interpreted: " << expression << std::endl
#define WRONG_AMOUNT_OF_ARGS std::cout << "wrong amount of args" << std::endl
#define RESULT_(str) std::cout << "result: " << str << std::endl
#define PREFIX(str) std::cout << "prefix expression: " << str << std::endl
#define NORMAL(str) std::cout << "normal expression: " << str << std::endl
#define VARS(str) std::cout<< "vars: " << str << std::endl
#define UNKNOWN std::cout << "unknown command" << std::endl
#define IS_ON_EXIT(lane) lane.substr(0, 4) == "exit"
#define IS_COMP(lane) lane.substr(0, 4) == "comp" || lane.substr(0, 4) == "calc"
#define IS_ENTER(lane) lane.substr(0, 5) == "enter"
#define IS_PRINT(lane) lane.substr(0, 5) == "print"
#define IS_NORM(lane) lane.substr(0, 4) == "norm"
#define IS_VARS(lane) lane.substr(0, 4) == "vars"
#define IS_JOIN(lane) lane.substr(0, 4) == "join"
#define IS_HELP(lane) lane.substr(0, 4) == "help" || lane.substr(0, 4) == "info"

#define TREE_INTERFACE_H

#include <iostream>
#include <string>
#include <vector>
#include "Tree.h"
#include "utilities/FixExpression.h"

class Interface {
private:
    Tree *tree;
    Tree *subtree;

    bool menu(const std::string &lane);

    void enter(const std::string &lane);

    void join(const std::string &lane);

    void comp(const std::string &lane);

public:
    Interface() : tree(NULL), subtree(NULL) {};

    ~Interface() {
        delete tree;
        delete subtree;
    }

    void run();
};


#endif //TREE_INTERFACE_H

//
// Created by ufabi on 20.10.2023.
//

#ifndef EFFECTIVE_PROGRAMMING_TECHNIQUES_CINTERFACE_H
#define EFFECTIVE_PROGRAMMING_TECHNIQUES_CINTERFACE_H
#define CMD_LANE "ctree>"
#define HELP "Commands:\n"\
             "enter <expression> - enter expression\n"\
             "join <expression> - join expression\n"\
             "comp <expression> - compute expression\n"\
             "print - print expression\n"\
             "vars - print variables\n"\
             "norm - normalize expression\n"\
             "help - print help\n"\
             "exit - exit\n"


#include "Utilities/CScan.h"
#include "CTree.h"

class CInterface {
private:
    CScan *scan;
    CTree *tree;
    CTree *subTree;

    void enter(const std::string &lane);

    void join(const std::string &lane);

    void comp(const std::string &lane);

    void print();

    static void info();

    void vars();

    bool menu(const std::string &lane);

    static void unknownCommand();

    void norm();

public:
    CInterface();

    ~CInterface();

    void run();
};

#endif //EFFECTIVE_PROGRAMMING_TECHNIQUES_CINTERFACE_H

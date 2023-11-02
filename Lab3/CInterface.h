//
// Created by ufabi on 20.10.2023.
//

#ifndef EFFECTIVE_PROGRAMMING_TECHNIQUES_CINTERFACE_H
#define EFFECTIVE_PROGRAMMING_TECHNIQUES_CINTERFACE_H


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

public:
    CInterface();

    ~CInterface();

    void run();

    void norm();
};

static const char *CMD_LANE = "ctree>";

#endif //EFFECTIVE_PROGRAMMING_TECHNIQUES_CINTERFACE_H

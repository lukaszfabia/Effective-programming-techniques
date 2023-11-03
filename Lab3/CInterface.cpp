//
// Created by ufabi on 20.10.2023.
//

#include <iostream>
#include "CInterface.h"
#include "Utilities/CFixExpression.h"

CInterface::CInterface() {
    scan = new CScan();
    tree = new CTree();
    subTree = new CTree();
}

CInterface::~CInterface() {
    delete scan;
    delete tree;
    delete subTree;
}

void CInterface::run() {
    bool isExit = false;
    while (!isExit) {
        CScan::printPrompt(CMD_LANE);
        scan->readLane();
        isExit = menu(CPreprocessExpression::removeInvalidVars(CPreprocessExpression::toLowerCase(scan->getLane())));
    }
}

bool CInterface::menu(const std::string &lane) {
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

void CInterface::enter(const std::string &lane) {
    CPreprocessExpression *expression = new CFixExpression(lane.substr(5));
    expression->fixExpression();
    CScan::printResult("expression was interpreted as: " + expression->getExpression());
    tree->setElements(expression->getElements());
    delete expression;
}

void CInterface::join(const std::string &lane) {
    CPreprocessExpression *expression = new CFixExpression(lane.substr(4));
    expression->fixExpression();
    CScan::printResult("expression was interpreted as: " + expression->getExpression());
    subTree->setElements(expression->getElements());
    *tree = *tree + *subTree;
    delete expression;
}

void CInterface::comp(const std::string &lane) {
    std::string tmp = lane.substr(4);
    int amountOfVars = CPreprocessExpression::getAmountOfVariables(
            CPreprocessExpression::removeDuplicates(tree->printVars()));

    if (tmp.empty() && amountOfVars != 0) {
        CScan::printPrompt("amount of variables and values is not equal\n");
    } else if (amountOfVars == 0) {
        CScan::printResult("result: " + std::to_string(tree->calculate()));
    } else if (amountOfVars == CPreprocessExpression::getAmountOfValues(lane.substr(5)) && !tmp.empty()) {
        tree->setValues(
                CPreprocessExpression::createMap(lane.substr(5),
                                                 CPreprocessExpression::removeDuplicates(tree->printVars())));
        CScan::printResult("result: " + std::to_string(tree->calculate()));
    } else {
        CScan::printPrompt("too many or too little args\n");
    }
}

void CInterface::print() {
    CScan::printResult("prefix expression: " + tree->print());
}

void CInterface::info() {
    CScan::printPrompt("available commands: enter, join, comp, norm, vars, print, info, exit\n");
}

void CInterface::vars() {
    CScan::printResult("vars: " + CPreprocessExpression::removeDuplicates(tree->printVars()));
}

void CInterface::norm() {
    CScan::printResult("normal expression: " + tree->printNormalExpression());
}

void CInterface::unknownCommand() {
    CScan::printPrompt("unknown command\n");
}
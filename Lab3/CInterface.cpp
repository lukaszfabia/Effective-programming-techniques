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
    if (lane.find("exit") != std::string::npos) {
        return true;
    } else if (lane.substr(0, 5) == "enter") {
        enter(lane);
    } else if (lane.find("join") != std::string::npos) {
        join(lane);
    } else if (lane.find("comp") != std::string::npos) {
        comp(lane);
    } else if (lane.find("print") != std::string::npos) {
        print();
    } else if (lane.find("info") != std::string::npos) {
        info();
    } else if (lane.find("vars") != std::string::npos) {
        vars();
    } else if (lane.find("norm") != std::string::npos) {
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
    int amountOfVars = CPreprocessExpression::getAmountOfVariables(
            CPreprocessExpression::removeDuplicates(tree->printVars()));

    if (amountOfVars == 0) {
        CScan::printResult("result: " + std::to_string(tree->calculate()));
    } else if (amountOfVars == CPreprocessExpression::getAmountOfValues(lane.substr(5))) {
        tree->setValues(
                CPreprocessExpression::createMap(lane.substr(5),
                                                 CPreprocessExpression::removeDuplicates(tree->printVars())));
        CScan::printResult("result: " + std::to_string(tree->calculate()));
    } else {
        CScan::printPrompt("amount of variables and values is not equal\n");
    }
}

void CInterface::print() {
    CScan::printResult("prefix expression: " + tree->print());
}

void CInterface::info() {
    CScan::printPrompt("available commands: enter, join, comp, vars, print, info, exit\n");
}

void CInterface::vars() {
    CScan::printResult("vars: " + CPreprocessExpression::removeDuplicates(tree->printVars()));
}

void CInterface::norm() {
    CScan::printResult("normal expression: " + tree->printNormalExpression());
}

void CInterface::unknownCommand() {
    CScan::printPrompt("Unknown command\n");
}
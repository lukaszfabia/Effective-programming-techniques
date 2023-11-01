//
// Created by ufabi on 20.10.2023.
//

#include "CInterface.h"

CInterface::CInterface() {
    scan = new CScan();
    tree = new CTree();
    resultTree = new CTree();
    subTree = new CTree();
}

CInterface::~CInterface() {
    delete scan;
    delete tree;
    delete resultTree;
    delete subTree;
}

void CInterface::run() {
    bool isExit = false;
    while (!isExit) {
        CScan::printPrompt("ctree>");
        scan->readLane();
        isExit = menu(scan->getLane());
    }
}

bool CInterface::menu(const std::string &lane) {
    if (lane.find("exit") != std::string::npos) {
        return true;
    } else if (lane.find("enter") != std::string::npos) {
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
    } else {
        unknownCommand();
    }
    return false;
}

void CInterface::enter(const std::string &lane) {
    CPreprocessExpression *expression = new CPreprocessExpression(lane.substr(6));
    CScan::printResult("expression was interpreted as: " + expression->getExpression());
    tree->setPreprocessExpression(expression);
}

void CInterface::join(const std::string &lane) {
    subTree->setPreprocessExpression(new CPreprocessExpression(lane.substr(5)));
    *resultTree = *tree + *subTree;
}

void CInterface::comp(const std::string &lane) {
//    std::string var = lane.substr(5);
//    if (tree->addValue(std::stoi(var))) {
//        CScan::printPrompt("value " + var + " was added\n");
//    } else {
//        CScan::printPrompt("value " + var + " was not added\n");
//    }
    CScan::printPrompt("result: ");
    CScan::printResult(std::to_string(tree->calculate()));
}

void CInterface::print() {
    CScan::printPrompt("result: ");
    CScan::printResult(tree->print());
    amountOfVariables = 0;
}

void CInterface::info() {
    CScan::printPrompt("available commands: enter, join, comp, vars, print, info, exit\n");
}

void CInterface::vars() {
    CScan::printPrompt("vars: ");
    CScan::printResult(CPreprocessExpression::removeDuplicates(tree->printVars()));
}

void CInterface::unknownCommand() {
    CScan::printPrompt("Unknown command\n");
}
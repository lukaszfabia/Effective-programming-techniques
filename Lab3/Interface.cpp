//
// Created by ufabi on 21.11.2023.
//

#include "Interface.h"

bool Interface::menu(const std::string &lane) {
    if (IS_ON_EXIT(lane)) {
        return true;
    } else if (IS_ENTER(lane)) {
        enter(lane);
    } else if (IS_JOIN(lane)) {
        join(lane);
    } else if (IS_COMP(lane)) {
        comp(lane);
    } else if (IS_PRINT(lane)) {
        PREFIX(tree->print());
    } else if (IS_HELP(lane)) {
        HELP;
    } else if (IS_VARS(lane)) {
        VARS(tree->vars());
    } else if (IS_NORM(lane)) {
        NORMAL(tree->norm());
    } else {
        UNKNOWN;
    }
    return false;
}

void Interface::enter(const std::string &lane) {
    tree = new Tree(Tools::createVector(lane.substr(5)));
    INTERPRETED(tree->print());
}

void Interface::join(const std::string &lane) {
    subtree = new Tree(Tools::createVector(lane.substr(4)));
    *tree = *tree + *subtree;
    INTERPRETED(tree->print());
}

void Interface::comp(const std::string &lane) {
    std::string tmp = lane.substr(4);
    std::stringstream ss;
    int amountOfVars = Tools::getAmountOfVariables(tree->vars());

    if (tmp.empty() && amountOfVars != ZERO) {
        WRONG_AMOUNT_OF_ARGS;
    } else if (amountOfVars == ZERO) {
        ss << tree->comp();
        RESULT_(ss.str());
    } else if (amountOfVars == Tools::getAmountOfValues(lane.substr(5)) && !tmp.empty()) {
        tree->setMap(
                Tools::createMap(lane.substr(5), tree->vars()));
        ss << tree->comp();
        RESULT_(ss.str());
    }
}

void Interface::run() {
    bool isExit = false;
    while (!isExit) {
        std::string lane;
        std::cout << CMD;
        std::getline(std::cin, lane);
        isExit = menu(Tools::removeInvalidChars(Tools::toLowerCase(lane)));
    }
}

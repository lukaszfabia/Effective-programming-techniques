//
// Created by ufabi on 20.10.2023.
//

#include <iostream>
#include "CPreprocessExpression.h"
#include "../CTree.h"
#include "CScan.h"

CPreprocessExpression::CPreprocessExpression() {
    elements = std::vector<std::string>();
}

CPreprocessExpression::CPreprocessExpression(const std::string &newExpression) {
    expression = newExpression;
    elements = std::vector<std::string>();
    fixExpression();
}

CPreprocessExpression::~CPreprocessExpression() {
    elements.clear();
}

std::string CPreprocessExpression::getExpression() {
    setExpression("");
    for (int i = 0; i < elements.size(); i++) {
        setExpression(expression + elements[i] + " ");
    }
    return expression;
}

std::vector<std::string> CPreprocessExpression::getElements() {
    return elements;
}

bool CPreprocessExpression::isNumber(const std::string &token) {
    return isdigit(token[0]);
}

bool CPreprocessExpression::isOperator(const std::string &token) {
    return token == "+" || token == "*" || token == "-" || token == "/";
}

bool CPreprocessExpression::isVariable(const std::string &token) {
    return !isOperator(token) && !isNumber(token) && !isFunction(token);
}

bool CPreprocessExpression::isFunction(const std::string &token) {
    return token == "sin" || token == "cos";
}

void CPreprocessExpression::setElements(const std::vector<std::string> &newElements) {
    elements = newElements;
}

void CPreprocessExpression::setExpression(const std::string &newExpression) {
    expression = newExpression;
    createVector(expression);
}

void CPreprocessExpression::createVector(const std::string &newExpression) {
    elements.clear();
    std::string currentElement;
    for (int i = 0; i < newExpression.length(); i++) {
        if (newExpression[i] == ' ') {
            if (!currentElement.empty()) {
                elements.push_back(currentElement);
                currentElement = "";
            }
        } else {
            currentElement += newExpression[i];
        }
    }
    if (!currentElement.empty()) {
        elements.push_back(currentElement);
    }
    setElements(elements);
}

bool CPreprocessExpression::fixExpression() {
    createVector(expression);
    if (amountOfNumbers() == amountOfOperators() + 1) {
        return false;
    }

    if (expression.empty() || hasOnlyNumbersOrVars() || amountOfNumbers() == amountOfOperators()) {
        setExpression(DEFAULT_EXPRESSION);
        return false;
    }

    if (amountOfOperators() == amountOfNumbers() - 2) {
        elements.pop_back();
        return true;
    }
    // TODO PATRZE ISSUES NA GICIE
    CTree tree = CTree(this);
    std::string newExpression = tree.printNormalExpression();
    std::string fixedExpression;
    createVector(newExpression); // Załóżmy, że ta funkcja tworzy vector elements.

    if (isOperator(elements[0])) {
        fixedExpression += " " + FILL_VALUE;
    }

    for (int i = 0; i < elements.size(); i++) {
        if (isOperator(elements[i])) {
            fixedExpression += " " + elements[i] + " " + FILL_VALUE + " ";
        } else {
            fixedExpression += " " + elements[i];
        }
    }

    createVector(fixedExpression);

    if (isOperator(std::string(1, fixedExpression[fixedExpression.length() - 1])) &&
        amountOfNumbers() != amountOfOperators() + 1) {
        fixedExpression += " " + FILL_VALUE;
    }

    createVector(fixedExpression);
    fixedExpression = "";
    for (int i=0; i<elements.size(); i++) {
        fixedExpression+=elements[i];
    }
    CScan::printResult(fixedExpression);
    // todo wywolanie funkcji infix to prefix
    return true;
}


int CPreprocessExpression::amountOfOperators() {
    int numberOfOperators = 0;
    for (int i = 0; i < elements.size(); i++) {
        if (isOperator(elements[i])) {
            numberOfOperators++;
        }
    }
    return numberOfOperators;
}

int CPreprocessExpression::amountOfNumbers() {
    int numberOfNumbers = 0;
    for (int i = 0; i < elements.size(); i++) {
        if (isNumber(elements[i]) || isVariable(elements[i])) {
            numberOfNumbers++;
        }
    }
    return numberOfNumbers;
}

int CPreprocessExpression::hasOnlyNumbersOrVars() {
    for (int i = 0; i < elements.size(); i++) {
        if (!isNumber(elements[i]) && !isVariable(elements[i])) {
            return false;
        }
    }
    return true;
}
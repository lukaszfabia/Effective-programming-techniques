//
// Created by ufabi on 20.10.2023.
//

#include <iostream>
#include "CPreprocessExpression.h"
#include "../CTree.h"

CPreprocessExpression::CPreprocessExpression() {
    elements = std::vector<std::string>();
}

CPreprocessExpression::CPreprocessExpression(const std::string &newExpression) {
    expression = newExpression;
    elements = std::vector<std::string>();
    fixExpression();
    createVector(expression);
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
}

void CPreprocessExpression::createVector(const std::string &newExpression) {
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
    if (amountOfNumbers(expression) == amountOfOperators(expression) + 1) {
        return false;
    }

    if (expression.empty() || hasOnlyNumbersOrVars(expression)) {
        setExpression(DEFAULT_EXPRESSION);
        return false;
    }
    // TODO PATRZE ISSUES NA GICIE

    expression += " ";
    std::string fixedString;
    bool needOperand = true;

    for (int i = 0; i < expression.length(); i++) {
        fixedString += expression[i];

        if (isOperator(std::string(1, expression[i]))) {
            if (needOperand) {
                fixedString += " " + FILL_VALUE + " ";
                needOperand = false;
            }else {
                needOperand = true;
            }
        } else {
            needOperand = true;
        }
    }

    if (amountOfOperators(fixedString) == amountOfNumbers(fixedString)) {
        fixedString += " " + FILL_VALUE;
    }

    setExpression(fixedString);

    return true;
}

int CPreprocessExpression::amountOfOperators(const std::string& str) {
    int numberOfOperators = 0;
    for (int i = 0; i < str.length(); i++) {
        if (isOperator(std::string(1, str[i])))
            numberOfOperators++;
    }
    return numberOfOperators;
}

int CPreprocessExpression::amountOfNumbers(const std::string& str) {
    int numberOfNumbers = 0;
    for (int i = 0; i < str.length(); i++) {
        if (isNumber(std::string(1, str[i])) || isVariable(std::string(1, str[i])) && str[i]!=' ') {
            numberOfNumbers++;
        }
    }
    return numberOfNumbers;
}

int CPreprocessExpression::hasOnlyNumbersOrVars(const std::string& str) {
    for (int i = 0; i < str.length(); i++) {
        if (!isNumber(std::string(1, str[i])) && !isVariable(std::string(1, str[i])) && str[i]!=' ') {
            return false;
        }
    }
    return true;
}
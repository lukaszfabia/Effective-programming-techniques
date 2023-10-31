//
// Created by ufabi on 20.10.2023.
//

#include <iostream>
#include "CPreprocessExpression.h"
#include "../CTree.h"
#include "CScan.h"
#include <stack>
#include <string>
#include <algorithm>
#include <sstream>
#include <cctype>

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
    std::string tmp;
    for (int i = 0; i < elements.size(); i++) {
        tmp += elements[i] + " ";
    }
    return tmp;
}

std::vector<std::string> CPreprocessExpression::getElements() {
    return elements;
}

bool CPreprocessExpression::isNumber(const std::string &token) {
    for (int i = 0; i < token.length(); ++i) {
        if (!isdigit(token[i])) {
            return false;
        }
    }
    return true;
}

bool CPreprocessExpression::isOperator(const std::string &token) {
    return token == "+" || token == "*" || token == "-" || token == "/";
}

bool CPreprocessExpression::isOperator(char c) {
    return (!isalpha(c) && !isdigit(c) && c != '=');
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
    std::istringstream iss(newExpression);
    std::string element;

    while (iss >> std::ws >> element) {
        elements.push_back(element);
    }


    setElements(elements);
}

bool CPreprocessExpression::fixExpression() {
    createVector(expression);
    if (amountOfNumbers() == amountOfOperators() + 1) {
        return false;
    }

    if (expression.empty() || hasOnlyNumbersOrVars()) {
        setExpression(DEFAULT_EXPRESSION);
        return false;
    }

    if (amountOfOperators() == amountOfNumbers() - 2) {
        elements.pop_back();
        return true;
    }
    CTree tree = CTree(this);
    std::string newExpression = tree.printNormalExpression();
    std::string fixedExpression;
    createVector(newExpression);

    if (isOperator(elements[0])) {
        fixedExpression += " " + FILL_VALUE;
    }

    for (int i = 0; i < elements.size(); i++) {
        if (isOperator(elements[i]) && !isNumber(elements[i + 1]) && !isVariable(elements[i + 1])) {
            fixedExpression += " " + elements[i] + " " + FILL_VALUE + " ";
        } else {
            fixedExpression += " " + elements[i];
        }
    }

    if (isOperator(elements[elements.size() - 1])) {
        fixedExpression += " " + FILL_VALUE;
    }

    createVector(fixedExpression);

    fixedExpression = "";
    for (int i = 0; i < elements.size(); i++) {
        fixedExpression += elements[i] + " ";
    }
    CScan::printResult("expression was interpreted as: " + fixedExpression);
    fixedExpression = infixToPrefix(fixedExpression);
    // todo naprawic infixtoPrefix bo splituje jak leci
    // todo przerobic infixa tak zeby bral sobie vectora
    CScan::printResult("expression was interpreted as: " + infixToPrefix(fixedExpression));
    expression = fixedExpression;
    elements.clear();
    createVector(expression);

//    for (int i = 0; i < elements.size(); ++i) {
//        CScan::printResult(elements[i]);
//    }

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

int CPreprocessExpression::getPriority(char C) {
    if (C == '-' || C == '+')
        return 1;
    else if (C == '*' || C == '/')
        return 2;
    else if (C == '^')
        return 3;
    return 0;
}

std::string CPreprocessExpression::infixToPostfix(std::string infix) {
    infix = '(' + infix + ')';
//    int l = infix.size();
    std::stack<char> char_stack;
    std::string output;

    for (int i = 0; i < infix.length(); i++) {
        if (isalpha(infix[i]) || isdigit(infix[i])) {
            output += infix[i];
            output += " ";
        } else if (infix[i] == '(') {
            char_stack.push('(');
        } else if (infix[i] == ')') {
            while (char_stack.top() != '(') {
                output += char_stack.top();
                output += " ";
                char_stack.pop();
            }
            char_stack.pop();
        } else {
            if (isOperator(char_stack.top())) {
                if (infix[i] == '^') {
                    while (getPriority(infix[i]) <= getPriority(char_stack.top())) {
                        output += char_stack.top();
                        output += " ";
                        char_stack.pop();
                    }
                } else {
                    while (getPriority(infix[i]) < getPriority(char_stack.top())) {
                        output += char_stack.top();
                        output += " ";
                        char_stack.pop();
                    }
                }
                char_stack.push(infix[i]);
            }
        }
    }
    while (!char_stack.empty()) {
        output += char_stack.top();
        char_stack.pop();
    }
    return output;
}


std::string CPreprocessExpression::infixToPrefix(std::string infix) {
    reverse(infix.begin(), infix.end());
    for (int i = 0; i < infix.length(); i++) {
        if (infix[i] == '(') {
            infix[i] = ')';
        } else if (infix[i] == ')') {
            infix[i] = '(';
        }
    }
    std::string prefix = infixToPostfix(infix);
    reverse(prefix.begin(), prefix.end());
    return trim(prefix);
}

std::string CPreprocessExpression::trim(const std::string& output){
    unsigned long first = output.find_first_not_of(" \t\n\r");
    if (std::string::npos == first){
        return output;
    }

    unsigned long last = output.find_last_not_of(" \t\n\r");
    return output.substr(first, (last - first + 1));
}

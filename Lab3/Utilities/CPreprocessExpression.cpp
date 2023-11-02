//
// Created by ufabi on 20.10.2023.
//

#include <iostream>
#include "CPreprocessExpression.h"
#include "../CTree.h"
#include "CScan.h"
#include <stack>
#include <string>
#include <map>
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
    /// case when expression is correct
    if (isCorrect()) {
        return false;
    }
    /// when expression is completely empty or has only numbers or variables
    if (expression.empty() || hasOnlyNumbersOrVars()) {
        setExpression(DEFAULT_EXPRESSION);
        return false;
    }
    /// case when we have too many args - we delete last one
    if (amountOfOperators() == amountOfNumbers() - 2) {
        elements.pop_back();
        return true;
    }
    /// case when we have a only operators in expression - we build balanced tree then
    if (hasOnlyOperators()) {
        for (int i = 0; i < elements.size() + 1; i++) {
            if (i % 2 != 0) {
                elements.insert(elements.begin() + i, FILL_VALUE);
            }
        }
        elements.push_back(FILL_VALUE);
        return true;
    }
    /// case when we have a missing elements in expression - we add them
    CTree tree = CTree(this);
    std::string newExpression = tree.printNormalExpression();
    createVector(newExpression);

    if (!elements.empty() && isOperator(elements[0])) {
        elements.insert(elements.begin(), FILL_VALUE);
    }

    for (int i = 0; i < elements.size(); i++) {
        if (isOperator(elements[i]) && i < elements.size() - 1 && nextNotAnOperator(elements[i + 1])) {
            elements.insert(elements.begin() + i + 1, FILL_VALUE);
        }
    }

    if (!elements.empty() && isOperator(elements[elements.size() - 1])) {
        elements.push_back(FILL_VALUE);
    }

    elements = infixToPrefix(elements);

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

bool CPreprocessExpression::hasOnlyNumbersOrVars() {
    for (int i = 0; i < elements.size(); i++) {
        if (!isNumber(elements[i]) && !isVariable(elements[i])) {
            return false;
        }
    }
    return true;
}

bool CPreprocessExpression::isCorrect() {
    return amountOfNumbers() == amountOfOperators() + 1;
}

bool CPreprocessExpression::hasOnlyOperators() {
    for (int i = 0; i < elements.size(); i++) {
        if (!isOperator(elements[i])) {
            return false;
        }
    }
    return true;
}

int CPreprocessExpression::getPriority(const std::string &operator_str) {
    if (operator_str == "+" || operator_str == "-") {
        return 1;
    } else if (operator_str == "*" || operator_str == "/") {
        return 2;
    } else {
        return 0;
    }
}

std::vector<std::string> CPreprocessExpression::infixToPostfix(const std::vector<std::string> &infix) {
    std::stack<std::string> string_stack;
    std::vector<std::string> output;
    for (int i = 0; i < infix.size(); ++i) {
        if (isNumber(infix[i]) || isVariable(infix[i]) || isFunction(infix[i])) {
            output.push_back(infix[i]);
        } else {
            while (!string_stack.empty() && getPriority(infix[i]) < getPriority(string_stack.top())) {
                output.push_back(string_stack.top());
                string_stack.pop();
            }
            string_stack.push(infix[i]);
        }
    }
    while (!string_stack.empty()) {
        output.push_back(string_stack.top());
        string_stack.pop();
    }
    return output;
}

std::vector<std::string> CPreprocessExpression::infixToPrefix(const std::vector<std::string> &infix) {
    std::vector<std::string> reversedInfix = infix;
    std::reverse(reversedInfix.begin(), reversedInfix.end());

    // Konwersja na postfix
    std::vector<std::string> postfix = infixToPostfix(reversedInfix);

    // Odwrócenie postfix do uzyskania prefix
    std::reverse(postfix.begin(), postfix.end());

    return postfix;
}

bool CPreprocessExpression::nextNotAnOperator(const std::string &token) {
    return !isNumber(token) && !isVariable(token) && !isFunction(token);
}

std::string CPreprocessExpression::removeDuplicates(const std::string &input) {
    std::string result;
    char lastChar = '\0';

    for (int i = 0; i < input.length(); i++) {
        if (input[i] != lastChar && !(input[i] == ' ' || lastChar == ' ')) {
            result += input[i];
            result += " ";
            lastChar = input[i];
        }
    }

    return result;
}

int CPreprocessExpression::getAmountOfVariables(const std::string &input) {
    int amount = 0;
    std::istringstream iss(removeDuplicates(input));
    std::string element;

    while (iss >> std::ws >> element) {
        amount++;
    }

    return amount;
}

int CPreprocessExpression::getAmountOfValues(const std::string &lane) {
    int amount = 0;
    std::istringstream iss(lane);
    std::string element;

    while (iss >> std::ws >> element) {
        if (isNumber(element)) {
            amount++;
        }
    }

    return amount;
}

std::map<std::string, int> CPreprocessExpression::createMap(const std::string &values, const std::string &vars) {
    std::map<std::string, int> result;
    std::istringstream valuesStream(values);
    std::istringstream varsStream(vars);
    std::string value;
    std::string var;

    while (std::getline(valuesStream, value, ' ')) {
        if (std::getline(varsStream, var, ' ')) {
            result[var] = std::stoi(value);
        }
    }

    return result;
}
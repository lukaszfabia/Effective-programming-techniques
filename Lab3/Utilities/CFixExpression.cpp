//
// Created by Lukasz Fabia on 02/11/2023.
//

#include "CFixExpression.h"
#include "../CTree.h"
#include <stack>

CFixExpression::CFixExpression() {
    expression = DEFAULT_EXPRESSION;
}

CFixExpression::CFixExpression(const std::string &newExpression) {
    elements = std::vector<std::string>();
    expression = newExpression;
}

CFixExpression::~CFixExpression() {
    elements.clear();
}

int CFixExpression::amountOfOperators() {
    int numberOfOperators = 0;
    for (int i = 0; i < elements.size(); i++) {
        if (isOperator(elements[i])) {
            numberOfOperators++;
        }
    }
    return numberOfOperators;
}

int CFixExpression::amountOfNumbers() {
    int numberOfNumbers = 0;
    for (int i = 0; i < elements.size(); i++) {
        if (isNumber(elements[i]) || isVariable(elements[i])) {
            numberOfNumbers++;
        }
    }
    return numberOfNumbers;
}

bool CFixExpression::hasOnlyNumbersOrVars() {
    for (int i = 0; i < elements.size(); i++) {
        if (!isNumber(elements[i]) && !isVariable(elements[i])) {
            return false;
        }
    }
    return true;
}

int CFixExpression::getPriority(const std::string &operator_str) {
    if (operator_str == "+" || operator_str == "-") {
        return 1;
    } else if (operator_str == "*" || operator_str == "/") {
        return 2;
    } else {
        return 0;
    }
}

std::vector<std::string> CFixExpression::infixToPostfix(const std::vector<std::string> &infix) {
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

std::vector<std::string> CFixExpression::infixToPrefix(const std::vector<std::string> &infix) {
    std::vector<std::string> reversedInfix = infix;
    std::reverse(reversedInfix.begin(), reversedInfix.end());

    /// convert to postfix
    std::vector<std::string> postfix = infixToPostfix(reversedInfix);

    /// reverse postfix to get prefix
    std::reverse(postfix.begin(), postfix.end());

    return postfix;
}

bool CFixExpression::nextNotAnOperator(const std::string &token) {
    return !isNumber(token) && !isVariable(token) && !isFunction(token);
}

bool CFixExpression::isCorrect() {
    return amountOfNumbers() == amountOfOperators() + 1;
}

bool CFixExpression::hasOnlyOperators() {
    for (int i = 0; i < elements.size(); i++) {
        if (!isOperator(elements[i])) {
            return false;
        }
    }
    return true;
}

std::vector<std::string> CFixExpression::fixExpression() {
    elements = createVector(expression);
    /// case when expression is correct
    if (isCorrect()) {
        return elements;
    }
    /// when expression is completely empty or has only numbers or variables
    if (expression.empty() || hasOnlyNumbersOrVars()) {
        expression = DEFAULT_EXPRESSION;
        elements = createVector(expression);
        return elements;
    }
    /// case when we have too many args - we delete last one
    if (amountOfOperators() == amountOfNumbers() - 2) {
        elements.pop_back();
        return elements;
    }
    /// case when we have a only operators in expression - we build balanced tree then
    if (hasOnlyOperators()) {
        for (int i = 0; i < elements.size() + 1; i++) {
            if (i % 2 != 0) {
                elements.insert(elements.begin() + i, FILL_VALUE);
            }
        }
        elements.push_back(FILL_VALUE);
        return elements;
    }
    /// case when we have a missing elements in expression - we add them
    CTree *tree = new CTree(elements);
    std::string newExpression = tree->printNormalExpression();
    delete tree;
    elements = createVector(newExpression);

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

    return elements;
}

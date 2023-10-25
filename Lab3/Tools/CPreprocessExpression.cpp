//
// Created by ufabi on 20.10.2023.
//

#include "CPreprocessExpression.h"

CPreprocessExpression::CPreprocessExpression() {
    elements = std::vector<std::string>();
}

CPreprocessExpression::CPreprocessExpression(const std::string& expression) {
    elements = std::vector<std::string>();
    std::string currentElement;
    for (int i = 0; i < expression.length(); i++) {
        if (expression[i] == ' ') {
            if (!currentElement.empty()) {
                elements.push_back(currentElement);
                currentElement = "";
            }
        } else {
            currentElement += expression[i];
        }
    }
    if (!currentElement.empty()) {
        elements.push_back(currentElement);
    }
}

CPreprocessExpression::~CPreprocessExpression() {
    elements.clear();
}

std::string CPreprocessExpression::getExpression() {
    return expression;
}

std::vector<std::string> CPreprocessExpression::getElements() {
    return elements;
}

//
// Created by ufabi on 20.10.2023.
//

#include <iostream>
#include "CPreprocessExpression.h"
#include <string>
#include <map>
#include <sstream>
#include <cctype>

CPreprocessExpression::CPreprocessExpression() {
    elements = std::vector<std::string>();
}

CPreprocessExpression::CPreprocessExpression(const std::string &newExpression) {
    elements = std::vector<std::string>();
    expression = newExpression;
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
}

std::vector<std::string> CPreprocessExpression::createVector(const std::string &newExpression) {
    elements.clear();
    std::istringstream iss(newExpression);
    std::string element;

    while (iss >> std::ws >> element) {
        elements.push_back(element);
    }

    return elements;
}

std::string CPreprocessExpression::removeDuplicates(const std::string &input) {
    std::string result;

    for (int i = 0; i < input.length(); i++) {
        if (result.find(input[i]) == std::string::npos) {
            result += input[i];
            result += " ";
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

std::string CPreprocessExpression::toLowerCase(const std::string &input) {
    std::string result = input;

    for (int i = 0; i < result.length(); ++i) {
        if (result[i] <= 'Z' && result[i] >= 'A')
            result[i] = static_cast<char>(result[i] + 32);
    }

    return result;
}

std::string CPreprocessExpression::removeInvalidVars(const std::string &input) {
    std::string result = input;
    const char invalidChars[] = "!@#$%^&()_={}[]|\\:;\"'<>,.?/";

    for (int i = 0; i < result.length(); ++i) {
        if (strchr(invalidChars, result[i]) != NULL) {
            result.erase(i, 1);
            --i;
        }
    }

    return result;
}
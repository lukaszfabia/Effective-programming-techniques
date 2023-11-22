//
// Created by ufabi on 21.11.2023.
//

#include "Tools.h"
#include "../Tree.h"

bool Tools::isNumber(const std::string &token) {
    bool hasDot = false;
    bool hasMinus = false;

    for (int i = 0; i < token.length(); ++i) {
        if (!isdigit(token[i])) {
            if (token[i] == DOT && !hasDot) {
                hasDot = true;
            } else if (token[i] == MINUS && !hasMinus) {
                hasMinus = true;
            } else {
                return false;
            }
        }
    }
    return true;
}

std::vector<std::string> Tools::createVector(const std::string &expression) {
    std::vector<std::string> elements;
    std::istringstream iss(expression);
    std::string element;

    while (iss >> std::ws >> element) {
        elements.push_back(element);
    }

    return elements;
}

std::map<std::string, double> Tools::createMap(const std::string &values, const std::string &vars) {
    std::map<std::string, double> result;
    std::istringstream valuesStream(values);
    std::istringstream varsStream(vars);
    std::string value;
    std::string var;

    while (std::getline(valuesStream, value, ' ')) {
        if (std::getline(varsStream, var, ' ')) {
            std::stringstream ss(value);
            double castedVal;
            ss >> castedVal;
            result[var] = castedVal;
        }
    }

    return result;
}

std::string Tools::removeDuplicates(const std::string &input) {
    std::istringstream iss(input);
    std::set<std::string> seenElements;
    std::string result, word;

    while (iss >> word) {
        if (seenElements.find(word) == seenElements.end()) {
            seenElements.insert(word);
            result += word + SPACE;
        }
    }

    if (!result.empty()) {
        result.erase(result.size() - 1);
    }

    return result;
}

int Tools::getAmountOfVariables(const std::string &input) {
    int amount = 0;
    std::istringstream iss(input);
    std::string element;

    while (iss >> std::ws >> element) {
        amount++;
    }

    return amount;
}

int Tools::getAmountOfValues(const std::string &input) {
    int amount = 0;
    std::istringstream iss(input);
    std::string element;

    while (iss >> std::ws >> element) {
        if (IS_NUMBER(element) || IS_STRING(element)) {
            amount++;
        }
    }

    return amount;
}

std::string Tools::removeInvalidChars(const std::string &input) {
    std::string result = input;

    for (int i = 0; i < result.length(); ++i) {
        if (strchr(INVALID_CHARS, result[i]) != NULL) {
            result.erase(i, 1);
            --i;
        }
    }

    return result;
}

std::string Tools::toLowerCase(const std::string &input) {
    std::string result = input;
    std::transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

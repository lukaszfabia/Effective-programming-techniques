//
// Created by Lukasz Fabia on 04/01/2024.
//

#include "Tools.h"

std::string Tools::toLowerCase(const std::string &input) {
    std::string result = input;
    std::transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
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

std::string Tools::substract(const std::string &input, const std::string &sub) {
    std::stringstream ss;
    if (input.length() < sub.length() || input.find(sub) == std::string::npos) {
        SET_QUOTE(input);
        return ss.str();
    }
    size_t index = input.length() - sub.length();
    for (size_t i = index; i < input.length(); ++i) {
        if (input[i] != sub[i - index]) {
            SET_QUOTE(input);
            return ss.str();
        }
    }

    SET_QUOTE(input.substr(0, index));
    return ss.str();
}

std::string Tools::multiply(const std::string &input, const std::string &sub) {
    std::string result;
    std::stringstream ss;
    for (char i: input) {
        if (i == sub[0]) {
            result += sub;
        } else {
            result += i;
        }
    }

    SET_QUOTE(result);
    return ss.str();
}

std::string Tools::divide(const std::string &input, const std::string &sub) {
    std::string result;
    std::stringstream ss;
    for (size_t i = 0; i < input.length(); i++) {
        if (input[i] == sub[0]) {
            if (input.substr(i, sub.length()) == sub) {
                result += sub[0];
                i += sub.length() - 1;
            } else {
                result += input[i];
            }
        } else {
            result += input[i];
        }
    }


    SET_QUOTE(result);
    return ss.str();
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

int Tools::getAmountOfVariables(const std::string &input) {
    int amount = 0;
    std::istringstream iss(input);
    std::string element;

    while (iss >> std::ws >> element) {
        amount++;
    }

    return amount;
}

bool Tools::isNumber(const std::string &token) {
    std::istringstream iss(token);
    double number;
    iss >> number;
    return iss.eof() && !iss.fail();
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
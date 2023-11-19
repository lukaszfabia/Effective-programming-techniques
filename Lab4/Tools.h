//
// Created by ufabi on 19.11.2023.
//

#ifndef TEMPLATES_TOOLS_H
#define FILL "x"
#define EXPRESSION "+ x y"
#define TEMPLATES_TOOLS_H


#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <stack>
#include <sstream>

template<class T>
class Tools {
public:

    static bool isOperator(const std::string &token);

    static bool isFunction(const std::string &token);

    static bool isVariable(const std::string &token);

    static bool isString(const std::string &token);

    static bool isNumber(const std::string &token);

    static std::vector<std::string> createVector(const std::string &expression);

    static std::map<std::string, T> createMap(const std::string &values, const std::string &vars);

    static std::string removeDuplicates(const std::string &input);

    static int getAmountOfVariables(const std::string &input);

    static int getAmountOfValues(const std::string &input);
};

template<class T>
int Tools<T>::getAmountOfValues(const std::string &input) {
    int amount = 0;
    std::istringstream iss(input);
    std::string element;

    while (iss >> std::ws >> element) {
        if (isNumber(element) || isString(element)) {
            amount++;
        }
    }

    return amount;
}

template<class T>
int Tools<T>::getAmountOfVariables(const std::string &input) {
    int amount = 0;
    std::istringstream iss(input);
    std::string element;

    while (iss >> std::ws >> element) {
        amount++;
    }

    return amount;
}

template<class T>
bool Tools<T>::isOperator(const std::string &token) {
    return token == "+" || token == "-" || token == "*" || token == "/";
}

template<class T>
bool Tools<T>::isFunction(const std::string &token) {
    return token == "sin" || token == "cos";
}

template<class T>
bool Tools<T>::isVariable(const std::string &token) {
    return !isOperator(token) && !isFunction(token) && !isNumber(token) && !isString(token);
}

template<class T>
bool Tools<T>::isString(const std::string &token) {
    return token[0] == '"' && token[token.size() - 1] == '"';
}

template<class T>
bool Tools<T>::isNumber(const std::string &token) {
    bool hasDot = false;

    for (int i = 0; i < token.length(); ++i) {
        if (!isdigit(token[i])) {
            if (token[i] == '.' && !hasDot) {
                hasDot = true;
            } else {
                return false;
            }
        }
    }
    return true;
}

template<class T>
std::vector<std::string> Tools<T>::createVector(const std::string &expression) {
    std::vector<std::string> elements;
    std::istringstream iss(expression);
    std::string element;

    while (iss >> std::ws >> element) {
        elements.push_back(element);
    }

    return elements;
}

template<class T>
std::string Tools<T>::removeDuplicates(const std::string &input) {
    std::istringstream iss(input);
    std::set<std::string> seenElements;
    std::string result, word;

    while (iss >> word) {
        if (seenElements.find(word) == seenElements.end()) {
            seenElements.insert(word);
            result += word + " ";
        }
    }

    if (!result.empty()) {
        result.erase(result.size() - 1);
    }

    return result;
}

template<class T>
std::map<std::string, T> Tools<T>::createMap(const std::string &values, const std::string &vars) {
    std::map<std::string, T> result;
    std::istringstream valuesStream(values);
    std::istringstream varsStream(vars);
    std::string value;
    std::string var;

    while (std::getline(valuesStream, value, ' ')) {
        if (std::getline(varsStream, var, ' ')) {
            std::stringstream ss(value);
            T castedVal;
            ss >> castedVal;
            result[var] = castedVal;
        }
    }

    return result;
}

#endif //TEMPLATES_TOOLS_H

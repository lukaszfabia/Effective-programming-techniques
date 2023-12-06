//
// Created by ufabi on 19.11.2023.
//

#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <stack>
#include <sstream>
#include <cstring>

#ifndef TEMPLATES_TOOLS_H
#define FILL "x"
#define SET_QUOTE(x) ss << '"' << x << '"'
#define IS_OPERATOR(token) token == "+" || token == "-" || token == "*" || token == "/"
#define IS_FUNCTION(token) token == SINUS || token == COSINUS
#define IS_STRING(token) token[0] == '"' && token[token.size() - 1] == '"'
#define IS_NUMBER(token) Tools<T>::isNumber(token)
#define IS_VARIABLE(token) !(IS_OPERATOR(token)) && !(IS_FUNCTION(token)) && !(IS_NUMBER(token)) && !(IS_STRING(token))
#define DOT '.'
#define MINUS '-'
#define SPACE " "
#define REMOVE_QUOTE(input) input.substr(1, input.size() - 2)
#define INVALID_CHARS "!@#$%^&()_={}[]|\\:;\'<>,?"
#define TEMPLATES_TOOLS_H


template<class T>
class Tools {
public:

    static bool isNumber(const std::string &token);

    static std::vector<std::string> createVector(const std::string &expression);

    static std::map<std::string, T> createMap(const std::string &values, const std::string &vars);

    static std::string removeDuplicates(const std::string &input);

    static int getAmountOfVariables(const std::string &input);

    static int getAmountOfValues(const std::string &input);

    static std::string substract(const std::string &input, const std::string &sub);

    static std::string multiply(const std::string &input, const std::string &sub);

    static std::string divide(const std::string &input, const std::string &sub);

    static std::string removeInvalidChars(const std::string &input);

    static std::string toLowerCase(const std::string &input);

};

template<class T>
std::string Tools<T>::toLowerCase(const std::string &input) {
    std::string result = input;
    std::transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

template<class T>
std::string Tools<T>::removeInvalidChars(const std::string &input) {
    std::string result = input;

    for (int i = 0; i < result.length(); ++i) {
        if (strchr(INVALID_CHARS, result[i]) != NULL) {
            result.erase(i, 1);
            --i;
        }
    }

    return result;
}

template<class T>
std::string Tools<T>::substract(const std::string &input, const std::string &sub) {
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

template<class T>
std::string Tools<T>::multiply(const std::string &input, const std::string &sub) {
    std::string result;
    std::stringstream ss;
    for (size_t i = 0; i < input.length(); ++i) {
        if (input[i] == sub[0]) {
            result += sub;
        } else {
            result += input[i];
        }
    }

    SET_QUOTE(result);
    return ss.str();
}

template<class T>
std::string Tools<T>::divide(const std::string &input, const std::string &sub) {
    std::string result;
    std::stringstream ss;
    for (size_t i = 0; i < input.length(); i++) {
        if (input[i] == sub[0]) {
            if (input.substr(i, sub.length()) == sub) {
                result += sub[0];
                i += sub.length() - 1;
            }else{
                result += input[i];
            }
        } else {
            result += input[i];
        }
    }


    SET_QUOTE(result);
    return ss.str();
}

template<class T>
int Tools<T>::getAmountOfValues(const std::string &input) {
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
bool Tools<T>::isNumber(const std::string &token) {
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
            result += word + SPACE;
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

//
// Created by ufabi on 19.11.2023.
//

#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <sstream>

#ifndef TEMPLATES_TOOLS_H
#define FILL "x"
#define SET_QUOTE(x) ss << '"' << x << '"'
#define IS_OPERATOR(token) token == "+" || token == "-" || token == "*" || token == "/"
#define IS_FUNCTION(token) token == SINUS || token == COSINUS
#define IS_STRING(token) token[0] == '"' && token[token.size() - 1] == '"'
#define IS_NUMBER(token) Tools::isNumber(token)
#define IS_VARIABLE(token) !(IS_OPERATOR(token)) && !(IS_FUNCTION(token)) && !(IS_NUMBER(token)) && !(IS_STRING(token))
#define SPACE " "
#define REMOVE_QUOTE(input) input.substr(1, input.size() - 2)
#define INVALID_CHARS "!@#$%^&()_={}[]|\\:;\'<>,?"
#define TEMPLATES_TOOLS_H

namespace Tools {
    bool isNumber(const std::string &token);

    std::vector<std::string> createVector(const std::string &expression);

    template<typename T>
    std::map<std::string, T> createMap(const std::string &values, const std::string &vars);

    std::string removeDuplicates(const std::string &input);

    int getAmountOfVariables(const std::string &input);

    int getAmountOfValues(const std::string &input);

    std::string substract(const std::string &input, const std::string &sub);

    std::string multiply(const std::string &input, const std::string &sub);

    std::string divide(const std::string &input, const std::string &sub);

    std::string removeInvalidChars(const std::string &input);

    std::string toLowerCase(const std::string &input);

}

template<typename T>
std::map<std::string, T> Tools::createMap(const std::string &values, const std::string &vars) {
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

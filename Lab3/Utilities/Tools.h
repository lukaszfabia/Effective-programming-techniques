//
// Created by ufabi on 21.11.2023.
//
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <stack>
#include <sstream>
#include <cstring>

#ifndef TREE_TOOLS_H
#define FILL "x"
#define EXPRESSION "+ x y"
#define SET_QUOTE(x) ss << '"' << x << '"'
#define IS_OPERATOR(token) token == "+" || token == "-" || token == "*" || token == "/"
#define IS_FUNCTION(token) token == SINUS || token == COSINUS
#define IS_STRING(token) token[0] == '"' && token[token.size() - 1] == '"'
#define IS_NUMBER(token) Tools::isNumber(token)
#define IS_VARIABLE(token) !(IS_OPERATOR(token)) && !(IS_FUNCTION(token)) && !(IS_NUMBER(token)) && !(IS_STRING(token))
#define DOT '.'
#define REMOVE_QUOTE(input) input.substr(1, input.size() - 2)
#define INVALID_CHARS "!@#$%^&()_={}[]|\\:;\"'<>,?/"
#define TREE_TOOLS_H


class Tools {
public:
    static bool isNumber(const std::string &token);

    static std::vector<std::string> createVector(const std::string &expression);

    static std::map<std::string, double> createMap(const std::string &values, const std::string &vars);

    static std::string removeDuplicates(const std::string &input);

    static int getAmountOfVariables(const std::string &input);

    static int getAmountOfValues(const std::string &input);

    static std::string removeInvalidChars(const std::string &input);

    static std::string toLowerCase(const std::string &input);
};


#endif //TREE_TOOLS_H

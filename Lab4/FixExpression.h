//
// Created by ufabi on 19.11.2023.
//

#ifndef TEMPLATES_FIXEXPRESSION_H
#define TEMPLATES_FIXEXPRESSION_H
#define IS_CORRECT(vector1) amountOfNumbers(vector1) == amountOfOperators(vector1) + 1

#include <vector>
#include <string>
#include "Tools.h"
#include "Tree.h"

template<class T>
class FixExpression {
private:

    static bool hasOnlyVarsOrNumbers(const std::vector<std::string> &vector1) {
        for (int i = 0; i < vector1.size(); i++) {
            if (IS_OPERATOR(vector1[i]) || IS_FUNCTION(vector1[i])) {
                return false;
            }
        }
        return  true;
    }

    static int amountOfOperators(const std::vector<std::string> &vector1) {
        int numberOfOperators = 0;
        for (int i = 0; i < vector1.size(); i++) {
            if (IS_OPERATOR(vector1[i])) {
                numberOfOperators++;
            }
        }
        return numberOfOperators;
    }

    static int amountOfNumbers(const std::vector<std::string> &vector1) {
        int numberOfNumbers = 0;
        for (int i = 0; i < vector1.size(); i++) {
            if (!(IS_FUNCTION(vector1[i]) || IS_OPERATOR(vector1[i]))) {
                numberOfNumbers++;
            }
        }
        return numberOfNumbers;
    }

    static bool hasOnlyOperators(const std::vector<std::string> &vector1) {
        for (int i = 0; i < vector1.size(); i++) {
            if (!(IS_OPERATOR(vector1[i]))) {
                return false;
            }
        }
        return true;
    }

    static std::vector<std::string> infixToPrefix(const std::vector<std::string> &infix);

    static std::vector<std::string> infixToPostfix(const std::vector<std::string> &infix);

    static int getPriority(const std::string &operator_str);

public:
    static std::vector<std::string> fix(std::vector<std::string> tokens);
};

template<class T>
std::vector<std::string> FixExpression<T>::fix(std::vector<std::string> tokens) {
    if (IS_CORRECT(tokens)) {
        return tokens;
    }

    if (hasOnlyVarsOrNumbers(tokens)) {
        tokens = Tools<T>::createVector(EXPRESSION);
        return tokens;
    }

    if (amountOfOperators(tokens) == amountOfNumbers(tokens) - 2) {
        tokens.pop_back();
        return tokens;
    }

    if (hasOnlyOperators(tokens)) {
        for (int i = 0; i < tokens.size() + 1; i++) {
            if (i % 2 != 0) {
                tokens.insert(tokens.begin() + i, FILL);
            }
        }
        tokens.push_back(FILL);
        return tokens;
    }

    Tree<T> *tree = new Tree<T>(tokens);
    std::string newExpression = tree->norm();
    delete tree;
    tokens = Tools<T>::createVector(newExpression);

    if (!tokens.empty() && IS_OPERATOR(tokens[0])) {
        tokens.insert(tokens.begin(), FILL);
    }

    for (int i = 0; i < tokens.size(); i++) {
        if (IS_OPERATOR(tokens[i]) && i < tokens.size() - 1 && IS_OPERATOR(tokens[i + 1])) {
            tokens.insert(tokens.begin() + i + 1, FILL);
        }
    }

    if (!tokens.empty() && IS_OPERATOR(tokens[tokens.size() - 1])) {
        tokens.push_back(FILL);
    }

    tokens = infixToPrefix(tokens);

    return tokens;
}

template<class T>
std::vector<std::string> FixExpression<T>::infixToPrefix(const std::vector<std::string> &infix) {
    std::vector<std::string> reversedInfix = infix;
    std::reverse(reversedInfix.begin(), reversedInfix.end());

    /// convert to postfix
    std::vector<std::string> postfix = infixToPostfix(reversedInfix);

    /// reverse postfix to get prefix
    std::reverse(postfix.begin(), postfix.end());

    return postfix;
}

template<class T>
std::vector<std::string> FixExpression<T>::infixToPostfix(const std::vector<std::string> &infix) {
    std::stack<std::string> string_stack;
    std::vector<std::string> output;
    for (int i = 0; i < infix.size(); ++i) {
        if (!(IS_OPERATOR(infix[i]))) {
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

template<class T>
int FixExpression<T>::getPriority(const std::string &operator_str) {
    if (operator_str == "+" || operator_str == "-") {
        return 1;
    } else if (operator_str == "*" || operator_str == "/") {
        return 2;
    } else {
        return 0;
    }
}

#endif //TEMPLATES_FIXEXPRESSION_H

//
// Created by ufabi on 21.11.2023.
//

#include "FixExpression.h"
#include "../Tree.h"

bool FixExpression::hasOnlyVarsOrNumbers(const std::vector<std::string> &vector1) {
    for (int i = 0; i < vector1.size(); i++) {
        if (IS_OPERATOR(vector1[i]) || IS_FUNCTION(vector1[i])) {
            return false;
        }
    }
    return true;
}

int FixExpression::amountOfOperators(const std::vector<std::string> &vector1) {
    int numberOfOperators = 0;
    for (int i = 0; i < vector1.size(); i++) {
        if (IS_OPERATOR(vector1[i])) {
            numberOfOperators++;
        }
    }
    return numberOfOperators;
}

int FixExpression::amountOfNumbers(const std::vector<std::string> &vector1) {
    int numberOfNumbers = 0;
    for (int i = 0; i < vector1.size(); i++) {
        if (!(IS_FUNCTION(vector1[i]) || IS_OPERATOR(vector1[i]))) {
            numberOfNumbers++;
        }
    }
    return numberOfNumbers;
}

bool FixExpression::hasOnlyOperators(const std::vector<std::string> &vector1) {
    for (int i = 0; i < vector1.size(); i++) {
        if (!(IS_OPERATOR(vector1[i]))) {
            return false;
        }
    }
    return true;
}

std::vector<std::string> FixExpression::infixToPrefix(const std::vector<std::string> &infix) {
    std::vector<std::string> reversedInfix = infix;
    std::reverse(reversedInfix.begin(), reversedInfix.end());

    /// convert to postfix
    std::vector<std::string> postfix = infixToPostfix(reversedInfix);

    /// reverse postfix to get prefix
    std::reverse(postfix.begin(), postfix.end());

    return postfix;
}

std::vector<std::string> FixExpression::infixToPostfix(const std::vector<std::string> &infix) {
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

int FixExpression::getPriority(const std::string &operator_str) {
    if (operator_str == "+" || operator_str == "-") {
        return 1;
    } else if (operator_str == "*" || operator_str == "/") {
        return 2;
    } else {
        return 0;
    }
}

std::vector<std::string> FixExpression::fix(std::vector<std::string> tokens) {
    if (IS_CORRECT(tokens)) {
        return tokens;
    }

    if (hasOnlyVarsOrNumbers(tokens)) {
        tokens = Tools::createVector(EXPRESSION);
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

    Tree *tree = new Tree(tokens);
    std::string newExpression = tree->norm();
    delete tree;
    tokens = Tools::createVector(newExpression);

    if (!tokens.empty() && IS_OPERATOR(tokens[0])) {
        tokens.insert(tokens.begin(), FILL);
    }

    for (int i = 0; i < tokens.size(); i++) {
        if (IS_OPERATOR(tokens[i]) && i < tokens.size() - 1 && IS_OPERATOR(tokens[i + 1])) {
            tokens.insert(tokens.begin() + i + 1, FILL);
            i++;
        }
    }

    if (!tokens.empty() && IS_OPERATOR(tokens[tokens.size() - 1])) {
        tokens.push_back(FILL);
    }

    tokens = infixToPrefix(tokens);

    return tokens;
}

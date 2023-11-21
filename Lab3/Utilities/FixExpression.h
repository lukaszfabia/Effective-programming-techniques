//
// Created by ufabi on 21.11.2023.
//

#ifndef TREE_FIXEXPRESSION_H
#define TREE_FIXEXPRESSION_H
#define IS_CORRECT(vector1) amountOfNumbers(vector1) == amountOfOperators(vector1) + 1

#include <vector>
#include <string>
#include "Tools.h"
#include "../Tree.h"

class FixExpression {

private:

    static bool hasOnlyVarsOrNumbers(const std::vector<std::string> &vector1) {
        for (int i = 0; i < vector1.size(); i++) {
            if (IS_OPERATOR(vector1[i]) || IS_FUNCTION(vector1[i])) {
                return false;
            }
        }
        return true;
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


#endif //TREE_FIXEXPRESSION_H

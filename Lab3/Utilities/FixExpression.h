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

    static bool hasOnlyVarsOrNumbers(const std::vector<std::string> &vector1);

    static int amountOfOperators(const std::vector<std::string> &vector1);

    static int amountOfNumbers(const std::vector<std::string> &vector1);

    static bool hasOnlyOperators(const std::vector<std::string> &vector1);

    static std::vector<std::string> infixToPrefix(const std::vector<std::string> &infix);

    static std::vector<std::string> infixToPostfix(const std::vector<std::string> &infix);

    static int getPriority(const std::string &operator_str);

public:
    static std::vector<std::string> fix(std::vector<std::string> tokens);
};


#endif //TREE_FIXEXPRESSION_H

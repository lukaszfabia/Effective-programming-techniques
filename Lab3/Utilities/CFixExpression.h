//
// Created by Lukasz Fabia on 02/11/2023.
//

#ifndef EFFECTIVE_PROGRAMMING_TECHNIQUES_CFIXEXPRESSION_H
#define EFFECTIVE_PROGRAMMING_TECHNIQUES_CFIXEXPRESSION_H


#include <string>
#include <vector>
#include "CPreprocessExpression.h"

class CFixExpression : public CPreprocessExpression {
private:
    int amountOfOperators();

    int amountOfNumbers();

    bool hasOnlyNumbersOrVars();

    static int getPriority(const std::string &operator_str);

    static bool nextNotAnOperator(const std::string &token);

    bool isCorrect();

    bool hasOnlyOperators();

public:
    CFixExpression();

    explicit CFixExpression(const std::string &expression);

    ~CFixExpression();

    std::vector<std::string> fixExpression();

    static std::vector<std::string> infixToPostfix(const std::vector<std::string> &infix);

    static std::vector<std::string> infixToPrefix(const std::vector<std::string> &infix);
};


#endif //EFFECTIVE_PROGRAMMING_TECHNIQUES_CFIXEXPRESSION_H

//
// Created by ufabi on 20.10.2023.
//

#ifndef EFFECTIVE_PROGRAMMING_TECHNIQUES_CPREPROCESSEXPRESSION_H
#define EFFECTIVE_PROGRAMMING_TECHNIQUES_CPREPROCESSEXPRESSION_H


#include <string>
#include <vector>

class CPreprocessExpression {
private:
    std::vector<std::string> elements;
    std::string expression;
public:
    CPreprocessExpression();

    explicit CPreprocessExpression(const std::string& expression);

    ~CPreprocessExpression();

    std::string getExpression();

    std::vector<std::string> getElements();

    static bool isNumber(const std::string &token);

    static bool isOperator(const std::string &token);

    static bool isVariable(const std::string &token);

    static bool isFunction(const std::string &token);
};


#endif //EFFECTIVE_PROGRAMMING_TECHNIQUES_CPREPROCESSEXPRESSION_H

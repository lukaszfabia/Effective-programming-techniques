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

    static int amountOfOperators(const std::string &str);

    static int amountOfNumbers(const std::string &str);

    static int hasOnlyNumbersOrVars(const std::string &str);

public:
    CPreprocessExpression();

    explicit CPreprocessExpression(const std::string &newExpression);

    ~CPreprocessExpression();

    std::string getExpression();

    std::vector<std::string> getElements();

    static bool isNumber(const std::string &token);

    static bool isOperator(const std::string &token);

    static bool isVariable(const std::string &token);

    static bool isFunction(const std::string &token);

    void setElements(const std::vector<std::string> &newElements);

    void setExpression(const std::string &newExpression);

    void createVector(const std::string &newExpression);

    bool fixExpression();
};

static const std::string FILL_VALUE = "1";
static const std::string DEFAULT_EXPRESSION = "+ 2 2";

#endif //EFFECTIVE_PROGRAMMING_TECHNIQUES_CPREPROCESSEXPRESSION_H

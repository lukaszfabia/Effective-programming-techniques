//
// Created by ufabi on 20.10.2023.
//

#ifndef EFFECTIVE_PROGRAMMING_TECHNIQUES_CPREPROCESSEXPRESSION_H
#define EFFECTIVE_PROGRAMMING_TECHNIQUES_CPREPROCESSEXPRESSION_H


#include <string>
#include <vector>
#include <map>

class CPreprocessExpression {
protected:
    std::vector<std::string> elements;
    std::string expression;

    std::vector<std::string> createVector(const std::string &newExpression);
public:
    CPreprocessExpression();

    explicit CPreprocessExpression(const std::string &newExpression);

    virtual ~CPreprocessExpression() = 0;

    std::string getExpression();

    std::vector<std::string> getElements();

    void setElements(const std::vector<std::string> &newElements);

    void setExpression(const std::string &newExpression);

    static bool isNumber(const std::string &token);

    static bool isOperator(const std::string &token);

    static bool isVariable(const std::string &token);

    static bool isFunction(const std::string &token);

    static std::string removeDuplicates(const std::string &input);

    static int getAmountOfVariables(const std::string &input);

    static int getAmountOfValues(const std::string &lane);

    static std::map<std::string, int> createMap(const std::string &values, const std::string &vars);

    static std::string toLowerCase(const std::string &input);

    static std::string removeInvalidVars(const std::string &input);

    virtual std::vector<std::string> fixExpression() = 0;
};

static const std::string FILL_VALUE = "1";
static const std::string DEFAULT_EXPRESSION = "+ 2 2";

#endif //EFFECTIVE_PROGRAMMING_TECHNIQUES_CPREPROCESSEXPRESSION_H

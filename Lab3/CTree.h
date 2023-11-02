//
// Created by ufabi on 20.10.2023.
//

#ifndef EFFECTIVE_PROGRAMMING_TECHNIQUES_CTREE_H
#define EFFECTIVE_PROGRAMMING_TECHNIQUES_CTREE_H


#include <string>
#include "Utilities/CPreprocessExpression.h"
#include "Utilities/CNode.h"

class CTree {
private:
    CNode *root;
    CPreprocessExpression *preprocessExpression;
    std::map<std::string, int> values;

public:
    CTree();

    explicit CTree(CPreprocessExpression *preprocessExpression);

    ~CTree();

    CTree &operator=(const CTree &other);

    CTree operator+(const CTree &other) const;

    std::string printVars();

    std::string printNormalExpression();

    CNode *getRoot() const;

    void setRoot(CNode *cNodeRoot);

    void buildTree();

    std::string print();

    CPreprocessExpression *getPreprocessExpression() const;

    std::string printLevels();

    void setPreprocessExpression(CPreprocessExpression *pExpression);

    CNode *getOperatorChild() const;

    double calculate();

    void setValues(const std::map<std::string, int>& valuesMap);
};


#endif //EFFECTIVE_PROGRAMMING_TECHNIQUES_CTREE_H

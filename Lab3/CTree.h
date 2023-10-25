//
// Created by ufabi on 20.10.2023.
//

#ifndef EFFECTIVE_PROGRAMMING_TECHNIQUES_CTREE_H
#define EFFECTIVE_PROGRAMMING_TECHNIQUES_CTREE_H


#include <string>
#include "Tools/CPreprocessExpression.h"
#include "Tools/CNode.h"

class CTree {
private:
    CNode *root;
    CPreprocessExpression *preprocessExpression;


    std::string inOrderTraversal(CNode *startNode);

    bool isNumber(const std::string &token);

    bool isOperator(const std::string &token);

    bool isFunction(const std::string &token);

public:
    CTree();

    explicit CTree(CPreprocessExpression *preprocessExpression);

    ~CTree();

    CTree &operator=(const CTree &other);

    CTree &operator+(const CTree &other);

    std::string printVars();

    void buildTree();


};


#endif //EFFECTIVE_PROGRAMMING_TECHNIQUES_CTREE_H

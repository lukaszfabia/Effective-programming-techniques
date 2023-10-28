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

    std::string preOrderTraversal(CNode *startNode);

    std::string postOrderTraversal(CNode *startNode);

    CNode *buildSubtree(const std::vector<std::string> &elements, int &i);

public:
    CTree();

    explicit CTree(CPreprocessExpression *preprocessExpression);

    ~CTree();

    CTree &operator=(const CTree &other);

    CTree &operator+(const CTree &other);

    std::string printVars();

    std::string printNormalExpression();

    CNode *getRoot() const;

    void setRoot(CNode *cNodeRoot);

    void buildTree();

    static void addSubtree(CNode *thisNode, CNode *otherNode);

    CNode *searchForOperatorChild(CNode *currentNode);

    std::string print();
};


#endif //EFFECTIVE_PROGRAMMING_TECHNIQUES_CTREE_H

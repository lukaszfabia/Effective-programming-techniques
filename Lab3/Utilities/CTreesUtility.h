//
// Created by ufabi on 29.10.2023.
//

#ifndef EFFECTIVE_PROGRAMMING_TECHNIQUES_CTREESUTILITY_H
#define EFFECTIVE_PROGRAMMING_TECHNIQUES_CTREESUTILITY_H


#include <string>
#include <vector>
#include "CNode.h"
#include "../CTree.h"

class CTreesUtility {
public:
    static std::string inOrderTraversal(CNode *startNode);

    static std::string preOrderTraversal(CNode *startNode);

    static std::string postOrderTraversal(CNode *startNode);

    static std::string levelOrderTraversal(CNode *startNode);

    static CNode *buildSubtree(const std::vector<std::string> &elements, int &i);

    static CNode *searchForOperatorChild(CNode *currentNode);

    static CTree &addSubtree(const CTree &tree, const CTree &subtree);

    static double getValueOfExpression(CNode *currentNode, const std::map<std::string, int> &values, double result);
};

static int iteratorForAmountOfVars = 0;
#endif //EFFECTIVE_PROGRAMMING_TECHNIQUES_CTREESUTILITY_H

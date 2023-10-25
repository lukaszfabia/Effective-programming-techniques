//
// Created by ufabi on 20.10.2023.
//

#include <stack>
#include "CTree.h"
#include "Tools/CPreprocessExpression.h"

const int FILL_VALUE = 1;

CTree::CTree() {
    root = NULL;
    preprocessExpression = NULL;
}

CTree::~CTree() {
    delete root;
}

CTree &CTree::operator=(const CTree &other) {
    return *this;
}

std::string CTree::inOrderTraversal(CNode *startNode) {
    std::string result;
    if (startNode != NULL) {
        result += inOrderTraversal(startNode->getLeft());
        result += startNode->getValue() + " ";
        result += inOrderTraversal(startNode->getRight());
    }
    return result;
}


std::string CTree::printVars() {
    return inOrderTraversal(root);
}

CTree &CTree::operator+(const CTree &other) {
    return *this;
}

CTree::CTree(CPreprocessExpression *newPreprocessExpression) {
    root = NULL;
    preprocessExpression = newPreprocessExpression;
}

bool CTree::isNumber(const std::string &token) {
    return isdigit(token[0]);
}

bool CTree::isOperator(const std::string &token) {
    return token == "+" || token == "*" || token == "-" || token == "/" || token == "sin" || token == "cos";
}

bool CTree::isFunction(const std::string &token) {
    return !isOperator(token) && !isNumber(token);
}


void CTree::buildTree() {
    std::stack<CNode *> nodeStack;
    CNode *newNode;
    for (int i = 0; i < preprocessExpression->getElements().size(); i++) {
        if (isNumber(preprocessExpression->getElements()[i])) {
            newNode = new CNode(preprocessExpression->getElements()[i], NULL, NULL);
            nodeStack.push(newNode);
        } else if (isOperator(preprocessExpression->getElements()[i]) ||
                   isFunction(preprocessExpression->getElements()[i])) {
            newNode = new CNode(preprocessExpression->getElements()[i], NULL, NULL);
            CNode *right = nodeStack.top();
            nodeStack.pop();
            CNode *left = nodeStack.top();
            nodeStack.pop();
            newNode->left = left;
            newNode->right = right;
            nodeStack.push(newNode);
        }
    }

    // Po zakończeniu pętli przypisz korzeń drzewa
    if (!nodeStack.empty()) {
        root = nodeStack.top();
    }

    delete newNode;
}


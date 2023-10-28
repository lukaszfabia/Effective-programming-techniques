//
// Created by ufabi on 20.10.2023.
//

#include <stack>
#include <iostream>
#include "CTree.h"
#include "Tools/CPreprocessExpression.h"

CTree::CTree() {
    root = NULL;
    preprocessExpression = NULL;
}

CTree::~CTree() {
    delete root;
}

CTree &CTree::operator=(const CTree &other) {
    if (this == &other) {
        return *this;
    } else {
        setRoot(other.root);
        preprocessExpression = other.preprocessExpression;
        return *this;
    }
}

CTree &CTree::operator+(const CTree &other) {
    if (root == NULL) {
        root = other.root;
    } else if (searchForOperatorChild(root) != NULL) {
        CNode *operatorChild = searchForOperatorChild(root);
        if (operatorChild->getLeft() == NULL) {
            operatorChild->setLeft(other.getRoot());
        } else {
            operatorChild->setRight(other.getRoot());
        }
    } else {
        addSubtree(root, other.root);
    }
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


std::string CTree::printNormalExpression() {
    return inOrderTraversal(root);
}


CTree::CTree(CPreprocessExpression *newPreprocessExpression) {
    root = NULL;
    preprocessExpression = newPreprocessExpression;
}


void CTree::buildTree() {
    const std::vector<std::string> &elements = preprocessExpression->getElements();
    int i = 0;
    root = buildSubtree(elements, i);
}

CNode *CTree::buildSubtree(const std::vector<std::string> &elements, int &i) {
    if (i >= elements.size()) {
        return NULL;
    }

    const std::string &value = elements[i];
    ++i;

    if (CPreprocessExpression::isFunction(value)) {
        return new CNode(value, NULL, buildSubtree(elements, i), NULL);
    } else if (CPreprocessExpression::isOperator(value)) {
        CNode *node = new CNode(value, buildSubtree(elements, i), buildSubtree(elements, i), NULL);
        return node;
    } else {
        return new CNode(value, NULL, NULL, NULL);
    }
}


CNode *CTree::getRoot() const {
    return root;
}

void CTree::setRoot(CNode *cNodeRoot) {
    root = cNodeRoot;
}

CNode *CTree::searchForOperatorChild(CNode *currentNode) {
    if (currentNode == NULL) {
        return NULL;
    }

    if (CPreprocessExpression::isOperator(currentNode->getValue())) {
        if (currentNode->left == NULL && currentNode->right != NULL ||
            currentNode->left != NULL && currentNode->right == NULL) {
            return currentNode;
        }
    }

    CNode *leftResult = searchForOperatorChild(currentNode->left);
    if (leftResult != NULL) {
        return leftResult;
    }

    return searchForOperatorChild(currentNode->right);
}


void CTree::addSubtree(CNode *thisNode, CNode *otherNode) {
    if (otherNode == NULL) {
        return;
    }

    CNode *operatorChild = thisNode;

    while (operatorChild->left != NULL) {
        operatorChild = operatorChild->left;
    }

    operatorChild->setValue(otherNode->getValue());
    operatorChild->setLeft(otherNode->getLeft());
    operatorChild->setRight(otherNode->getRight());
}

std::string CTree::preOrderTraversal(CNode *startNode) {
    std::string result;
    if (startNode != NULL) {
        result += startNode->getValue() + " ";
        result += preOrderTraversal(startNode->getLeft());
        result += preOrderTraversal(startNode->getRight());
    }
    return result;
}

std::string CTree::print() {
    return preOrderTraversal(root);
}

std::string CTree::printVars() {
    return postOrderTraversal(root);
}

std::string CTree::postOrderTraversal(CNode *startNode) {
    std::string result;
    if (startNode != NULL) {
        result += postOrderTraversal(startNode->getLeft());
        result += postOrderTraversal(startNode->getRight());
        if (CPreprocessExpression::isVariable(startNode->getValue())) {
            result += startNode->getValue() + " ";
        }
    }
    return result;
}

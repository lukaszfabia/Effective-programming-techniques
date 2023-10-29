//
// Created by ufabi on 20.10.2023.
//

#include "CTree.h"
#include "Utilities/CTreesUtility.h"
#include "Utilities/CPreprocessExpression.h"

CTree::CTree() {
    root = NULL;
    preprocessExpression = NULL;
}

CTree::CTree(CPreprocessExpression *newPreprocessExpression) {
    root = NULL;
    preprocessExpression = newPreprocessExpression;
    buildTree();
}

CTree::~CTree() {
    delete root;
}

CTree &CTree::operator=(const CTree &other) {
    if (this == &other) {
        return *this;
    }

    setRoot(other.root);
    setPreprocessExpression(other.preprocessExpression);
    return *this;
}

CTree CTree::operator+(const CTree &other) const {
    CTree result; // Tworzymy nowe drzewo wynikowe

    if (getRoot() == NULL) {
        result = other;
    } else if (other.getRoot() == NULL) {
        result = *this;
    } else {
        //todo: problem z podpięciem drzewa do innego drzewa
    }

    return result;
}

std::string CTree::printNormalExpression() {
    return CTreesUtility::inOrderTraversal(root);
}

void CTree::buildTree() {
    const std::vector<std::string> &elements = preprocessExpression->getElements();
    int i = 0;
    root = CTreesUtility::buildSubtree(elements, i);
}

CNode *CTree::getRoot() const {
    return root;
}

void CTree::setRoot(CNode *cNodeRoot) {
    root = cNodeRoot;
}

std::string CTree::print() {
    return CTreesUtility::preOrderTraversal(root);
}

std::string CTree::printVars() {
    return CTreesUtility::postOrderTraversal(root);
}

void CTree::setPreprocessExpression(CPreprocessExpression *pExpression) {
    preprocessExpression = pExpression;
    buildTree();
}

std::string CTree::printLevels() {
    return CTreesUtility::levelOrderTraversal(root);
}

CNode *CTree::getOperatorChild() const {
    return CTreesUtility::searchForOperatorChild(getRoot());
}

CPreprocessExpression *CTree::getPreprocessExpression() const {
    return preprocessExpression;
}

//
// Created by ufabi on 20.10.2023.
//

#include "CTree.h"
#include "Utilities/CTreesUtility.h"
#include "Utilities/CPreprocessExpression.h"

CTree::CTree() {
    root = NULL;
    elements = std::vector<std::string>();
}

CTree::CTree(const std::vector<std::string> &newElements) {
    root = NULL;
    elements = newElements;
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
    elements = other.elements;
    values = other.values;
    buildTree();
    return *this;
}

CTree& CTree::operator+(const CTree &other) const {
    CTree* result = new CTree();
    result->elements.insert(result->elements.end(), elements.begin(), elements.end()-1);
    result->elements.insert(result->elements.end(), other.elements.begin(), other.elements.end());
    return *result;
}

std::string CTree::printNormalExpression() {
    return CTreesUtility::inOrderTraversal(root);
}

void CTree::buildTree() {
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

void CTree::setValues(const std::map<std::string, int> &valuesMap) {
    values = valuesMap;
}

std::string CTree::printLevels() {
    return CTreesUtility::levelOrderTraversal(root);
}

CNode *CTree::getOperatorChild() const {
    return CTreesUtility::searchForOperatorChild(getRoot());
}

double CTree::calculate() {
    return CTreesUtility::getValueOfExpression(root, values, 0);
}

void CTree::setElements(const std::vector<std::string> &newElements) {
    elements = newElements;
    buildTree();
}

std::vector<std::string> CTree::getElements() const {
    return elements;
}
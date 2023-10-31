//
// Created by ufabi on 29.10.2023.
//

#include "CTreesUtility.h"
#include "CPreprocessExpression.h"
#include <queue>

std::string CTreesUtility::inOrderTraversal(CNode *startNode) {
    std::string result;
    if (startNode != NULL) {
        result += inOrderTraversal(startNode->getLeft());
        result += startNode->getValue() + " ";
        result += inOrderTraversal(startNode->getRight());
    }
    return result;
}

std::string CTreesUtility::preOrderTraversal(CNode *startNode) {
    std::string result;
    if (startNode != NULL) {
        result += startNode->getValue() + " ";
        result += preOrderTraversal(startNode->getLeft());
        result += preOrderTraversal(startNode->getRight());
    }
    return result;
}

std::string CTreesUtility::postOrderTraversal(CNode *startNode) {
    std::string result;
    if (startNode != NULL) {
        result += postOrderTraversal(startNode->getLeft());
        result += postOrderTraversal(startNode->getRight());
        if (CPreprocessExpression::isVariable(startNode->getValue())) {
            result += startNode->getValue() + " ";
            amountOfVariables++;
        }
    }
    return result;
}

std::string CTreesUtility::levelOrderTraversal(CNode *startNode) {
    std::string result;
    if (startNode != NULL) {
        std::queue<CNode *> queue;
        queue.push(startNode);
        while (!queue.empty()) {
            CNode *currentNode = queue.front();
            queue.pop();
            result += currentNode->getValue() + " ";
            if (currentNode->getLeft() != NULL) {
                queue.push(currentNode->getLeft());
            }
            if (currentNode->getRight() != NULL) {
                queue.push(currentNode->getRight());
            }
        }
    }
    return result;
}

CNode *CTreesUtility::buildSubtree(const std::vector<std::string> &elements, int &i) {
    if (i >= elements.size()) {
        return NULL;
    }

    const std::string &value = elements[i];
    ++i;

    if (CPreprocessExpression::isFunction(value)) {
        return new CNode(value, NULL, buildSubtree(elements, i));
    } else if (CPreprocessExpression::isOperator(value)) {
        CNode *node = new CNode(value, buildSubtree(elements, i), buildSubtree(elements, i));
        return node;
    } else {
        return new CNode(value, NULL, NULL);
    }
}

CNode *CTreesUtility::searchForOperatorChild(CNode *currentNode) {
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

CTree &CTreesUtility::addSubtree(const CTree &tree, const CTree &subtree) {
    CNode *operatorChild = searchForOperatorChild(tree.getRoot());

    return const_cast<CTree &>(tree);
}

double CTreesUtility::getValueOfExpression(CNode *currentNode, const std::vector<int> &values, double result) {
    if (currentNode != NULL) {
        if (CPreprocessExpression::isOperator(currentNode->getValue())) {
            if (currentNode->getValue() == "+") {
                result = getValueOfExpression(currentNode->getLeft(), values, result) +
                         getValueOfExpression(currentNode->getRight(), values, result);
            } else if (currentNode->getValue() == "-") {
                result = getValueOfExpression(currentNode->getLeft(), values, result) -
                         getValueOfExpression(currentNode->getRight(), values, result);
            } else if (currentNode->getValue() == "*") {
                result = getValueOfExpression(currentNode->getLeft(), values, result) *
                         getValueOfExpression(currentNode->getRight(), values, result);
            } else if (currentNode->getValue() == "/") {
                result = getValueOfExpression(currentNode->getLeft(), values, result) /
                         getValueOfExpression(currentNode->getRight(), values, result);
            } else if (currentNode->getValue() == "sin") {
                result = sin(getValueOfExpression(currentNode->getRight(), values, result));
            } else if (currentNode->getValue() == "cos") {
                result = cos(getValueOfExpression(currentNode->getRight(), values, result));
            }
        } else if (CPreprocessExpression::isVariable(currentNode->getValue())) {
            if (iteratorForAmountOfVars<amountOfVariables){
                result = values[iteratorForAmountOfVars++];
            }
        } else {
            result = std::stod(currentNode->getValue());
        }
    }
    return result;
}




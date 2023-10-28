//
// Created by ufabi on 20.10.2023.
//

#include "CNode.h"

CNode::CNode() {
    value = "1";
    left = NULL;
    right = NULL;
    parent = NULL;
}

CNode::CNode(const std::string& newValue, CNode *newLeft, CNode *newRight, CNode *newParent) {
    value = newValue;
    left = newLeft;
    right = newRight;
    parent = newParent;
}

CNode::~CNode() {
    delete parent;
    delete left;
    delete right;
}

std::string CNode::getValue() const {
    return value;
}

CNode *CNode::getLeft() const {
    return left;
}

void CNode::setLeft(CNode *newLeft) {
    left = newLeft;
}

CNode *CNode::getRight() const {
    return right;
}

void CNode::setRight(CNode *newRight) {
    right = newRight;
}

void CNode::setValue(const std::string& newValue) {
    value = newValue;
}

CNode *CNode::getParent() const {
    return parent;
}

void CNode::setParent(CNode *newParent) {
    parent = newParent;
}
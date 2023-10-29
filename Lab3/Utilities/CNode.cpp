//
// Created by ufabi on 20.10.2023.
//

#include "CNode.h"

CNode::CNode() {
    value = "1";
    left = NULL;
    right = NULL;
//    parent = NULL;
}

CNode::CNode(const std::string &value, CNode *left, CNode *right) {
    this->value = value;
    this->left = left;
    this->right = right;
}

CNode::~CNode() {
//    delete parent;
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

void CNode::setValue(const std::string &newValue) {
    value = newValue;
}

//CNode *CNode::getParent() const {
//    return parent;
//}
//
//void CNode::setParent(CNode *newParent) {
//    parent = newParent;
//}
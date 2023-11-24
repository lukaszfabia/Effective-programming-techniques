//
// Created by ufabi on 24.11.2023.
//
#include "Node.h"

Node::Node(double value, Node *left, Node *right, Operator op, Type type, const std::string &newVariable) {
    this->value = value;
    this->left = left;
    this->right = right;
    this->op = op;
    this->type = type;
    this->variable = newVariable;
}

Node::~Node() {
    delete left;
    delete right;
}

double Node::getValue() const {
    return value;
}

Node *Node::getLeft() const {
    return left;
}

Node *Node::getRight() const {
    return right;
}

char Node::getOp() const {
    return op;
}

Type Node::getType() const {
    return type;
}

std::string Node::getVariable() const {
    return variable;
}
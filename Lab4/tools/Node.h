//
// Created by ufabi on 18.11.2023.
//

#ifndef EFFECTIVE_PROGRAMMING_TECHNIQUES_NODE_H
#define EFFECTIVE_PROGRAMMING_TECHNIQUES_NODE_H


#include "Operators.h"

template<typename T>
class Node {
public:

    Node();

    explicit Node(const T &newValue);

    Node(const Operator &anOperator, Node *newLeft, Node *newRight);

    explicit Node(const std::string &varName);

    ~Node();

    T getValue() const;

    void setValue(const T &newValue);

    Node *getLeft() const;

    void setLeft(Node *left);

    Node *getRight() const;

    void setRight(Node *newRight);

    Operator getOp() const;

    void setOp(Operator anOperator);

    const std::string &getVarName() const;

    void setVarName(const std::string &varName);

private:
    T value;
    Node<T> *left;
    Node<T> *right;
    Operator op;
    std::string varName;
};

template<typename T>
Node<T>::Node(const Operator &anOperator, Node *newLeft, Node *newRight) {
    value = T();
    left = newLeft;
    right = newRight;
    op = anOperator;
    varName = "";
} // dla operatorow

template<typename T>
Node<T>::Node(const T &value) {
    this->value = value;
    this->left = NULL;
    this->right = NULL;
    op = UNDEFINED;
    varName = "";
} // dla wartosci

template<typename T>
Node<T>::Node(const std::string &varName) {
    this->varName = varName;
    this->left = NULL;
    this->right = NULL;
    op = UNDEFINED;
    value = T();
} // dla zmiennych

template<typename T>
Node<T>::Node() {
    value = T();
    left = NULL;
    right = NULL;
    op = UNDEFINED;
} // pusty

template<typename T>
Node<T>::~Node() {
    delete left;
    delete right;
}

template<typename T>
T Node<T>::getValue() const {
    return value;
}

template<typename T>
void Node<T>::setValue(const T &newValue) {
    value = newValue;
}

template<typename T>
Node<T> *Node<T>::getLeft() const {
    return left;
}

template<typename T>
void Node<T>::setLeft(Node *newLeft) {
    left = newLeft;
}

template<typename T>
Node<T> *Node<T>::getRight() const {
    return right;
}

template<typename T>
void Node<T>::setRight(Node *newRight) {
    right = newRight;
}

template<typename T>
Operator Node<T>::getOp() const {
    return op;
}

template<typename T>
void Node<T>::setOp(Operator anOperator) {
    op = anOperator;
}

template<typename T>
const std::string &Node<T>::getVarName() const {
    return varName;
}

template<typename T>
void Node<T>::setVarName(const std::string &newVarName) {
    varName = newVarName;
}

#endif //EFFECTIVE_PROGRAMMING_TECHNIQUES_NODE_H

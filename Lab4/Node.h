//
// Created by ufabi on 19.11.2023.
//

#ifndef TEMPLATES_NODE_H
#define TEMPLATES_NODE_H

#include <cstddef>
#include <string>
#include "Operators.h"
#include "Type.h"

template<class T>
class Node {
private:
    T value;
    Node<T> *left;
    Node<T> *right;
    Operator op;
    Type type;
    std::string variable;
public:

    Node(T value, Node<T> *left, Node<T> *right, Operator op, Type type, const std::string &newVariable) : value(value),
                                                                                                           left(left),
                                                                                                           right(right),
                                                                                                           op(op),
                                                                                                           type(type),
                                                                                                           variable(
                                                                                                                   newVariable) {};

    T getValue() const {
        return value;
    }

    Node<T> *getLeft() const {
        return left;
    }

    Node<T> *getRight() const {
        return right;
    }

    char getOp() const {
        return op;
    }

    Type getType() const {
        return type;
    }

    std::string getVariable() const {
        return variable;
    }

    void setValue(T newValue) {
        this->value = newValue;
    }

    void setLeft(Node<T> *newLeft) {
        this->left = newLeft;
    }

    void setRight(Node<T> *newRight) {
        this->right = newRight;
    }

    void setOp(Operator anOperator) {
        this->op = anOperator;
    }

    void setType(Type newType) {
        this->type = newType;
    }

    void setVariable(const std::string &newVariable) {
        this->variable = newVariable;
    }

};


#endif //TEMPLATES_NODE_H

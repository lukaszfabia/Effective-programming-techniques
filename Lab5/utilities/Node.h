//
// Created by ufabi on 19.11.2023.
//

#ifndef TEMPLATES_NODE_H
#define TEMPLATES_NODE_H

#include <cstddef>
#include <string>
#include <utility>
#include "Operators.h"
#include "Type.h"

template<class T>
class Node {
private:
    T value;
//    Node<T> *left;
//    Node<T> *right;
    std::vector<Node<T> *> children;
    Operator op;
    Type type;
    std::string variable;
public:

    Node(T value, Node<T> *left, Node<T> *right, Operator op, Type type, std::string newVariable) : value(value),
                                                                                                    op(op),
                                                                                                    type(type),
                                                                                                    variable(std::move(
                                                                                                            newVariable)) {
        children.push_back(left);
        children.push_back(right);
    };

    Node(T value, Node<T> *mid, Operator op, Type type, std::string newVariable) : value(value),
                                                                                                    op(op),
                                                                                                    type(type),
                                                                                                    variable(std::move(
                                                                                                            newVariable)) {
        children.push_back(mid);
    };


    ~Node() {
        for (int i = 0; i < children.size(); ++i) {
            delete children[i];
        }
    }

    T getValue() const {
        return value;
    }

    Node<T> *getLeft() const {
        return children[0];
    }

    Node<T> *getRight() const {
        return children[1];
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
};

#endif //TEMPLATES_NODE_H

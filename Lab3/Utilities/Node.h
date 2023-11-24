//
// Created by ufabi on 19.11.2023.
//

#ifndef TEMPLATES_NODE_H
#define TEMPLATES_NODE_H

#include <cstddef>
#include <string>
#include "Operators.h"
#include "Type.h"


class Node {
private:
    double value;
    Node *left;
    Node *right;
    Operator op;
    Type type;
    std::string variable;
public:

    Node(double value, Node *left, Node *right, Operator op, Type type, const std::string &newVariable);

    ~Node();

    double getValue() const;

    Node *getLeft() const;

    Node *getRight() const;

    char getOp() const;

    Type getType() const;

    std::string getVariable() const;
};

#endif //TEMPLATES_NODE_H

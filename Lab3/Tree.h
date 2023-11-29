//
// Created by ufabi on 21.11.2023.
//

#include <string>
#include <iostream>
#include <vector>
#include <map>
#include "utilities/Node.h"
#include "utilities/Tools.h"

#ifndef TREE_TREE_H
#define DIV_ERROR "Division by zero"
#define ZERO 0
#define EMPTY ""
#define SPACE " "
#define SINUS "sin"
#define COSINUS "cos"
#define NEW_LANE "\n"
#define TREE_TREE_H


class Tree {
private:
    Node *root;
    std::vector<std::string> elements;
    std::map<std::string, double> values;

    Node *build(const std::vector<std::string> &vector, int &index);

    std::string inorder(Node *node);

    std::string preorder(Node *node);

    std::string postorder(Node *node);

    double eval(Node *current, double result);

public:
    Tree();

    explicit Tree(const std::vector<std::string> &expression);

    ~Tree();

    void setMap(const std::map<std::string, double> &newValues);

    Tree &operator=(const Tree &tree);

    Tree operator+(const Tree &other);

    std::string print();

    std::string norm();

    std::string vars();

    double comp();

    void set(const std::string &oldElement, const std::string &newElement);

    std::string printLevels();
};


#endif //TREE_TREE_H

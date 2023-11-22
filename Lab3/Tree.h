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
#define QUOTE "\""
#define TREE_TREE_H


class Tree {
private:
    Node<double> *root;
    std::vector<std::string> elements;
    std::map<std::string, double> values;

    Node<double> *build(const std::vector<std::string> &vector, int &index);

    std::string inorder(Node<double> *node);

    std::string preorder(Node<double> *node);

    std::string postorder(Node<double> *node);

    double eval(Node<double> *current, double result);

public:
    Tree() : root(NULL) {};

    explicit Tree(const std::vector<std::string> &expression) {
        int index = 0;
        root = build(expression, index);
    }

    ~Tree() {
        values.clear();
        elements.clear();
        delete root;
    }

    void setMap(const std::map<std::string, double> &newValues) {
        values = newValues;
    }

    Tree &operator=(const Tree &tree) {
        if (this != &tree) {
            delete root;
            values = tree.values;
            int index = 0;
            root = build(tree.elements, index);
        }
        return *this;
    }

    Tree operator+(const Tree &other) {
        Tree result;
        result.elements.insert(result.elements.end(), elements.begin(), elements.end() - 1);
        result.elements.insert(result.elements.end(), other.elements.begin(), other.elements.end());
        return result;
    }

    std::string print() {
        return preorder(root);
    }

    std::string norm() {
        return inorder(root);
    }

    std::string vars() {
        return Tools::removeDuplicates(postorder(root));
    }

    double comp() {
        return eval(root, 0);
    }
};


#endif //TREE_TREE_H

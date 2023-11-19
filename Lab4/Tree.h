//
// Created by ufabi on 19.11.2023.
//

#ifndef TEMPLATES_TREE_H
#define DIV_ERROR "Division by zero"
#define TEMPLATES_TREE_H

#include <cmath>
#include <vector>
#include <sstream>
#include <iostream>
#include "Node.h"
#include "Tools.h"


template<class T>
class Tree {
private:
    Node<T> *root;
    std::vector<std::string> elements;
    std::map<std::string, T> values;

    Node<T> *build(const std::vector<std::string> &vector, int &index);

    std::string inorder(Node<T> *node);

    std::string preorder(Node<T> *node);

    std::string postorder(Node<T> *node);

    T eval(Node<T> *node, T result);

public:
    Tree() : root(NULL) {};

    explicit Tree(const std::vector<std::string> &expression) {
        int index = 0;
        elements = expression;
        root = build(elements, index);
    }

    ~Tree() {
        delete root;
    }

    void setMap(const std::map<std::string, T> &newValues) {
        values = newValues;
    }

    Tree &operator=(const Tree &tree) {
        if (this != &tree) {
            delete root;
            values = tree.values;
            elements = tree.elements;
            int index = 0;
            root = build(elements, index);
        }
        return *this;
    }

    Tree operator+(const Tree &other) {
        Tree<T> result;
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
        return Tools<T>::removeDuplicates(postorder(root));
    }

    T comp() {
        return eval(root, T());
    }
};

template<>
double Tree<double>::eval(Node<double> *current, double result) {
    double right;
    if (current != NULL) {
        if (current->getType() == OPERATOR) {
            switch (current->getOp()) {
                case ADD:
                    return eval(current->getLeft(), result) + eval(current->getRight(), result);
                case SUBTRACT:
                    return eval(current->getLeft(), result) - eval(current->getRight(), result);
                case MULTIPLY:
                    return eval(current->getLeft(), result) * eval(current->getRight(), result);
                case DIVIDE:
                    right = eval(current->getRight(), result);
                    if (right == 0.0) {
                        std::cout << DIV_ERROR << std::endl;
                        return INT_MAX;
                    }
                    return eval(current->getLeft(), result) / right;
                case SIN:
                    return sin(eval(current->getRight(), result));
                case COS:
                    return cos(eval(current->getRight(), result));
                default:
                    break;
            }
        } else if (Tools<double>::isVariable(current->getVariable())) {
            typename std::map<std::string, double>::iterator it = values.find(current->getVariable());
            for (it = values.begin(); it != values.end(); it++) {
                if (it->first == current->getVariable()) {
                    result = it->second;
                    break;
                }
            }
        } else {
            return current->getValue();
        }
    }
    return result;
}

template<>
std::string Tree<std::string>::eval(Node<std::string> *current, std::string result) {
    std::string left, right;
    if (current != NULL) {
        if (current->getType() == OPERATOR) {
            switch (current->getOp()) {
                case ADD:
                    return "\""+Tools<std::string>::removeQuote(eval(current->getLeft(), result)) +
                           Tools<std::string>::removeQuote(eval(current->getRight(), result)) + "\"";
                case SUBTRACT:
                    return Tools<std::string>::substract(
                            Tools<std::string>::removeQuote(eval(current->getLeft(), result)),
                            Tools<std::string>::removeQuote(eval(current->getRight(), result)));
                case MULTIPLY:
                    return Tools<std::string>::multiply(
                            Tools<std::string>::removeQuote(eval(current->getLeft(), result)),
                            Tools<std::string>::removeQuote(eval(current->getRight(), result)));
                case DIVIDE:
                    return Tools<std::string>::divide(Tools<std::string>::removeQuote(eval(current->getLeft(), result)),
                                                      Tools<std::string>::removeQuote(
                                                              eval(current->getRight(), result)));
                default:
                    break;
            }
        } else if (current->getType() == VARIABLE) {
            typename std::map<std::string, std::string>::iterator it = values.find(current->getVariable());
            for (it = values.begin(); it != values.end(); it++) {
                if (it->first == current->getVariable()) {
                    result = it->second;
                    break;
                }
            }
        } else {
            return current->getValue();
        }
    }
    return result;
}

template<>
int Tree<int>::eval(Node<int> *current, int result) {
    int right;
    if (current != NULL) {
        if (current->getType() == OPERATOR) {
            switch (current->getOp()) {
                case ADD:
                    return eval(current->getLeft(), result) + eval(current->getRight(), result);
                case SUBTRACT:
                    return eval(current->getLeft(), result) - eval(current->getRight(), result);
                case MULTIPLY:
                    return eval(current->getLeft(), result) * eval(current->getRight(), result);
                case DIVIDE:
                    right = eval(current->getRight(), result);
                    if (right == 0) {
                        std::cout << DIV_ERROR << std::endl;
                        return INT_MAX;
                    }
                    return static_cast<int>(eval(current->getLeft(), result) / right);
                case SIN:
                    return static_cast<int>(sin(eval(current->getRight(), result)));
                case COS:
                    return static_cast<int>(cos(eval(current->getRight(), result)));
                default:
                    break;
            }
        } else if (current->getType() == VARIABLE) {
            typename std::map<std::string, int>::iterator it = values.find(current->getVariable());
            for (it = values.begin(); it != values.end(); it++) {
                if (it->first == current->getVariable()) {
                    result = it->second;
                    break;
                }
            }
        } else {
            return current->getValue();
        }
    }
    return result;
}

template<class T>
std::string Tree<T>::inorder(Node<T> *node) {
    std::string result;
    if (node != NULL) {
        result += inorder(node->getLeft());
        if (node->getType() == OPERATOR) {
            if (node->getOp() == SIN) {
                result += "sin ";
            } else if (node->getOp() == COS) {
                result += "cos ";
            } else {
                std::ostringstream oss;
                oss << node->getOp();
                result += oss.str() + " ";
            }
        } else if (node->getType() == VALUE) {
            std::ostringstream oss;
            oss << node->getValue();
            result += oss.str() + " ";
        } else if (node->getType() == VARIABLE) {
            result += node->getVariable() + " ";
        }
        result += inorder(node->getRight());
    }
    return result;
}

template<class T>
std::string Tree<T>::preorder(Node<T> *node) {
    std::string result;
    if (node != NULL) {
        if (node->getType() == OPERATOR) {
            if (node->getOp() == SIN) {
                result += "sin ";
            } else if (node->getOp() == COS) {
                result += "cos ";
            } else {
                std::ostringstream oss;
                oss << node->getOp();
                result += oss.str() + " ";
            }
        } else if (node->getType() == VALUE) {
            std::ostringstream oss;
            oss << node->getValue();
            result += oss.str() + " ";
        } else if (node->getType() == VARIABLE) {
            result += node->getVariable() + " ";
        }
        result += preorder(node->getLeft());
        result += preorder(node->getRight());
    }
    return result;
}

template<class T>
std::string Tree<T>::postorder(Node<T> *node) {
    std::string result;
    if (node != NULL) {
        result += postorder(node->getLeft());
        result += postorder(node->getRight());
        if (node->getType() == VARIABLE) {
            result += node->getVariable() + " ";
        }
    }
    return result;
}

template<class T>
Node<T> *Tree<T>::build(const std::vector<std::string> &vector, int &index) {
    if (index >= vector.size()) {
        return NULL;
    }

    const std::string &token = vector[index];
    ++index;

    if (Tools<T>::isFunction(token)) {
        return token == "sin" ? new Node<T>(T(), NULL, build(vector, index), SIN, OPERATOR, "") : new Node<T>(T(),
                                                                                                              NULL,
                                                                                                              build(vector,
                                                                                                                    index),
                                                                                                              COS,
                                                                                                              OPERATOR,
                                                                                                              "");
    } else if (Tools<T>::isOperator(token)) {
        switch (token[0]) {
            case ADD:
                return new Node<T>(T(), build(vector, index), build(vector, index), ADD, OPERATOR, "");
            case SUBTRACT:
                return new Node<T>(T(), build(vector, index), build(vector, index), SUBTRACT, OPERATOR, "");
            case MULTIPLY:
                return new Node<T>(T(), build(vector, index), build(vector, index), MULTIPLY, OPERATOR, "");
            case DIVIDE:
                return new Node<T>(T(), build(vector, index), build(vector, index), DIVIDE, OPERATOR, "");
            default:
                return NULL;
        }
    } else if (Tools<T>::isVariable(token)) {
        return new Node<T>(T(), NULL, NULL, UNDEFINED, VARIABLE, token);
    } else {
        std::istringstream iss(token);
        T value;
        iss >> value;
        return new Node<T>(value, NULL, NULL, UNDEFINED, VALUE, "");
    }
}

#endif //TEMPLATES_TREE_H

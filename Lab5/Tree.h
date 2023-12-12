//
// Created by ufabi on 19.11.2023.
//

#ifndef TEMPLATES_TREE_H
#define DIV_ERROR "Division by zero"
#define ZERO 0
#define EMPTY ""
#define SPACE " "
#define SINUS "sin"
#define COSINUS "cos"
#define QUOTE "\""
#define TEMPLATES_TREE_H

#include <cmath>
#include <vector>
#include <sstream>
#include <iostream>
#include "utilities/Node.h"
#include "utilities/Tools.h"


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
    Tree() : root(nullptr) {}

    explicit Tree(const std::vector<std::string> &expression) {
        int index = 0;
        root = build(expression, index);
    }

    Tree(Tree &&tree) noexcept: root(tree.root), values(std::move(tree.values)), elements(std::move(tree.elements)) {
        tree.root = nullptr;
    }

    ~Tree() {
        values.clear();
        elements.clear();
        delete root;
    }

    void setMap(const std::map<std::string, T> &newValues) {
        values = newValues;
    }

    Tree &operator=(Tree &&tree) noexcept {
        if (this != &tree) {
            delete root;
            tree.root = nullptr;
            values = std::move(tree.values);
            elements.clear();
            int index = 0;
            root = build(std::move(tree.elements), index);
            // 2 kopie mniej chyba
        }
        return *this;
    }

    Tree operator+(const Tree &other) const {
        Tree<T> result;
        result.elements = elements;
        result.elements.pop_back();
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
    if (current != nullptr) {
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
                    if (right == ZERO) {
                        std::cout << DIV_ERROR << std::endl;
                        return INT_MAX;
                    }
                    return eval(current->getLeft(), result) / right;
                case SIN:
                    return sin(eval(current->getRight(), result));
                case COS:
                    return cos(eval(current->getRight(), result));
                default:
                    return ZERO;
            }
        } else if (current->getType() == VARIABLE) {
            std::map<std::string, double>::iterator it = values.find(current->getVariable());
            for (it = values.begin(); it != values.end(); it++) {
                if (it->first == current->getVariable()) {
                    result = it->second;
                    return result;
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
    if (current != nullptr) {
        if (current->getType() == OPERATOR) {
            switch (current->getOp()) {
                case ADD:
                    return QUOTE + REMOVE_QUOTE(eval(current->getLeft(), result))
                           +
                           REMOVE_QUOTE(eval(current->getRight(), result))
                           + QUOTE;
                case SUBTRACT:
                    return Tools<std::string>::substract(
                            REMOVE_QUOTE(eval(current->getLeft(), result)),
                            REMOVE_QUOTE(eval(current->getRight(), result)));
                case MULTIPLY:
                    return Tools<std::string>::multiply(
                            REMOVE_QUOTE(eval(current->getLeft(), result)),
                            REMOVE_QUOTE(eval(current->getRight(), result)));
                case DIVIDE:
                    return Tools<std::string>::divide(REMOVE_QUOTE(eval(current->getLeft(), result)),
                                                      REMOVE_QUOTE(
                                                              eval(current->getRight(), result)));
                default:
                    return EMPTY;
            }
        } else if (current->getType() == VARIABLE) {
            std::map<std::string, std::string>::iterator it = values.find(current->getVariable());
            for (it = values.begin(); it != values.end(); it++) {
                if (it->first == current->getVariable()) {
                    result = it->second;
                    return result;
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
    if (current != nullptr) {
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
                    return ZERO;
            }
        } else if (current->getType() == VARIABLE) {
            std::map<std::string, int>::iterator it = values.find(current->getVariable());
            for (it = values.begin(); it != values.end(); it++) {
                if (it->first == current->getVariable()) {
                    result = it->second;
                    return result;
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
    std::ostringstream oss;
    if (node != nullptr) {
        result += inorder(node->getLeft());
        if (node->getType() == OPERATOR) {
            if (node->getOp() == SIN) {
                result += SINUS;
                result += SPACE;
            } else if (node->getOp() == COS) {
                result += COSINUS;
                result += SPACE;
            } else {
                oss << node->getOp();
                result += oss.str() + SPACE;
            }
        } else if (node->getType() == VALUE) {
            oss << node->getValue();
            result += oss.str() + SPACE;
        } else if (node->getType() == VARIABLE) {
            result += node->getVariable() + SPACE;
        }
        result += inorder(node->getRight());
    }
    return result;
}

template<class T>
std::string Tree<T>::preorder(Node<T> *node) {
    std::ostringstream oss;
    std::string result;
    if (node != nullptr) {
        if (node->getType() == OPERATOR) {
            if (node->getOp() == SIN) {
                result += SINUS;
                result += SPACE;
            } else if (node->getOp() == COS) {
                result += COSINUS;
                result += SPACE;
            } else {
                oss << node->getOp();
                result += oss.str() + SPACE;
            }
        } else if (node->getType() == VALUE) {
            oss << node->getValue();
            result += oss.str() + SPACE;
        } else if (node->getType() == VARIABLE) {
            result += node->getVariable() + SPACE;
        }
        result += preorder(node->getLeft());
        result += preorder(node->getRight());
    }
    return result;
}

template<class T>
std::string Tree<T>::postorder(Node<T> *node) {
    std::string result;
    if (node != nullptr) {
        result += postorder(node->getLeft());
        result += postorder(node->getRight());
        if (node->getType() == VARIABLE) {
            result += node->getVariable() + SPACE;
        }
    }
    return result;
}

template<class T>
Node<T> *Tree<T>::build(const std::vector<std::string> &vector, int &index) {
    if (index >= vector.size()) {
        return nullptr;
    }

    const std::string &token = vector[index];
    ++index;

    if (IS_FUNCTION(token)) {
        elements.push_back(token);
        Node<T> *middleChild = build(vector, index);
        if (middleChild == nullptr) {
            elements.emplace_back(FILL);
            middleChild = new Node<T>(T(), nullptr, nullptr, UNDEFINED, VARIABLE, FILL);
        }

        return token == SINUS ? new Node<T>(T(), middleChild, SIN, OPERATOR, EMPTY)
                              : new Node<T>(T(),
                                            middleChild,
                                            COS,
                                            OPERATOR,
                                            EMPTY);
    } else if (IS_OPERATOR(token)) {
        elements.push_back(token);
        Node<T> *leftChild = build(vector, index);
        Node<T> *rightChild = build(vector, index);


        if (leftChild == nullptr) {
            elements.emplace_back(FILL);
            leftChild = new Node<T>(T(), nullptr, nullptr, UNDEFINED, VARIABLE, FILL);
        }

        if (rightChild == nullptr) {
            elements.emplace_back(FILL);
            rightChild = new Node<T>(T(), nullptr, nullptr, UNDEFINED, VARIABLE, FILL);
        }

        return new Node<T>(T(), leftChild, rightChild, static_cast<Operator>(token[0]), OPERATOR, EMPTY);
    } else if (IS_VARIABLE(token)) {
        elements.push_back(token);
        return new Node<T>(T(), nullptr, nullptr, UNDEFINED, VARIABLE, token);
    } else {
        elements.push_back(token);
        std::istringstream iss(token);
        T value;
        iss >> value;
        return new Node<T>(value, nullptr, nullptr, UNDEFINED, VALUE, EMPTY);
    }
}

#endif //TEMPLATES_TREE_H

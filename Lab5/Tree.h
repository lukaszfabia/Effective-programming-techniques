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
#include "utilities/OperatorNode.h"
#include "utilities/ValueNode.h"

#include "utilities/VariableNode.h"


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

    virtual T eval(Node<T> *node, T result);

public:
    Tree() : root(nullptr) {}

    explicit Tree(const std::vector<std::string> &expression) {
        int index = 0;
        root = build(expression, index);
    }

    Tree(Tree &&tree) noexcept: root(tree.root), values(std::move(tree.values)), elements(std::move(tree.elements)) {
        tree.root = nullptr;
    }

    virtual ~Tree() {
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
        if (OperatorNode<double> *opNode = dynamic_cast<OperatorNode<double> *>(current)) {
            switch (opNode->getOperator()) {
                case Add:
                    return eval(opNode->getLeft(), result) + eval(opNode->getRight(), result);
                case Sub:
                    return eval(opNode->getLeft(), result) - eval(opNode->getRight(), result);
                case Mul:
                    return eval(opNode->getLeft(), result) * eval(opNode->getRight(), result);
                case Div:
                    right = eval(opNode->getRight(), result);
                    if (right == ZERO) {
                        std::cout << DIV_ERROR << std::endl;
                        return INT_MAX;
                    }
                    return eval(opNode->getLeft(), result) / right;
                case Sin:
                    return sin(eval(opNode->getRight(), result));
                case Cos:
                    return cos(eval(opNode->getRight(), result));
                default:
                    return ZERO;
            }
        } else if (VariableNode<double> *varNode = dynamic_cast<VariableNode<double> *>(current)) {
            std::map<std::string, double>::iterator it = values.find(varNode->getVariable());
            for (it = values.begin(); it != values.end(); it++) {
                if (it->first == varNode->getVariable()) {
                    result = it->second;
                    return result;
                }
            }
        } else if (ValueNode<double> *valNode = dynamic_cast<ValueNode<double> *>(current)) {
            return valNode->getValue();
        }
    }
    return result;
}

template<>
std::string Tree<std::string>::eval(Node<std::string> *current, std::string result) {
    std::string left, right;
    if (current != nullptr) {
        if (OperatorNode<std::string> *opNode = dynamic_cast<OperatorNode<std::string> *>(current)) {
            switch (opNode->getOperator()) {
                case Add:
                    return QUOTE + REMOVE_QUOTE(eval(current->getLeft(), result))
                           +
                           REMOVE_QUOTE(eval(current->getRight(), result))
                           + QUOTE;
                case Sub:
                    return Tools<std::string>::substract(
                            REMOVE_QUOTE(eval(current->getLeft(), result)),
                            REMOVE_QUOTE(eval(current->getRight(), result)));
                case Mul:
                    return Tools<std::string>::multiply(
                            REMOVE_QUOTE(eval(current->getLeft(), result)),
                            REMOVE_QUOTE(eval(current->getRight(), result)));
                case Div:
                    return Tools<std::string>::divide(REMOVE_QUOTE(eval(current->getLeft(), result)),
                                                      REMOVE_QUOTE(
                                                              eval(current->getRight(), result)));
                default:
                    return EMPTY;
            }
        } else if (VariableNode<std::string> *varNode = dynamic_cast<VariableNode<std::string> *>(current)) {
            std::map<std::string, std::string>::iterator it = values.find(varNode->getVariable());
            for (it = values.begin(); it != values.end(); it++) {
                if (it->first == varNode->getVariable()) {
                    result = it->second;
                    return result;
                }
            }
        } else if (ValueNode<std::string> *valNode = dynamic_cast<ValueNode<std::string> *>(current)) {
            return valNode->getValue();
        }
    }
    return result;
}

template<>
int Tree<int>::eval(Node<int> *current, int result) {
    int right;
    if (current != nullptr) {
        if (OperatorNode<int> *opNode = dynamic_cast<OperatorNode<int> *>(current)) {
            switch (opNode->getOperator()) {
                case Add:
                    return eval(current->getLeft(), result) + eval(current->getRight(), result);
                case Sub:
                    return eval(current->getLeft(), result) - eval(current->getRight(), result);
                case Mul:
                    return eval(current->getLeft(), result) * eval(current->getRight(), result);
                case Div:
                    right = eval(current->getRight(), result);
                    if (right == 0) {
                        std::cout << DIV_ERROR << std::endl;
                        return INT_MAX;
                    }
                    return static_cast<int>(eval(current->getLeft(), result) / right);
                case Sin:
                    return static_cast<int>(sin(eval(current->getRight(), result)));
                case Cos:
                    return static_cast<int>(cos(eval(current->getRight(), result)));
                default:
                    return ZERO;
            }
        } else if (VariableNode<int> *varNode = dynamic_cast<VariableNode<int> *>(current)) {
            std::map<std::string, int>::iterator it = values.find(varNode->getVariable());
            for (it = values.begin(); it != values.end(); it++) {
                if (it->first == varNode->getVariable()) {
                    result = it->second;
                    return result;
                }
            }
        } else if (ValueNode<int> *valNode = dynamic_cast<ValueNode<int> *>(current)) {
            return valNode->getValue();
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
        if (OperatorNode<T> *opNode = dynamic_cast<OperatorNode<T> *>(node)) {
            if (opNode->getOperator() == Sin) {
                result += SINUS;
                result += SPACE;
            } else if (opNode->getOperator() == Cos) {
                result += COSINUS;
                result += SPACE;
            } else {
                oss << opNode->getOperator();
                result += oss.str() + SPACE;
            }
        } else if (ValueNode<T> *valNode = dynamic_cast<ValueNode<T> *>(node)) {
            oss << valNode->getValue();
            result += oss.str() + SPACE;
        } else if (VariableNode<T> *varNode = dynamic_cast<VariableNode<T> *>(node)) {
            result += varNode->getVariable() + SPACE;
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
        if (OperatorNode<T>* opNode = dynamic_cast<OperatorNode<T>*>(node)) {
            if (opNode->getOperator() == Sin) {
                result += SINUS;
                result += SPACE;
            } else if (opNode->getOperator() == Cos) {
                result += COSINUS;
                result += SPACE;
            } else {
                oss << opNode->getOperator();
                result += oss.str() + SPACE;
            }
        } else if (auto * valueNode = dynamic_cast<ValueNode<T>*>(node)) {
            oss << valueNode->getValue();
            result += oss.str() + SPACE;
        } else if (VariableNode<T>* varNode = dynamic_cast<VariableNode<T>*>(node)) {
            result += varNode->getVariable() + SPACE;
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
        if (VariableNode<T> *varNode = dynamic_cast<VariableNode<T> *>(node)) {
            result += varNode->getVariable() + SPACE;
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
            middleChild = new VariableNode<T>(nullptr, nullptr, FILL);
        }

        return token == SINUS ? new OperatorNode<T>(nullptr, middleChild, Sin)
                              : new OperatorNode<T>(nullptr, middleChild, Cos);

    } else if (IS_OPERATOR(token)) {
        elements.push_back(token);
        Node<T> *leftChild = build(vector, index);
        Node<T> *rightChild = build(vector, index);


        if (leftChild == nullptr) {
            elements.emplace_back(FILL);
            leftChild = new VariableNode<T>(nullptr, nullptr, FILL);
        }

        if (rightChild == nullptr) {
            elements.emplace_back(FILL);
            rightChild = new VariableNode<T>(nullptr, nullptr, FILL);
        }

        return new OperatorNode<T>(leftChild, rightChild, static_cast<Operator>(token[0]));
    } else if (IS_VARIABLE(token)) {
        elements.push_back(token);
        return new VariableNode<T>(nullptr, nullptr, token);
    } else {
        elements.push_back(token);
        std::istringstream iss(token);
        T value;
        iss >> value;
        return new ValueNode<T>(nullptr, nullptr, value);
    }
}

#endif //TEMPLATES_TREE_H

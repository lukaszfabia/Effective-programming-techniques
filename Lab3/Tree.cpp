//
// Created by ufabi on 21.11.2023.
//

#include <iostream>
#include <cmath>
#include "Tree.h"
#include "utilities/Tools.h"
#include "utilities/Node.h"


Node<double> *Tree::build(const std::vector<std::string> &vector, int &index) {
    if (index >= vector.size()) {
        return NULL;
    }

    const std::string &token = vector[index];
    ++index;

    if (IS_FUNCTION(token)) {
        elements.push_back(token);
        Node<double> *rightChild = build(vector, index);
        if (rightChild == NULL) {
            elements.push_back(FILL);
            rightChild = new Node<double>(double(), NULL, NULL, UNDEFINED, VARIABLE, FILL);
        }

        return token == SINUS ? new Node<double>(double(), NULL, rightChild, SIN, OPERATOR, EMPTY)
                              : new Node<double>(double(),
                                                 NULL,
                                                 rightChild,
                                                 COS,
                                                 OPERATOR,
                                                 EMPTY);
    } else if (IS_OPERATOR(token)) {
        elements.push_back(token);
        Node<double> *leftChild = build(vector, index);
        Node<double> *rightChild = build(vector, index);

    
        if (leftChild == NULL) {
            elements.push_back(FILL);
            leftChild = new Node<double>(double(), NULL, NULL, UNDEFINED, VARIABLE, FILL);
        }

        if (rightChild == NULL) {
            elements.push_back(FILL);
            rightChild = new Node<double>(double(), NULL, NULL, UNDEFINED, VARIABLE, FILL);
        }

        return new Node<double>(double(), leftChild, rightChild, static_cast<Operator>(token[0]), OPERATOR, EMPTY);
    } else if (IS_VARIABLE(token)) {
        elements.push_back(token);
        return new Node<double>(double(), NULL, NULL, UNDEFINED, VARIABLE, token);
    } else {
        elements.push_back(token);
        std::istringstream iss(token);
        double value;
        iss >> value;
        return new Node<double>(value, NULL, NULL, UNDEFINED, VALUE, EMPTY);
    }
}

std::string Tree::inorder(Node<double> *node) {
    std::string result;
    std::ostringstream oss;
    if (node != NULL) {
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

std::string Tree::preorder(Node<double> *node) {
    std::ostringstream oss;
    std::string result;
    if (node != NULL) {
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

std::string Tree::postorder(Node<double> *node) {
    std::string result;
    if (node != NULL) {
        result += postorder(node->getLeft());
        result += postorder(node->getRight());
        if (node->getType() == VARIABLE) {
            result += node->getVariable() + SPACE;
        }
    }
    return result;
}

double Tree::eval(Node<double> *current, double result) {
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
            typename std::map<std::string, double>::iterator it = values.find(current->getVariable());
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


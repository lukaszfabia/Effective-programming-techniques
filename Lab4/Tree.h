//
// Created by ufabi on 18.11.2023.
//

#ifndef EFFECTIVE_PROGRAMMING_TECHNIQUES_TREE_H
#define EFFECTIVE_PROGRAMMING_TECHNIQUES_TREE_H


#include <string>
#include <vector>
#include <map>
#include "tools/Node.h"
#include "../Lab3/Utilities/CPreprocessExpression.h"
#include <valarray>
#include <sstream>

template<typename T>
class Tree {
private:
    Node<T> *root;
    std::vector<std::string> elements;
    std::map<std::string, T> values;

    std::string inorder(Node<T> *current);

    std::string postorder(Node<T> *current);

    std::string preorder(Node<T> *current);

public:
    Tree() {
        root = new Node<T>();
    }

    explicit Tree(const std::vector<std::string> &newElements) {
        elements = newElements;
        int i = 0;
        root = buildTree(i);
    }

    ~Tree() {
        delete root;
    }

    Tree &operator=(const Tree<T> &other);

    Tree operator+(const Tree<T> &other) const;

    std::string printVars();

    std::string printNormalExpression();

    Node<T> *getRoot() const;

    void setRoot(Node<T> *root);

    Node<T> *buildTree(int &i);

    std::string print();

    std::vector<std::string> getElements() const;

    void setElements(const std::vector<std::string> &newElements);

    void setValues(const std::map<std::string, T> &valuesMap);

};

template<typename T>
std::string Tree<T>::print() {
    return preorder(root);
}

template<typename T>
std::string Tree<T>::preorder(Node<T> *current) {
    std::string result;
    if (current != NULL) {
        if (current->getOp() != UNDEFINED) {
            if (current->getOp() == 's') {
                result += "sin ";
            } else if (current->getOp() == 'c') {
                result += "cos ";
            } else {
                std::ostringstream oss;
                oss << static_cast<char>(current->getOp());
                result += oss.str() + " ";
            }
        } else if (current->getValue() != T()) {
            std::ostringstream oss;
            oss << current->getValue();
            result += oss.str() + " ";
        } else if (!current->getVarName().empty()) {
            result += current->getVarName() + " ";
        }
        result += preorder(current->getLeft());
        result += preorder(current->getRight());
    }
    return result;
}

template<typename T>
Tree<T> &Tree<T>::operator=(const Tree<T> &other) {
    if (this != &other) {
        delete root;
        elements = other.elements;
        values = other.values;
        int i = 0;
        root = buildTree(i);
    }
    return *this;
}

template<typename T>
Tree<T> Tree<T>::operator+(const Tree<T> &other) const {
    Tree<T> result;
    result.elements.insert(result.elements.end(), elements.begin(), elements.end() - 1);
    result.elements.insert(result.elements.end(), other.elements.begin(), other.elements.end());
    return result;
}

/// post order traversal

template<typename T>
std::string Tree<T>::printVars() {
    return CPreprocessExpression::removeDuplicates(postorder(root));
}

template<typename T>
std::string Tree<T>::postorder(Node<T> *current) {
    std::string result;
    if (current != NULL) {
        result += postorder(current->getLeft());
        result += postorder(current->getRight());
        if (CPreprocessExpression::isVariable(current->getVarName()) &&
            !current->getVarName().empty() && !CPreprocessExpression::isString(current->getVarName())) {
            result += current->getVarName() + " ";
        }
    }
    return result;
}


/// inorder traversal

template<typename T>
std::string Tree<T>::printNormalExpression() {
    return inorder(root);
}

template<typename T>
std::string Tree<T>::inorder(Node<T> *current) {
    std::string result;
    if (current != NULL) {
        result += inorder(current->getLeft());
        if (current->getOp() != UNDEFINED) {
            if (current->getOp() == 's') {
                result += "sin ";
            } else if (current->getOp() == 'c') {
                result += "cos ";
            } else {
                std::ostringstream oss;
                oss << static_cast<char>(current->getOp());
                result += oss.str() + " ";
            }
        } else if (current->getValue() != T()) {
            std::ostringstream oss;
            oss << current->getValue();
            result += oss.str() + " ";
        } else if (!current->getVarName().empty()) {
            result += current->getVarName() + " ";
        }
        result += inorder(current->getRight());
    }
    return result;
}

/// build tree

template<typename T>
Node<T> *Tree<T>::buildTree(int &i) {
    if (i >= elements.size()) {
        return NULL;
    }

    const std::string &token = elements[i];
    ++i;

    if (CPreprocessExpression::isFunction(token)) {
        return token == "sin" ? new Node<T>(SIN, NULL, buildTree(i)) : new Node<T>(COS, NULL, buildTree(i));
    } else if (CPreprocessExpression::isOperator(token)) {
        switch (token[0]) {
            case '+':
                return new Node<T>(ADD, buildTree(i), buildTree(i));
            case '-':
                return new Node<T>(SUBTRACT, buildTree(i), buildTree(i));
            case '*':
                return new Node<T>(MULTIPLY, buildTree(i), buildTree(i));
            case '/':
                return new Node<T>(DIVIDE, buildTree(i), buildTree(i));
            default:
                return NULL;
        }
    } else if (CPreprocessExpression::isVariable(token) && !CPreprocessExpression::isString(token)) {
        return new Node<T>(token);
    } else {
        return new Node<T>(token);
    }
}


/// getters and setters

template<typename T>
void Tree<T>::setValues(const std::map<std::string, T> &valuesMap) {
    values = valuesMap;
}

template<typename T>
std::vector<std::string> Tree<T>::getElements() const {
    return elements;
}

template<typename T>
void Tree<T>::setElements(const std::vector<std::string> &newElements) {
    elements = newElements;
}

template<typename T>
Node<T> *Tree<T>::getRoot() const {
    return root;
}

template<typename T>
void Tree<T>::setRoot(Node<T> *newRoot) {
    root = newRoot;
}


#endif //EFFECTIVE_PROGRAMMING_TECHNIQUES_TREE_H

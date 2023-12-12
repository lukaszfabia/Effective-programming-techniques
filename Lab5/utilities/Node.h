//
// Created by ufabi on 19.11.2023.
//

#ifndef TEMPLATES_NODE_H
#define TEMPLATES_NODE_H

#include <string>
#include <utility>

template<class T>
class Node {
protected:
    Node<T>* left;
    Node<T>* right;

public:
    Node(Node<T>* leftNode, Node<T>* rightNode) : left(leftNode), right(rightNode) {}
    virtual ~Node() {
        delete left;
        delete right;
    }

    virtual Node<T>* getLeft() const {
        return left;
    }

    virtual Node<T>* getRight() const {
        return right;
    }
};


#endif //TEMPLATES_NODE_H

//
// Created by Lukasz Fabia on 02/01/2024.
//

#ifndef EFFECTIVE_PROGRAMMING_TECHNIQUES_VALUENODE_H
#define EFFECTIVE_PROGRAMMING_TECHNIQUES_VALUENODE_H

#include "Node.h"

template<class T>
class ValueNode : public Node<T> {
private:
    T value;

public:
    ValueNode(Node<T> *leftNode, Node<T> *rightNode, T newValue) : Node<T>(leftNode, rightNode),
                                                                          value(newValue) {}

    T getValue() {
        return this->value;
    }

};

#endif //EFFECTIVE_PROGRAMMING_TECHNIQUES_VALUENODE_H

//
// Created by Lukasz Fabia on 02/01/2024.
//

#ifndef EFFECTIVE_PROGRAMMING_TECHNIQUES_VARIABLENODE_H
#define EFFECTIVE_PROGRAMMING_TECHNIQUES_VARIABLENODE_H

#include "Node.h"

#include <utility>

template<class T>
class VariableNode : public Node<T> {
private:
    std::string variable;

public:
    VariableNode(Node<T> *leftNode, Node<T> *rightNode, std::string newVariable) : Node<T>(leftNode,
                                                                                        rightNode),
                                                                                variable(std::move(newVariable)) {}

    std::string getVariable() {
        return this->variable;
    }


};

#endif //EFFECTIVE_PROGRAMMING_TECHNIQUES_VARIABLENODE_H

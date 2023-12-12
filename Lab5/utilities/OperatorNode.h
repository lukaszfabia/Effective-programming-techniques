//
// Created by Lukasz Fabia on 02/01/2024.
//

#ifndef EFFECTIVE_PROGRAMMING_TECHNIQUES_OPERATORNODE_H
#define EFFECTIVE_PROGRAMMING_TECHNIQUES_OPERATORNODE_H


#include "Node.h"
#include "Operator.h"


template<class T>
class OperatorNode : public Node<T> {
private:
    Operator op;

public:
    OperatorNode(Node<T>* leftNode, Node<T>* rightNode, Operator anOperator) : Node<T>(leftNode, rightNode),
                                                                                          op(anOperator) {};

    char getOperator() {
        return this->op;
    }

};


#endif //EFFECTIVE_PROGRAMMING_TECHNIQUES_OPERATORNODE_H

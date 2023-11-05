//
// Created by ufabi on 20.10.2023.
//

#ifndef EFFECTIVE_PROGRAMMING_TECHNIQUES_CNODE_H
#define EFFECTIVE_PROGRAMMING_TECHNIQUES_CNODE_H


#include <string>

class CNode {
public:
    std::string value;
    CNode *left;
    CNode *right;

    CNode();

    CNode(const std::string &value, CNode *left, CNode *right);

    ~CNode();

    std::string getValue() const;

    void setValue(const std::string &value);

    CNode *getLeft() const;

    void setLeft(CNode *left);

    CNode *getRight() const;

    void setRight(CNode *right);
};

#endif //EFFECTIVE_PROGRAMMING_TECHNIQUES_CNODE_H

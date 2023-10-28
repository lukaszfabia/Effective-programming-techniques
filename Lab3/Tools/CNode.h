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
    CNode *parent;

    CNode();

    CNode(const std::string &value, CNode *left, CNode *right, CNode *parent);

    ~CNode();

    std::string getValue() const;

    void setValue(const std::string &value);

    CNode *getLeft() const;

    void setLeft(CNode *left);

    CNode *getRight() const;

    void setRight(CNode *right);

    CNode *getParent() const;

    void setParent(CNode *parent);
};

#endif //EFFECTIVE_PROGRAMMING_TECHNIQUES_CNODE_H

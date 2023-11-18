//
// Created by ufabi on 20.10.2023.
//

#ifndef EFFECTIVE_PROGRAMMING_TECHNIQUES_CTREE_H
#define EFFECTIVE_PROGRAMMING_TECHNIQUES_CTREE_H


#include <string>
#include "Utilities/CPreprocessExpression.h"
#include "Utilities/CNode.h"

class CTree {
private:
    CNode *root;
    std::vector<std::string> elements;
    std::map<std::string, double> values;

public:
    CTree();

    explicit CTree(const std::vector<std::string> &elements);

    ~CTree();

    CTree &operator=(const CTree &other);

    CTree operator+(const CTree &other) const;

    std::string printVars();

    std::string printNormalExpression();

    CNode *getRoot() const;

    void setRoot(CNode *cNodeRoot);

    void buildTree();

    std::string print();

    std::vector<std::string> getElements() const;

    std::string printLevels();

    void setElements(const std::vector<std::string> &elements);

    CNode *getOperatorChild() const;

    double calculate();

    void setValues(const std::map<std::string, double> &valuesMap);

    void copyTree(const CNode *sourceNode, CNode *targetNode, CTree *result) const;
};


#endif //EFFECTIVE_PROGRAMMING_TECHNIQUES_CTREE_H

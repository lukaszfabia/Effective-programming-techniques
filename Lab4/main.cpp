//
// Created by ufabi on 18.11.2023.
//
#include <iostream>
#include <cstring>
#include <vector>
#include "tools/Node.h"
#include "Tree.h"

std::vector<std::string> create_vector(const std::string &expression){
    std::vector<std::string> elements;
    std::istringstream iss(expression);
    std::string element;

    while (iss >> std::ws >> element) {
        elements.push_back(element);
    }

    return elements;
}

int main(){
//    std::string res = "+ asd + 1 + 1";
//    std::vector<std::string> elements = create_vector(res);
//
//
//
//    Tree<char *> tree(elements);
//    std::cout << tree.printNormalExpression() << std::endl;
    std::string in;
    std::getline(std::cin, in);
    std::vector<std::string> elements = create_vector(in);
    Tree<char *> tree(elements);
    std::cout << tree.printNormalExpression() << std::endl;
    std::cout << tree.printVars() << std::endl;
    std::cout << tree.print() << std::endl;
    return 0;
}
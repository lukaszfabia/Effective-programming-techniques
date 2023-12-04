//
// Created by ufabi on 04.12.2023.
//
#include <iostream>
#include "MySmartPointer.h"

int main() {
    MySmartPointer<int> a(11);
    MySmartPointer<int> b(99);
    a = b;
    return 0;
}
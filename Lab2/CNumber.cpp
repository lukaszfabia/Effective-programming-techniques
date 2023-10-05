//
// Created by ufabi on 04.10.2023.
//

#include <iostream>
#include "CNumber.h"

const int DEFAULT_SIZE = 10;

CNumber::CNumber() {
    i_size = DEFAULT_SIZE;
    i_numbers = new int[i_size];
    v_fill_array(0);
}

CNumber::CNumber(int iSize) {
    i_size = iSize;
    i_numbers = new int[i_size];
    v_fill_array(-1);
}

CNumber::~CNumber() {
    delete i_numbers;
}

CNumber &CNumber::operator=(const CNumber &cOther) {
    if (this == &cOther) {
        return *this;
    }
    delete[] i_numbers;
    i_size = cOther.i_size;
    i_numbers = new int[i_size];
    for (int i = 0; i < i_size; i++) {
        i_numbers[i] = cOther.i_numbers[i];
    }
    return *this;
}

CNumber &CNumber::operator=(int iValue) {
    int tmp = iValue;
    int digits = 0;

    while (tmp != 0) {
        tmp /= 10;
        digits++;
    }

    for (int i = digits - 1; i >= 0; i--) {
        i_numbers[i] = iValue % 10;
        iValue /= 10;
    }
    return *this;
}

void CNumber::v_show_array() {
    for (int i = 0; i < i_size; i++) {
        std::cout << i_numbers[i] << " ";
    }
    std::cout << std::endl;
}

void CNumber::v_fill_array(int iValue) {
    for (int i = 0; i < i_size; i++) {
        i_numbers[i] = iValue;
    }
}

int CNumber::get_size() const {
    return i_size;
}

CNumber &CNumber::operator+(const CNumber &cOther) {
    int iSize = i_size > cOther.i_size ? i_size : cOther.i_size;
    CNumber *cResult = new CNumber(iSize);
    int i_carry = 0;
    for (int i = iSize - 1; i >= 0; i--) {
        int iSum = i_numbers[i] + cOther.i_numbers[i] + i_carry;
        cResult->i_numbers[i] = iSum % 10;
        i_carry = iSum / 10;
    }
    return *cResult;
}

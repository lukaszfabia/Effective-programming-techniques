//
// Created by ufabi on 04.10.2023.
//

#include <iostream>
#include "CNumber.h"

const int DEFAULT_SIZE = 10;

CNumber::CNumber() {
    i_size = DEFAULT_SIZE;
    i_numbers = new int[i_size];
    is_negative = false;
    v_fill_array(0);
}

CNumber::CNumber(int iSize) {
    i_size = iSize;
    i_numbers = new int[i_size];
    is_negative = false;
    v_fill_array(0);
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
    is_negative = cOther.is_negative;
    return *this;
}

CNumber &CNumber::operator=(int iValue) {
    if (iValue < 0) {
        iValue = -iValue;
        is_negative = true;
    } else {
        is_negative = false;
    }

    v_set_values(iValue, i_size - 1);

    return *this;
}

void CNumber::v_set_values(int iValue, int i_index) {
    if (i_index >= 0) {
        i_numbers[i_index] = iValue % 10;
        v_set_values(iValue / 10, i_index - 1);
    } else {
        return;
    }
}

void CNumber::v_show_array() {
    std::cout << "--------------------------------------" << std::endl;
    std::cout << "array: " << std::endl;
    for (int i = 0; i < i_size; i++) {
        std::cout << i_numbers[i] << "\t";
    }
    std::cout << std::endl << "is negative: ";
    if (is_negative) {
        std::cout << "true" << std::endl;
    } else {
        std::cout << "false" << std::endl;
    }
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
    CNumber *cResult = new CNumber(i_size);

    if (!cOther.is_negative && !is_negative) {
        // Both numbers are positive, perform addition
        v_add(cOther, cResult);
    } else if (cOther.is_negative && is_negative) {
        // Both numbers are negative, perform addition and result is negative
        cResult->is_negative = true;
        v_add(cOther, cResult);
    } else {
        cResult->is_negative = b_is_bigger(cOther);
        v_substraction(*this, cResult, cOther);
    }
    return *cResult;
}





CNumber &CNumber::operator-(const CNumber &cOther) {
    CNumber *cResult = new CNumber(i_size);

    if (b_is_bigger(cOther)) {
        cResult->is_negative = is_negative;
        if (is_negative == cOther.is_negative)
            v_substraction(cOther, cResult, *this);
        else
            v_add(cOther, cResult);
    } else {
        if (is_negative == cOther.is_negative) {
            cResult->is_negative = !is_negative;
            v_substraction(*this, cResult, cOther);
        } else {
            cResult->is_negative = is_negative;
            v_add(cOther, cResult);
        }
    }

    return *cResult;
}


/// this - other
void CNumber::v_substraction(const CNumber &cOther, CNumber *cResult, const CNumber &cThisObject) {
    int i_borrow = 0;
    for (int i = cThisObject.i_size - 1; i >= 0; i--) {
        cResult->i_numbers[i] = cThisObject.i_numbers[i] - cOther.i_numbers[i] - i_borrow;
        if (cResult->i_numbers[i] < 0) {
            i_borrow = 1;
            cResult->i_numbers[i] += 10;
        } else {
            i_borrow = 0;
        }
    }
}

void CNumber::v_add(const CNumber &cOther, CNumber *cResult) {
    int i_carry = 0;
    for (int i = i_size - 1; i >= 0; i--) {
        cResult->i_numbers[i] = i_numbers[i] + cOther.i_numbers[i] + i_carry;
        i_carry = cResult->i_numbers[i] / 10;
        cResult->i_numbers[i] %= 10;
    }
}


bool CNumber::b_is_bigger(const CNumber &cOther) {
    bool thisIsNegative = is_negative;
    bool otherIsNegative = cOther.is_negative;

    if (thisIsNegative && otherIsNegative) {
        for (int i = 0; i < i_size; i++) {
            if (i_numbers[i] < cOther.i_numbers[i]) {
                return false;
            } else if (i_numbers[i] > cOther.i_numbers[i]) {
                return true;
            }
        }
        return false;
    }

    if (thisIsNegative) {
        return false;
    }

    if (otherIsNegative) {
        return true;
    }

    for (int i = 0; i < i_size; i++) {
        if (i_numbers[i] < cOther.i_numbers[i]) {
            return false;
        } else if (i_numbers[i] > cOther.i_numbers[i]) {
            return true;
        }
    }
    return false;
}


bool CNumber::get_is_negative() const {
    return is_negative;
}

int *CNumber::get_i_numbers() const {
    return i_numbers;
}

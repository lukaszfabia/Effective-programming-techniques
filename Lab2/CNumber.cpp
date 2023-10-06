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

CNumber CNumber::operator+(const CNumber &cOther) const {
    CNumber result(i_size);

    if (is_negative && !cOther.is_negative) {
        CNumber thisCopy(*this);
        thisCopy.is_negative = false;
        result = cOther - thisCopy;
    } else if (!is_negative && cOther.is_negative) {
        CNumber otherCopy(cOther);
        otherCopy.is_negative = false;
        result = *this - otherCopy;
    } else if (is_negative && cOther.is_negative) {
        result.is_negative = true;
        result.v_add(cOther, &result);
    } else {
        result.v_add(cOther, &result);
    }

    return result;
}

CNumber CNumber::operator-(const CNumber &cOther) const {
    CNumber result(i_size);

    if (is_negative && !cOther.is_negative) {
        CNumber thisCopy(*this);
        thisCopy.is_negative = false;
        result = cOther + thisCopy;
        result.is_negative = true;
    } else if (!is_negative && cOther.is_negative) {
        CNumber otherCopy(cOther);
        otherCopy.is_negative = false;
        result = *this + otherCopy;
    } else if (is_negative && cOther.is_negative) {
        CNumber thisCopy(*this);
        CNumber otherCopy(cOther);
        thisCopy.is_negative = false;
        otherCopy.is_negative = false;
        result = otherCopy - thisCopy;
    } else {
        if (b_is_bigger(cOther)) {
            result.is_negative = false;
            v_substraction(cOther, &result, *this);
        } else {
            result = cOther - *this;
            result.is_negative = true;
        }
    }

    return result;
}


/// this - other
void CNumber::v_substraction(const CNumber &cOther, CNumber *cResult, const CNumber &cThisObject) const {
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

void CNumber::v_add(const CNumber &cOther, CNumber *cResult) const {
    int i_carry = 0;
    for (int i = i_size - 1; i >= 0; i--) {
        cResult->i_numbers[i] = i_numbers[i] + cOther.i_numbers[i] + i_carry;
        i_carry = cResult->i_numbers[i] / 10;
        cResult->i_numbers[i] %= 10;
    }
}


bool CNumber::b_is_bigger(const CNumber &cOther) const{
    bool thisIsNegative = is_negative;
    bool otherIsNegative = cOther.is_negative;

    if (!thisIsNegative && !otherIsNegative) {
        for (int i = 0; i < i_size; i++) {
            if (i_numbers[i] < cOther.i_numbers[i]) {
                return false;
            } else if (i_numbers[i] > cOther.i_numbers[i]) {
                return true;
            }
        }
    } else if (thisIsNegative && otherIsNegative) {
        for (int i = 0; i < i_size; i++) {
            if (i_numbers[i] < cOther.i_numbers[i]) {
                return true;
            } else if (i_numbers[i] > cOther.i_numbers[i]) {
                return false;
            }
        }
    }


    if (thisIsNegative) {
        return false;
    }

    if (otherIsNegative) {
        return true;
    }

    return false;
}


bool CNumber::get_is_negative() const {
    return is_negative;
}

int *CNumber::get_i_numbers() const {
    return i_numbers;
}

CNumber::CNumber(const CNumber &other) {
    i_size = other.i_size;
    i_numbers = new int[i_size];
    for (int i = 0; i < i_size; i++) {
        i_numbers[i] = other.i_numbers[i];
    }
    is_negative = other.is_negative;
}

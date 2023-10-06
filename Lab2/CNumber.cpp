//
// Created by ufabi on 04.10.2023.
//

#include <iostream>
#include "CNumber.h"

const int DEFAULT_SIZE = 10;

CNumber::CNumber() {
    i_size = DEFAULT_SIZE;
    i_numbers = new int[i_size];
    b_is_negative = false;
    v_fill_array(0);
}

CNumber::CNumber(int iSize) {
    i_size = iSize;
    i_numbers = new int[i_size];
    b_is_negative = false;
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
    b_is_negative = cOther.b_is_negative;
    return *this;
}

CNumber &CNumber::operator=(int iValue) {
    if (iValue < 0) {
        iValue = -iValue;
        b_is_negative = true;
    } else {
        b_is_negative = false;
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
    std::cout << std::endl << "b_is_negative: ";
    if (b_is_negative) {
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

bool CNumber::get_is_negative() const {
    return b_is_negative;
}

int *CNumber::get_i_numbers() const {
    return i_numbers;
}

CNumber &CNumber::operator+(const CNumber &cOther) const {
    CNumber *cResult;
    cResult = new CNumber();

    if (cOther.b_is_negative == b_is_negative) {
        cResult->b_is_negative = b_is_negative;
        v_add(cOther, cResult);
    } else if (cOther.b_is_negative * b_is_negative == 0) {
        bool b_sign;
        if (b_get_sign_of_bigger_abs_number(cOther)) {
            b_sign = b_is_negative;
            v_substraction(cOther, cResult, *this);
        } else {
            b_sign = cOther.b_is_negative;
            v_substraction(*this, cResult, cOther);
        }
        cResult->b_is_negative = b_sign;
    }
    return *cResult;
}

CNumber &CNumber::operator-(const CNumber &cOther) const {
    CNumber *cResult;
    cResult = new CNumber();
    /// dziala na kolejno + - i - +
    if (b_is_negative && !cOther.b_is_negative || !b_is_negative && cOther.b_is_negative) {
        cResult->b_is_negative = b_is_negative;
        v_add(cOther, cResult);
    } else if (!b_is_negative && !cOther.b_is_negative) {
        // jesli this jest wiekszy od othera
        bool b_sign;
        if (b_get_sign_of_bigger_abs_number(cOther)) {
            b_sign = b_is_negative;
            v_substraction(cOther, cResult, *this);
        } else {
            b_sign = !cOther.b_is_negative;
            v_substraction(*this, cResult, cOther);
        }
        cResult->b_is_negative = b_sign;
    } else {
        bool b_sign;
        if (b_get_sign_of_bigger_abs_number(cOther)) {
            v_substraction(cOther, cResult, *this);
            b_sign = true;
        } else {
            v_substraction(*this, cResult, cOther);
            b_sign = false;
        }
        cResult->b_is_negative = b_sign;
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

void CNumber::v_add(const CNumber &cOther, CNumber *cResult) const {
    int i_carry = 0;
    for (int i = i_size - 1; i >= 0; i--) {
        cResult->i_numbers[i] = i_numbers[i] + cOther.i_numbers[i] + i_carry;
        i_carry = cResult->i_numbers[i] / 10;
        cResult->i_numbers[i] %= 10;
    }
}


bool CNumber::b_is_bigger(const CNumber &cOther) const {
    bool thisIsNegative = b_is_negative;
    bool otherIsNegative = cOther.b_is_negative;

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

/// true = this obj is bigger and result will get his sign false vice versa
bool CNumber::b_get_sign_of_bigger_abs_number(const CNumber &cOther) const {
    for (int i = 0; i < i_size; i++) {
        if (i_numbers[i] < cOther.i_numbers[i]) {
            return false;
        } else if (i_numbers[i] > cOther.i_numbers[i]) {
            return true;
        }
    }
    return false; // when they're equal
}


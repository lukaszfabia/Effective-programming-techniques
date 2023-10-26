//
// Created by ufabi on 04.10.2023.
//

#include <iostream>
#include "CNumber.h"
#include "CHelpFunctions.h"

const int DEFAULT_SIZE = 10;

CNumber::CNumber() {
    i_size = DEFAULT_SIZE;
    i_numbers = new int[i_size];
    b_is_negative = false;
    CHelpFunctions::v_fill_array(i_numbers, 0, DEFAULT_SIZE);
}

CNumber::CNumber(int iSize) {
    i_size = iSize;
    i_numbers = new int[i_size];
    b_is_negative = false;
    CHelpFunctions::v_fill_array(i_numbers, 0, iSize);
}

CNumber::~CNumber() {
    delete[] i_numbers;
}

CNumber &CNumber::operator=(const CNumber &cOther) {
    if (this == &cOther) {
        return *this;
    }
    b_copy_variables(cOther);

    b_copy_elements(cOther);

    return *this;
}

CNumber &CNumber::operator=(int iValue) {
    if (iValue < 0) {
        iValue = -iValue;
        b_is_negative = true;
    } else {
        b_is_negative = false;
    }

    CHelpFunctions::v_set_values(i_numbers, iValue, i_size - 1);

    return *this;
}

CNumber CNumber::operator+(const CNumber &cOther) const {
    CNumber cResult;

    if (cOther.b_is_negative == b_is_negative) {
        cResult = CHelpFunctions::c_add(cOther, *this);
        cResult.b_is_negative = b_is_negative;
    } else if (cOther.b_is_negative * b_is_negative == 0) {
        bool b_sign;
        if (CHelpFunctions::b_get_sign_of_bigger_abs_number(cOther, *this)) {
            b_sign = b_is_negative;
            cResult = CHelpFunctions::c_substraction(cOther, *this);
        } else {
            b_sign = cOther.b_is_negative;
            cResult = CHelpFunctions::c_substraction(*this, cOther);
        }
        cResult.b_is_negative = b_sign;
    }
    return cResult;
}

CNumber CNumber::operator-(const CNumber &cOther) const {
    CNumber cResult;

    if (b_is_negative && !cOther.b_is_negative || !b_is_negative && cOther.b_is_negative) {
        cResult = CHelpFunctions::c_add(cOther, *this);
        cResult.b_is_negative = b_is_negative;
    } else if (!b_is_negative && !cOther.b_is_negative) {
        bool b_sign;
        if (CHelpFunctions::b_get_sign_of_bigger_abs_number(cOther, *this)) {
            b_sign = b_is_negative;
            cResult = CHelpFunctions::c_substraction(cOther, *this);
        } else {
            b_sign = !cOther.b_is_negative;
            cResult = CHelpFunctions::c_substraction(*this, cOther);
        }
        cResult.b_is_negative = b_sign;
    } else {
        bool b_sign;
        if (CHelpFunctions::b_get_sign_of_bigger_abs_number(cOther, *this)) {
            cResult = CHelpFunctions::c_substraction(cOther, *this);
            b_sign = true;
        } else {
            cResult = CHelpFunctions::c_substraction(*this, cOther);
            b_sign = false;
        }
        cResult.b_is_negative = b_sign;
    }
    return cResult;
}

CNumber CNumber::operator*(const CNumber &cOther) const {
//    CNumber cResult(cOther.i_size + i_size);
//    int i_carry, i_product;
//    for (int i = i_size - 1; i >= 0; i--) {
//        i_carry = 0;
//        for (int j = cOther.i_size - 1; j >= 0; j--) {
//            i_product = i_numbers[i] * cOther.i_numbers[j] + i_carry + cResult.i_numbers[i + j + 1];
//            i_carry = i_product / 10;
//            cResult.i_numbers[i + j + 1] = i_product % 10;
//        }
//        cResult.i_numbers[i] += i_carry;
//    }
    CNumber cResult, cTemp1, cTemp2;
    cResult = 0;
    cTemp1 = *this;
    cTemp2 = cOther;
    cTemp1.v_set_is_negative(false);
    cTemp2.v_set_is_negative(false);
    while (!(cTemp2==0)){
        cResult = CHelpFunctions::c_add(cResult, cTemp1);
        cTemp2 = --cTemp2;
    }

    cResult.b_is_negative = b_is_negative != cOther.b_is_negative;

    return cResult;
}

CNumber CNumber::operator/(const CNumber &cOther) const {
    CNumber cResult, cTemp, absOther;
    cResult = -1;
    if (!(cOther == 0)) {
        cResult = 0;
        cTemp = *this;

        cTemp.v_set_is_negative(false);
        absOther = cOther;
        absOther.v_set_is_negative(false);

        while (cTemp >= absOther) {
            cTemp = CHelpFunctions::c_substraction(absOther, cTemp);
            cResult = ++cResult;
        }

        cResult.b_is_negative = (b_is_negative != cOther.b_get_is_negative());

    }
    return cResult;
}

bool CNumber::operator>=(const CNumber &cOther) const {
    for (int i = 0; i < i_size; i++) {
        if (i_numbers[i] > cOther.i_numbers[i]) {
            return true;
        } else if (i_numbers[i] < cOther.i_numbers[i]) {
            return false;
        }
    }

    return true;
}

bool CNumber::operator>=(int iValue) const {
    CNumber cOther;
    cOther = iValue;
    return *this >= cOther;
}

CNumber CNumber::operator++() const {
    CNumber cOne;
    cOne = 1;
    return *this + cOne;
}

CNumber CNumber::operator--() const {
    CNumber cOne;
    cOne = 1;
    return *this - cOne;
}

bool CNumber::operator==(int iValue) const {
    for (int i = 0; i < i_size; i++) {
        if (i_numbers[i] != iValue) {
            return false;
        }
    }
    return true;
}

CNumber CNumber::operator!() const {
    CNumber cResult(i_size * 2), cTemp;
    cResult = 1;
    cTemp=*this;
    while (!(cTemp==0)){
        cResult = cResult * cTemp;
        cTemp = --cTemp;
    }

    return cResult;
}

bool CNumber::b_copy_elements(const CNumber &cOther) const {
    for (int i = 0; i < i_size; i++) {
        i_numbers[i] = cOther.i_numbers[i];
    }
    return true;
}

bool CNumber::b_copy_variables(const CNumber &cOther) {
    delete[] i_numbers;
    v_set_size(cOther.i_size);
    i_numbers = new int[i_size];
    v_set_is_negative(cOther.b_is_negative);
    return true;
}

int CNumber::i_get_size() const {
    return i_size;
}

bool CNumber::b_get_is_negative() const {
    return b_is_negative;
}

int *CNumber::pi_get_i_numbers() const {
    return i_numbers;
}

void CNumber::v_set_is_negative(bool bIsNegative) {
    b_is_negative = bIsNegative;
}

void CNumber::v_set_size(int iSize) {
    i_size = iSize;
}

void CNumber::v_information() const {
    CHelpFunctions::v_show_array(*this);
}
//
// Created by ufabi on 04.10.2023.
//

#include <iostream>
#include "CNumber.h"
#include "CHelpFunctions.h"

CNumber::CNumber() {
    i_size = DEFAULT_SIZE;
    i_numbers = new int[i_size];
    b_is_negative = false;
}

CNumber::CNumber(int iSize) {
    i_size = iSize;
    i_numbers = new int[i_size];
    b_is_negative = false;
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

    return CHelpFunctions::c_resize_array(cResult);
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
        if (CHelpFunctions::b_get_sign_of_bigger_abs_number(cOther, *this)) {
            cResult = CHelpFunctions::c_substraction(cOther, *this);
            cResult.b_is_negative = true;
        } else {
            cResult = CHelpFunctions::c_substraction(*this, cOther);
            cResult.b_is_negative= false;
        }
    }

    return CHelpFunctions::c_resize_array(cResult);
}

CNumber CNumber::operator*(const CNumber &cOther) const {
    CNumber cTemp1, cTemp2;
    cTemp1 = CHelpFunctions::c_resize_array(*this);
    cTemp2 = CHelpFunctions::c_resize_array(cOther);
    CNumber cResult = CHelpFunctions::c_multiply(cTemp1, cTemp2);
    cResult.v_set_is_negative(b_is_negative != cOther.b_is_negative);

    return CHelpFunctions::c_resize_array(cResult);
}

CNumber CNumber::operator/(const CNumber &cOther) const {
    if (cOther == 0) {
        std::cout << "Error: Division by zero or division by bigger number" << std::endl;
        CNumber cRes;
        cRes = INT_MAX;
        return cRes;
    }

    if (cOther == 1) {
        return *this;
    }

    CNumber cResult, cTemp, absOther;
    cResult = 0;
    cTemp = *this;

    absOther = cOther;
    absOther.v_set_is_negative(false);
    cTemp.v_set_is_negative(false);

    if (absOther > cTemp) {
        return CNumber(0);
    }


    while (cTemp >= absOther) {
        cTemp = CHelpFunctions::c_substraction(absOther, cTemp);
        cResult = ++cResult;
    }
    cResult.b_is_negative = (b_is_negative != cOther.b_is_negative);
    return CHelpFunctions::c_resize_array(cResult);
}

bool CNumber::operator>=(const CNumber &cOther) const {
    if (b_is_negative && !cOther.b_is_negative) {
        return false;
    } else if (!b_is_negative && cOther.b_is_negative) {
        return true;
    }
    if (i_size > cOther.i_size) {
        return true;
    } else if (i_size < cOther.i_size) {
        return false;
    }
    for (int i = 0; i < i_size; i++) {
        if (i_numbers[i] > cOther.i_numbers[i]) {
            return true;
        } else if (i_numbers[i] < cOther.i_numbers[i]) {
            return false;
        }
    }
    return true;
}

bool CNumber::operator>(const CNumber &cOther) const {
    if (b_is_negative && !cOther.b_is_negative) {
        return false;
    } else if (!b_is_negative && cOther.b_is_negative) {
        return true;
    }
    if (i_size > cOther.i_size) {
        return true;
    } else if (i_size < cOther.i_size) {
        return false;
    }
    for (int i = 0; i < i_size; i++) {
        if (i_numbers[i] > cOther.i_numbers[i]) {
            return true;
        } else if (i_numbers[i] < cOther.i_numbers[i]) {
            return false;
        }
    }

    return false;
}

CNumber CNumber::operator++() const {
    CNumber cOne;
    cOne = 1;
    return *this + cOne;
}

CNumber CNumber::operator--() const {
    CNumber cOne;
    cOne = 1;
    return CHelpFunctions::c_substraction(cOne, *this);
}

bool CNumber::operator==(int iValue) const {
    for (int i = i_size - 1; i >= 0; i--) {
        if (i_numbers[i] != iValue) {
            return false;
        }
    }
    return true;
}

CNumber CNumber::operator!() const {
    if (b_is_negative) {
        std::cout << "Invalid input. Factorial is defined only for non-negative integers." << std::endl;
        return CNumber();
    }
    CNumber cResult, cTemp;
    cResult = 1;
    cTemp = *this;
    while (!(cTemp == 0)) {
        cResult = CHelpFunctions::c_multiply(cResult, cTemp);
        cTemp = --cTemp;
    }

    return CHelpFunctions::c_resize_array(cResult);
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
    std::cout << "------------------------------------" << std::endl;
    std::cout << "result number" << std::endl;
    std::cout << CHelpFunctions::s_to_char_array(*this) << std::endl;
    std::cout << "------------------------------------" << std::endl;
}
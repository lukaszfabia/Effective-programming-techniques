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

    if (is_negative && cOther.is_negative) {
        cResult->is_negative = true;
    } else if (is_negative || cOther.is_negative) {
        if (b_is_bigger(cOther)) {
            cResult->is_negative = is_negative;
        } else {
            cResult->is_negative = cOther.is_negative;
        }
    }
    int i_carry = 0;
    for (int i = i_size - 1; i >= 0; i--) {
        cResult->i_numbers[i] = i_numbers[i] + cOther.i_numbers[i] + i_carry;
        i_carry = cResult->i_numbers[i] / 10;
        cResult->i_numbers[i] %= 10;
    }
    return *cResult;
}

CNumber &CNumber::operator-(const CNumber &cOther) {
    CNumber *cResult = new CNumber(i_size);
    int i_borrow = 0;
    for (int i = i_size - 1; i >= 0; i--) {
        int diff = i_numbers[i] - cOther.i_numbers[i] - i_borrow;
        if (diff < 0) {
            diff += 10;
            i_borrow = 1;
        } else {
            i_borrow = 0;
        }

        cResult->i_numbers[i] = diff;
    }

    return *cResult;
}

bool CNumber::b_is_bigger(const CNumber &cOther) {
    int i_res_this_arr = 0;
    int i_res_other_arr = 0;
    for (int i = 0; i < i_size; i++) {
        if (i_numbers[i] > cOther.i_numbers[i]) {
            i_res_this_arr++;
        } else if (i_numbers[i] < cOther.i_numbers[i]) {
            i_res_other_arr++;
        }
    }
    return i_res_this_arr > i_res_other_arr;
}

bool CNumber::get_is_negative() const {
    return is_negative;
}

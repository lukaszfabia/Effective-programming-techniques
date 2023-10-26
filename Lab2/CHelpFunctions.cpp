//
// Created by ufabi on 25.10.2023.
//

#include <iostream>
#include "CHelpFunctions.h"

void CHelpFunctions::v_substraction(const CNumber &cOther, const CNumber &cResult, const CNumber &cThisObject) {
    int i_borrow = 0;
    for (int i = cThisObject.i_get_size() - 1; i >= 0; i--) {
        cResult.pi_get_i_numbers()[i] = cThisObject.pi_get_i_numbers()[i] - cOther.pi_get_i_numbers()[i] - i_borrow;
        if (cResult.pi_get_i_numbers()[i] < 0) {
            i_borrow = 1;
            cResult.pi_get_i_numbers()[i] += 10;
        } else {
            i_borrow = 0;
        }
    }
}

void CHelpFunctions::v_add(const CNumber &cOther, const CNumber &cResult, const CNumber &cThisObject) {
    int i_carry = 0;
    for (int i = cThisObject.i_get_size() - 1; i >= 0; i--) {
        cResult.pi_get_i_numbers()[i] = cThisObject.pi_get_i_numbers()[i] + cOther.pi_get_i_numbers()[i] + i_carry;
        if (cResult.pi_get_i_numbers()[i] > 9) {
            i_carry = 1;
            cResult.pi_get_i_numbers()[i] -= 10;
        } else {
            i_carry = 0;
        }
    }
}

int CHelpFunctions::i_get_amount_of_digits(int iValue) {
    int i_tmp = iValue;
    int i_digits = 0;
    while (i_tmp != 0) {
        i_digits++;
        i_tmp /= 10;
    }

    return i_digits;
}

void CHelpFunctions::v_show_array(const CNumber &cNumber) {
    std::cout << "--------------------------------------" << std::endl;
    std::cout << "number: " << std::endl;
    int i_start_index = 0;
    while (cNumber.pi_get_i_numbers()[i_start_index] == 0) {
        i_start_index++;
    }

    if (cNumber.b_get_is_negative()) {
        std::cout << "- ";
    } else {
        std::cout << "+ ";
    }

    for (int i = i_start_index; i < cNumber.i_get_size(); i++) {
        std::cout << cNumber.pi_get_i_numbers()[i] << " ";
    }
    std::cout << std::endl;
}

void CHelpFunctions::v_fill_array(int *piNumbers, int iValue, int iSize) {
    for (int i = 0; i < iSize; i++) {
        piNumbers[i] = iValue;
    }
}

bool CHelpFunctions::b_get_sign_of_bigger_abs_number(const CNumber &cOther, const CNumber &cThisObject) {
    for (int i = 0; i < cThisObject.i_get_size(); i++) {
        if (cThisObject.pi_get_i_numbers()[i] < cOther.pi_get_i_numbers()[i]) {
            return false;
        } else if (cThisObject.pi_get_i_numbers()[i] > cOther.pi_get_i_numbers()[i]) {
            return true;
        }
    }
    return false; // when they're equal
}

void CHelpFunctions::v_set_values(int *piNumbers, int iValue, int i_index) {
    if (i_index >= 0) {
        piNumbers[i_index] = iValue % 10;
        v_set_values(piNumbers, iValue / 10, i_index - 1);
    } else {
        return;
    }
}
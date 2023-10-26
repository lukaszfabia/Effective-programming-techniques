//
// Created by ufabi on 25.10.2023.
//

#include <iostream>
#include "CHelpFunctions.h"

CNumber CHelpFunctions::c_substraction(const CNumber &cNumber1, const CNumber &cNumber2) {
    int max_size = cNumber1.i_get_size();
    CNumber cResult(max_size);

    const int* larger_array;
    const int* smaller_array;
    int longer_size;
    int shorter_size;

    if (cNumber1.i_get_size() <= cNumber2.i_get_size()) {
        larger_array = cNumber2.pi_get_i_numbers();
        longer_size = cNumber2.i_get_size();
        smaller_array = cNumber1.pi_get_i_numbers();
        shorter_size = cNumber1.i_get_size();
    } else {
        larger_array = cNumber1.pi_get_i_numbers();
        longer_size = cNumber1.i_get_size();
        smaller_array = cNumber2.pi_get_i_numbers();
        shorter_size = cNumber2.i_get_size();
    }

    int i_borrow = 0;
    int j = max_size - 1;

    for (int i = longer_size- 1; i >= 0; i--) {
        int difference = larger_array[i] -
                         ((i >= longer_size - shorter_size) ? smaller_array[i - (longer_size - shorter_size)] : 0) -
                         i_borrow;

        if (difference < 0) {
            difference += 10;
            i_borrow = 1;
        } else {
            i_borrow = 0;
        }

        cResult.pi_get_i_numbers()[j] = difference;
        j--;
    }

    return cResult;
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

CNumber CHelpFunctions::c_add(const CNumber &cNumber1, const CNumber &cNumber2) {
    int max_size = std::max(cNumber1.i_get_size(), cNumber2.i_get_size()) + 1;
    CNumber cResult(max_size);

    const int *longer_array;
    const int *shorter_array;
    int longer_size;
    int shorter_size;

    if (cNumber1.i_get_size() >= cNumber2.i_get_size()) {
        longer_array = cNumber1.pi_get_i_numbers();
        longer_size = cNumber1.i_get_size();
        shorter_array = cNumber2.pi_get_i_numbers();
        shorter_size = cNumber2.i_get_size();
    } else {
        longer_array = cNumber2.pi_get_i_numbers();
        longer_size = cNumber2.i_get_size();
        shorter_array = cNumber1.pi_get_i_numbers();
        shorter_size = cNumber1.i_get_size();
    }

    int i_carry = 0;
    int j = max_size - 1;

    for (int i = longer_size - 1; i >= 0; i--) {
        int sum = longer_array[i] +
                  ((i >= longer_size - shorter_size) ? shorter_array[i - (longer_size - shorter_size)] : 0) + i_carry;
        cResult.pi_get_i_numbers()[j] = sum % 10;
        i_carry = sum / 10;
        j--;
    }

    return cResult;
}
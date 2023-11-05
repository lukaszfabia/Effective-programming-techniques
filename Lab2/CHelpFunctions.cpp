//
// Created by ufabi on 25.10.2023.
//

#include <iostream>
#include "CHelpFunctions.h"

CNumber CHelpFunctions::c_substraction(const CNumber &cNumber1, const CNumber &cNumber2) {
    int max_size = std::max(cNumber2.i_get_size(), cNumber1.i_get_size());

    CNumber cResult(max_size);

    int i_borrow = 0;
    int j = max_size - 1;

    for (int i = cNumber2.i_get_size() - 1; i >= 0; i--) {
        int difference = cNumber2.pi_get_i_numbers()[i] -
                         ((i >= cNumber2.i_get_size() - cNumber1.i_get_size()) ? cNumber1.pi_get_i_numbers()[i - (cNumber2.i_get_size() - cNumber1.i_get_size())] : 0) -
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
}

char *CHelpFunctions::s_to_char_array(const CNumber &cNumber) {
    char *s_number = new char[cNumber.i_get_size() + 2];
    s_number[0] = cNumber.b_get_is_negative() ? '-' : '+';
    int i_index_for_string = 1;
    int i_start_index = 0;

    while (i_start_index < cNumber.i_get_size() && cNumber.pi_get_i_numbers()[i_start_index] == 0) {
        i_start_index++;
    }

    for (int i = i_start_index; i < cNumber.i_get_size(); i++) {
        s_number[i_index_for_string++] = cNumber.pi_get_i_numbers()[i] + '0';  // Konwersja na znak
    }

    s_number[i_index_for_string] = '\0';
    return s_number;
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

CNumber CHelpFunctions::c_resize_array(const CNumber &cResult) {
    int i_first_non_zero_index = 0;
    while (cResult.pi_get_i_numbers()[i_first_non_zero_index] == 0) {
        i_first_non_zero_index++;
    }
    int i_new_size = 0;
    for (int i = i_first_non_zero_index; i < cResult.i_get_size(); i++) {
        i_new_size++;
    }

    CNumber c_res(i_new_size);
    int j = 0;
    for (int i = i_first_non_zero_index; i < cResult.i_get_size(); i++) {
        c_res.pi_get_i_numbers()[j] = cResult.pi_get_i_numbers()[i];
        j++;
    }
    c_res.v_set_is_negative(cResult.b_get_is_negative());


    return c_res;
}

CNumber CHelpFunctions::c_add(const CNumber &cNumber1, const CNumber &cNumber2) {
    int max_size = std::max(cNumber1.i_get_size(), cNumber2.i_get_size()) + 1;

    CNumber cResult(max_size);
    int i_carry = 0;
    int j = max_size - 1;

    for (int i = cNumber2.i_get_size() - 1; i >= 0; i--) {
        int sum = cNumber2.pi_get_i_numbers()[i] +
                  ((i >= cNumber2.i_get_size() - cNumber1.i_get_size()) ? cNumber1.pi_get_i_numbers()[i - (cNumber2.i_get_size() - cNumber1.i_get_size())] : 0) + i_carry;
        cResult.pi_get_i_numbers()[j] = sum % 10;
        i_carry = sum / 10;
        j--;
    }

    if (i_carry > 0) {
        cResult.pi_get_i_numbers()[j] = i_carry;
    }

    return cResult;
}


int CHelpFunctions::i_get_number_of_digits(int iNumber) {
    int i_result = 0;
    while (iNumber != 0) {
        i_result++;
        iNumber /= 10;
    }

    return i_result;
}

CNumber CHelpFunctions::c_multiply(const CNumber &cNumber1, const CNumber &cNumber2) {
    CNumber cResult, cTemp1, cTemp2;
    cResult = 0;
    cTemp1 = cNumber1;
    cTemp2 = cNumber2;
    cTemp1.v_set_is_negative(false);
    cTemp2.v_set_is_negative(false);
    while (!(cTemp2 == 0)) {
        cResult = CHelpFunctions::c_add(cResult, cTemp1);
        cTemp2 = --cTemp2;
    }

    return cResult;
}
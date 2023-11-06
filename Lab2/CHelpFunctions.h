//
// Created by ufabi on 25.10.2023.
//

#ifndef EFFECTIVE_PROGRAMMING_TECHNIQUES_CHELPFUNCTIONS_H
#define EFFECTIVE_PROGRAMMING_TECHNIQUES_CHELPFUNCTIONS_H

#include "CNumber.h"

class CHelpFunctions {
public:
    static CNumber c_substraction(const CNumber &cOther, const CNumber &cThisObject);

    static void v_show_array(const CNumber &cNumber);

    static void v_fill_array(int *piNumbers, int iValue, int iSize);

    static bool b_get_sign_of_bigger_abs_number(const CNumber &cOther, const CNumber &cThisObject);

    static void v_set_values(int *piNumbers, int iValue, int i_index);

    static CNumber c_add(const CNumber &cNumber1, const CNumber &cNumber2);

    static int i_get_number_of_digits(int iNumber);

    static CNumber c_resize_array(const CNumber &cResult);

    static CNumber c_multiply(const CNumber &cNumber1, const CNumber &cNumber2);

    static char *s_to_char_array(const CNumber &cNumber);
};


#endif //EFFECTIVE_PROGRAMMING_TECHNIQUES_CHELPFUNCTIONS_H

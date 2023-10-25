//
// Created by ufabi on 25.10.2023.
//

#ifndef EFFECTIVE_PROGRAMMING_TECHNIQUES_CHELPFUNCTIONS_H
#define EFFECTIVE_PROGRAMMING_TECHNIQUES_CHELPFUNCTIONS_H

#include "CNumber.h"

class CHelpFunctions {
public:
    static void v_substraction(const CNumber &cOther, const CNumber &cResult, const CNumber &cThisObject);

    static void v_add(const CNumber &cOther, const CNumber &cResult, const CNumber &cThisObject);

    static int i_get_amount_of_digits(int iValue);

    static void v_show_array(const CNumber &cNumber);

    static void v_fill_array(int *piNumbers, int iValue, int iSize);

    static bool b_get_sign_of_bigger_abs_number(const CNumber &cOther, const CNumber &cThisObject)  ;
};


#endif //EFFECTIVE_PROGRAMMING_TECHNIQUES_CHELPFUNCTIONS_H
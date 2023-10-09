//
// Created by ufabi on 04.10.2023.
//

#ifndef EFFECTIVE_PROGRAMMING_TECHNIQUES_CNUMBER_H
#define EFFECTIVE_PROGRAMMING_TECHNIQUES_CNUMBER_H


class CNumber {
private:
    int i_size;
    int *i_numbers;
    bool b_is_negative;

    bool b_copy_elements(const CNumber &cOther) const;

    bool b_copy_variables(const CNumber &cOther);

    bool b_get_sign_of_bigger_abs_number(const CNumber &cOther) const;

    static void v_substraction(const CNumber &cOther, CNumber *cResult, const CNumber &cThisObject);

    void v_add(const CNumber &cOther, CNumber *cResult) const;

    void v_fill_array(int iValue);

    void v_set_values(int iValue, int i_index);

public:
    CNumber();

    explicit CNumber(int iSize);

    ~CNumber();

    CNumber &operator=(const CNumber &cOther);

    CNumber &operator=(int iValue);

    CNumber &operator+(const CNumber &cOther) const;

    CNumber &operator-(const CNumber &cOther) const;

    CNumber &operator*(const CNumber &cOther) const;

    CNumber &operator/(const CNumber &cOther) const;

    CNumber &operator/(int iDivider) const;

    CNumber &operator+(int iValue) const;

    CNumber &operator-(int iValue) const;

    CNumber &operator*(int iValue) const;

    void v_show_array();

    int i_get_size() const;

    int *pi_get_i_numbers() const;

    static int i_get_amount_of_digits(int iValue);

    bool b_get_is_negative() const;

    bool b_is_bigger(const CNumber &cOther) const;

};


#endif //EFFECTIVE_PROGRAMMING_TECHNIQUES_CNUMBER_H
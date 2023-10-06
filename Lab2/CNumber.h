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

    static void v_substraction(const CNumber &cOther, CNumber *cResult, const CNumber &cThisObject);

    void v_add(const CNumber &cOther, CNumber *cResult) const;

    bool b_is_bigger(const CNumber &cOther) const;

    bool get_is_negative() const;

    void v_set_values(int iValue, int i_index);

    void v_show_array();

    void v_fill_array(int iValue);

    int get_size() const;

    int *get_i_numbers() const;

    bool b_get_sign_of_bigger_abs_number(const CNumber &cOther) const;

    bool b_is_zero(const CNumber &number) const;
};


#endif //EFFECTIVE_PROGRAMMING_TECHNIQUES_CNUMBER_H
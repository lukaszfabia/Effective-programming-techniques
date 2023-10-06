//
// Created by ufabi on 04.10.2023.
//

#ifndef EFFECTIVE_PROGRAMMING_TECHNIQUES_CNUMBER_H
#define EFFECTIVE_PROGRAMMING_TECHNIQUES_CNUMBER_H


#include <string>

class CNumber {
public:
    CNumber();

    explicit CNumber(int iSize);

    ~CNumber();

    CNumber &operator=(const CNumber &cOther);
    CNumber &operator+(const CNumber &cOther);
    CNumber &operator-(const CNumber &cOther);
    CNumber &operator/(const CNumber &cOther);
    CNumber &operator*(const CNumber &cOther);

    CNumber &operator=(int iValue);

    void v_show_array();

    void v_fill_array(int iValue);

    int get_size() const;

    bool get_is_negative() const;

    int *get_i_numbers() const;

private:
    int *i_numbers;
    int i_size;
    bool is_negative;

    bool b_is_bigger(const CNumber &cOther);

    void v_set_values(int iValue, int i_index);

    static void v_substraction(const CNumber &cOther, CNumber *cResult, const CNumber &cThisObject);

    void v_add(const CNumber &cOther, CNumber *cResult);
};


#endif //EFFECTIVE_PROGRAMMING_TECHNIQUES_CNUMBER_H

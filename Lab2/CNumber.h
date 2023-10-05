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

private:
    int *i_numbers;
    int i_size;
};


#endif //EFFECTIVE_PROGRAMMING_TECHNIQUES_CNUMBER_H

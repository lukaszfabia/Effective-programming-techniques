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

    void v_set_values(int iValue, int i_index);

public:
    CNumber();

    explicit CNumber(int iSize);

    ~CNumber();

    CNumber &operator=(const CNumber &cOther);

    CNumber &operator=(int iValue);

    CNumber operator+(const CNumber &cOther) const;

    CNumber operator-(const CNumber &cOther) const;

    CNumber operator*(const CNumber &cOther) const;

    CNumber operator/(const CNumber &cOther) const;

    bool operator>=(const CNumber &cOther) const;

    bool operator>=(int iValue) const;

    bool operator==(int iValue) const;

    CNumber operator++() const;

    int i_get_size() const;

    int *pi_get_i_numbers() const;

    bool b_get_is_negative() const;

    void v_set_is_negative(bool bIsNegative);

    void v_set_size(int iSize);

    void v_set_i_numbers(int *piNumbers);

};


#endif //EFFECTIVE_PROGRAMMING_TECHNIQUES_CNUMBER_H
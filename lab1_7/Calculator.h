#pragma once
#include "Fraction.h"

class Calculator
{
private:
    Fraction fraction;

public:
    Fraction GetFraction() const { return fraction; }
    void SetFraction(Fraction value) { fraction = value; }

    void Init(long whole, unsigned char fr);
    void Read();
    void Display();
    string toString();

    Calculator operator+(const Calculator &other) const;
    Calculator operator-(const Calculator &other) const;
    Calculator operator*(const Calculator &other) const;
    bool operator==(const Calculator &other) const;
    bool operator!=(const Calculator &other) const;
    bool operator<(const Calculator &other) const;
    bool operator>(const Calculator &other) const;
    bool operator<=(const Calculator &other) const;
    bool operator>=(const Calculator &other) const;
};
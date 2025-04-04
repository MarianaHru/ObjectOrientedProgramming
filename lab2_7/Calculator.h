#pragma once
#include "Fraction.h"

class Calculator
{
private:
    Fraction fraction;

public:
    Fraction GetFraction() const { return fraction; }
    void SetFraction(Fraction value) { fraction = value; }

    Calculator();
    Calculator(Fraction value);
    Calculator(const Calculator &);
    ~Calculator();

    Calculator &operator=(const Calculator &);

    friend ostream &operator<<(ostream &os, const Calculator &c);
    friend istream &operator>>(istream &is, Calculator &c);
    operator string() const;

    friend Calculator operator+(const Calculator &c1, const Calculator &c2);
    friend Calculator operator-(const Calculator &c1, const Calculator &c2);
    friend Calculator operator*(const Calculator &c1, const Calculator &c2);

    friend bool operator==(const Calculator &c1, const Calculator &c2);
    friend bool operator!=(const Calculator &c1, const Calculator &c2);
    friend bool operator<(const Calculator &c1, const Calculator &c2);
    friend bool operator>(const Calculator &c1, const Calculator &c2);
    friend bool operator<=(const Calculator &c1, const Calculator &c2);
    friend bool operator>=(const Calculator &c1, const Calculator &c2);
};
// Calculator.cpp
#include "Calculator.h"

Fraction Calculator::Add(const Fraction &a, const Fraction &b)
{
    return a + b;
}

Fraction Calculator::Subtract(const Fraction &a, const Fraction &b)
{
    return a - b;
}

Fraction Calculator::Multiply(const Fraction &a, const Fraction &b)
{
    return a * b;
}

bool Calculator::Compare(const Fraction &a, const Fraction &b)
{
    return a == b;
}
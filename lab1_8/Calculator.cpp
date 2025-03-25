// Calculator.cpp
#include "Fraction.h"
#include <iostream>
#include <limits>

using namespace std;

void Calculator::Init(long whole, unsigned char fr)
{
    Fraction temp;
    if (temp.Init(whole, fr))
    {
        SetFraction(temp);
    }
}

void Calculator::Read()
{
    Fraction temp;
    temp.Read();
    SetFraction(temp);
}

void Calculator::Display()
{
    cout << toString() << endl;
}

string Calculator::toString()
{
    return fraction.toString();
}

// Реалізація арифметичних операторів
Calculator Calculator::operator+(const Calculator &other) const
{
    Calculator result;
    result.SetFraction(this->fraction + other.fraction);
    return result;
}

Calculator Calculator::operator-(const Calculator &other) const
{
    Calculator result;
    result.SetFraction(this->fraction - other.fraction);
    return result;
}

Calculator Calculator::operator*(const Calculator &other) const
{
    Calculator result;
    result.SetFraction(this->fraction * other.fraction);
    return result;
}

// Реалізація операторів порівняння
bool Calculator::operator==(const Calculator &other) const
{
    return this->fraction == other.fraction;
}

bool Calculator::operator!=(const Calculator &other) const
{
    return this->fraction != other.fraction;
}

bool Calculator::operator<(const Calculator &other) const
{
    return this->fraction < other.fraction;
}

bool Calculator::operator>(const Calculator &other) const
{
    return this->fraction > other.fraction;
}

bool Calculator::operator<=(const Calculator &other) const
{
    return this->fraction <= other.fraction;
}

bool Calculator::operator>=(const Calculator &other) const
{
    return this->fraction >= other.fraction;
}

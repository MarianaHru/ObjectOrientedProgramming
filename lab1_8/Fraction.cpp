#include "Fraction.h"
#include <iostream>
#include <sstream>

using namespace std;

Calculator::Fraction::Fraction(long whole, unsigned char fr)
{
    this->whole = whole;
    this->fr = fr;
}

bool Calculator::Fraction::SetFractional(unsigned char value)
{
    if (value < 100)
    {
        fr = value;
        return true;
    }
    return false;
}

bool Calculator::Fraction::Init(long whole, unsigned char fr)
{
    SetWhole(whole);
    return SetFractional(fr);
}

void Calculator::Fraction::Read()
{
    long whole;
    int temp_fr;
    cout << "Enter whole part: ";
    cin >> whole;
    do
    {
        cout << "Enter fractional part (0-99): ";
        cin >> temp_fr;
    } while (temp_fr < 0 || temp_fr >= 100);
    Init(whole, static_cast<unsigned char>(temp_fr));
}

void Calculator::Fraction::Display() const
{
    cout << toString() << endl;
}

string Calculator::Fraction::toString() const
{
    stringstream sout;
    sout << whole << "," << (fr < 10 ? "0" : "") << static_cast<int>(fr);
    return sout.str();
}

// Оператори
Calculator::Fraction Calculator::Fraction::operator+(const Fraction &other) const
{
    return Fraction(whole + other.whole, fr + other.fr);
}
Calculator::Fraction Calculator::Fraction::operator-(const Fraction &other) const
{
    return Fraction(whole - other.whole, fr - other.fr);
}
Calculator::Fraction Calculator::Fraction::operator*(const Fraction &other) const
{
    return Fraction(whole * other.whole, fr * other.fr);
}
bool Calculator::Fraction::operator==(const Fraction &other) const
{
    return whole == other.whole && fr == other.fr;
}
bool Calculator::Fraction::operator!=(const Fraction &other) const
{
    return !(*this == other);
}
bool Calculator::Fraction::operator<(const Fraction &other) const
{
    return whole < other.whole || (whole == other.whole && fr < other.fr);
}
bool Calculator::Fraction::operator>(const Fraction &other) const
{
    return other < *this;
}

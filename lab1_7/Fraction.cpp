#include "Fraction.h"
#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>

using namespace std;

Fraction::Fraction(long whole, unsigned char fr)
{
    this->whole = whole;
    this->fr = fr;
}

bool Fraction::SetSecond(unsigned char first)
{
    if (first < 100)
    {
        fr = first;
        return true;
    }
    else
    {
        cout << "Error, pennies cant be more than 99";
        return false;
    }
}

bool Fraction::Init(long whole, unsigned char fr)
{
    SetFirst(whole);
    return SetSecond(fr);
}

void Fraction::Read()
{
    long whole;
    unsigned char fr;
    cout << "Write whole part: ";
    cin >> whole;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int temp_fr;

    do
    {
        cout << "Write fractional part(0-99) ";
        cin >> temp_fr;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        fr = static_cast<unsigned char>(temp_fr);
    } while (!Init(whole, fr));
}

void Fraction::Display() const
{
    cout << toString() << endl;
}

string Fraction::toString() const
{
    stringstream sout;

    sout << whole << ",";
    if (fr < 10)
    {
        sout << "0";
    }
    sout << (int)fr;
    return sout.str();
}

Fraction Fraction::operator+(const Fraction &other) const
{
    long total1 = (whole * 100.0 + fr) + (other.whole * 100.0 + other.fr);

    return Fraction(total1 / 100, total1 % 100);
}

Fraction Fraction::operator-(const Fraction &other) const
{
    long total2 = (whole * 100.0 + fr) - (other.whole * 100.0 + other.fr);

    return Fraction(total2 / 100, total2 % 100);
}

Fraction Fraction::operator*(const Fraction &other) const
{
    long total1 = whole * 100 + fr;
    long total2 = other.whole * 100 + other.fr;

    long total = total1 * total2;

    long wholePart = total / 10000;
    unsigned char frPart = total % 10000;

    return Fraction(wholePart, frPart);
}

bool Fraction::operator==(const Fraction &other) const
{
    long total1 = whole * 100 + fr;
    long total2 = other.whole * 100 + other.fr;
    return total1 == total2;
}

bool Fraction::operator!=(const Fraction &other) const
{
    return !(*this == other);
}

bool Fraction::operator<(const Fraction &other) const
{
    long total1 = whole * 100 + fr;
    long total2 = other.whole * 100 + other.fr;
    return total1 < total2;
}

bool Fraction::operator>(const Fraction &other) const
{
    long total1 = whole * 100 + fr;
    long total2 = other.whole * 100 + other.fr;
    return total1 > total2;
}

bool Fraction::operator<=(const Fraction &other) const
{
    return !(*this <= other);
}

bool Fraction::operator>=(const Fraction &other) const
{
    return !(*this >= other);
}

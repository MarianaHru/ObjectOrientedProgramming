#include "Fraction.h"
#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>

using namespace std;

Fraction::Fraction()
{
    whole = 0;
    frac = 0;
}

Fraction::Fraction(long w, unsigned char f)
{
    whole = w;
    frac = f;
}

Fraction::Fraction(const Fraction &f)
{
    whole = f.whole;
    frac = f.frac;
}

Fraction::~Fraction() {};

Fraction &Fraction::operator=(const Fraction &f)
{
    whole = f.whole;
    frac = f.frac;
    return *this;
}

Fraction::operator string() const
{
    stringstream sout;

    sout << whole << ",";
    if (frac < 10)
    {
        sout << "0";
    }
    sout << (int)frac;
    return sout.str();
}

ostream &operator<<(ostream &sout, const Fraction &f)
{
    sout << string(f);
    return sout;
}

istream &operator>>(istream &in, Fraction &f)
{
    cout << "Write whole part: ";
    in >> f.whole;
    in.ignore(numeric_limits<streamsize>::max(), '\n');

    int temp;

    do
    {
        cout << "Write fractional part (0-99): ";
        in >> temp;
        in.ignore(numeric_limits<streamsize>::max(), '\n');
        f.frac = static_cast<unsigned char>(temp);
    } while (temp > 99);

    return in;
}

Fraction operator+(const Fraction &f1, const Fraction &f2)
{
    long Whole = f1.whole + f2.whole;
    unsigned char Frac = f1.frac + f2.frac;

    if (Frac > 100)
    {
        Whole += Frac / 100;
        Frac = Frac % 100;
    }
    return Fraction(Whole, Frac);
}

Fraction operator-(const Fraction &f1, const Fraction &f2)
{
    long Whole = f1.whole - f2.whole;
    int Frac = f1.frac - f2.frac;

    if (Frac < 0)
    {
        Whole -= 1;
        Frac += 100;
    }

    return Fraction(Whole, Frac);
}

Fraction operator*(const Fraction &f1, const Fraction &f2)
{
    long Whole = f1.whole * f2.whole;
    unsigned char Frac = (f1.frac * f2.frac) / 100;

    if (Frac >= 100)
    {
        Whole += Frac / 100;
        Frac = Frac % 100;
    }

    return Fraction(Whole, Frac);
}

bool operator==(const Fraction &f1, const Fraction &f2)
{
    if (f1.whole == f2.whole && f1.frac == f2.frac)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool operator!=(const Fraction &f1, const Fraction &f2)
{
    if (f1.whole != f2.whole && f1.frac != f2.frac)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool operator<(const Fraction &f1, const Fraction &f2)
{
    if (f1.whole < f2.whole && f1.frac < f2.frac)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool operator>(const Fraction &f1, const Fraction &f2)
{
    if (f1.whole > f2.whole && f1.frac > f2.frac)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool operator<=(const Fraction &f1, const Fraction &f2)
{
    if (f1.whole <= f2.whole && f1.frac <= f2.frac)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool operator>=(const Fraction &f1, const Fraction &f2)
{
    if (f1.whole >= f2.whole && f1.frac >= f2.frac)
    {
        return true;
    }
    else
    {
        return false;
    }
}
#include "Calculator.h"
#include <string>
#include <sstream>

using namespace std;

Calculator::Fraction::Fraction()
{
    whole = 0;
    frac = 0;
}

Calculator::Fraction::Fraction(long w, unsigned char f)
{
    whole = w;
    frac = f;
}

Calculator::Fraction::Fraction(const Fraction &f)
{
    whole = f.whole;
    frac = f.frac;
}

Calculator::Fraction::~Fraction() {};

Calculator::Fraction &Calculator::Fraction::operator=(const Calculator::Fraction &f)
{
    whole = f.whole;
    frac = f.frac;
    return *this;
}

Calculator::Fraction::operator string() const
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

ostream &operator<<(ostream &sout, const Calculator::Fraction &f)
{
    sout << string(f);
    return sout;
}

istream &operator>>(istream &in, Calculator::Fraction &f)
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

Calculator::Fraction operator+(const Calculator::Fraction &f1, const Calculator::Fraction &f2)
{
    long Whole = f1.whole + f2.whole;
    unsigned char Frac = f1.frac + f2.frac;

    if (Frac > 100)
    {
        Whole += Frac / 100;
        Frac = Frac % 100;
    }
    return Calculator::Fraction(Whole, Frac);
}

Calculator::Fraction operator-(const Calculator::Fraction &f1, const Calculator::Fraction &f2)
{
    long Whole = f1.whole - f2.whole;
    int Frac = f1.frac - f2.frac;

    if (Frac < 0)
    {
        Whole -= 1;
        Frac += 100;
    }

    return Calculator::Fraction(Whole, Frac);
}

Calculator::Fraction operator*(const Calculator::Fraction &f1, const Calculator::Fraction &f2)
{
    long Whole = f1.whole * f2.whole;
    unsigned char Frac = (f1.frac * f2.frac) / 100;

    if (Frac >= 100)
    {
        Whole += Frac / 100;
        Frac = Frac % 100;
    }

    return Calculator::Fraction(Whole, Frac);
}

bool operator==(const Calculator::Fraction &f1, const Calculator::Fraction &f2)
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

bool operator!=(const Calculator::Fraction &f1, const Calculator::Fraction &f2)
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

bool operator<(const Calculator::Fraction &f1, const Calculator::Fraction &f2)
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

bool operator>(const Calculator::Fraction &f1, const Calculator::Fraction &f2)
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

bool operator<=(const Calculator::Fraction &f1, const Calculator::Fraction &f2)
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

bool operator>=(const Calculator::Fraction &f1, const Calculator::Fraction &f2)
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

Calculator::Calculator()
{
    fraction = Fraction();
}

Calculator::Calculator(Fraction value)
{
    fraction = value;
}

Calculator::Calculator(const Calculator &c)
{
    fraction = c.fraction;
}

Calculator::~Calculator() {};

Calculator &Calculator::operator=(const Calculator &c)
{
    fraction = c.fraction;
    return *this;
}

Calculator::operator string() const
{
    stringstream ss;
    ss << fraction;
    return ss.str();
}

ostream &operator<<(ostream &sout, const Calculator &c)
{
    sout << string(c);
    return sout;
}

istream &operator>>(istream &in, Calculator &c)
{
    in >> c.fraction;
    return in;
}

Calculator operator+(const Calculator &c1, const Calculator &c2)
{
    Calculator::Fraction sum = c1.fraction + c2.fraction;
    return Calculator(sum);
}

Calculator operator-(const Calculator &c1, const Calculator &c2)
{
    Calculator::Fraction dif = c1.fraction - c2.fraction;
    return Calculator(dif);
}

Calculator operator*(const Calculator &c1, const Calculator &c2)
{
    Calculator::Fraction mult = c1.fraction * c2.

                                              fraction;
    return Calculator(mult);
}

bool operator==(const Calculator &c1, const Calculator &c2)
{
    return c1.fraction == c2.fraction;
}

bool operator!=(const Calculator &c1, const Calculator &c2)
{
    return c1.fraction != c2.fraction;
}

bool operator<(const Calculator &c1, const Calculator &c2)
{
    return c1.fraction < c2.fraction;
}

bool operator>(const Calculator &c1, const Calculator &c2)
{
    return c1.fraction > c2.fraction;
}

bool operator<=(const Calculator &c1, const Calculator &c2)
{
    return c1.fraction <= c2.fraction;
}

bool operator>=(const Calculator &c1, const Calculator &c2)
{
    return c1.fraction >= c2.fraction;
}
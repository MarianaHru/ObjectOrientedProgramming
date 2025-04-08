#include "Calculator.h"
#include <string>
#include <sstream>

using namespace std;

int Calculator::count = 0;
int Calculator::Fraction::count = 0;

Calculator::Fraction::Fraction() : whole(0), frac(0) { count++; }
Calculator::Fraction::Fraction(long w, unsigned char f) : whole(w), frac(f) { count++; }
Calculator::Fraction::Fraction(const Fraction &f) : whole(f.whole), frac(f.frac) { count++; }
Calculator::Fraction::~Fraction() { count--; }

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
        sout << "0";
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
    } while (temp < 0 || temp > 99);
    f.frac = static_cast<unsigned char>(temp);

    return in;
}

Calculator::Fraction operator+(const Calculator::Fraction &f1, const Calculator::Fraction &f2)
{
    long whole = f1.whole + f2.whole;
    unsigned char frac = f1.frac + f2.frac;

    if (frac >= 100)
    {
        whole += frac / 100;
        frac = frac % 100;
    }
    return Calculator::Fraction(whole, frac);
}

Calculator::Fraction operator-(const Calculator::Fraction &f1, const Calculator::Fraction &f2)
{
    long whole = f1.whole - f2.whole;
    int frac = f1.frac - f2.frac;

    if (frac < 0)
    {
        whole -= 1;
        frac += 100;
    }
    return Calculator::Fraction(whole, static_cast<unsigned char>(frac));
}

Calculator::Fraction operator*(const Calculator::Fraction &f1, const Calculator::Fraction &f2)
{
    long total1 = f1.whole * 100 + f1.frac;
    long total2 = f2.whole * 100 + f2.frac;
    long result = (total1 * total2) / 100;
    return Calculator::Fraction(result / 100, result % 100);
}

bool operator==(const Calculator::Fraction &f1, const Calculator::Fraction &f2)
{
    return f1.whole == f2.whole && f1.frac == f2.frac;
}

bool operator!=(const Calculator::Fraction &f1, const Calculator::Fraction &f2)
{
    return !(f1 == f2);
}

bool operator<(const Calculator::Fraction &f1, const Calculator::Fraction &f2)
{
    if (f1.whole < f2.whole)
        return true;
    if (f1.whole == f2.whole)
        return f1.frac < f2.frac;
    return false;
}

bool operator>(const Calculator::Fraction &f1, const Calculator::Fraction &f2)
{
    return f2 < f1;
}

bool operator<=(const Calculator::Fraction &f1, const Calculator::Fraction &f2)
{
    return !(f2 < f1);
}

bool operator>=(const Calculator::Fraction &f1, const Calculator::Fraction &f2)
{
    return !(f1 < f2);
}

Calculator::Calculator() : fraction() { count++; }
Calculator::Calculator(Fraction value) : fraction(value) { count++; }
Calculator::Calculator(const Calculator &c) : fraction(c.fraction) { count++; }
Calculator::~Calculator() { count--; }

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
    return Calculator(c1.fraction + c2.fraction);
}

Calculator operator-(const Calculator &c1, const Calculator &c2)
{
    return Calculator(c1.fraction - c2.fraction);
}

Calculator operator*(const Calculator &c1, const Calculator &c2)
{
    return Calculator(c1.fraction * c2.fraction);
}

bool operator==(const Calculator &c1, const Calculator &c2)
{
    return c1.fraction == c2.fraction;
}

bool operator!=(const Calculator &c1, const Calculator &c2)
{
    return !(c1 == c2);
}

bool operator<(const Calculator &c1, const Calculator &c2)
{
    return c1.fraction < c2.fraction;
}

bool operator>(const Calculator &c1, const Calculator &c2)
{
    return c2 < c1;
}

bool operator<=(const Calculator &c1, const Calculator &c2)
{
    return !(c2 < c1);
}

bool operator>=(const Calculator &c1, const Calculator &c2)
{
    return !(c1 < c2);
}

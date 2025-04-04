#include "Calculator.h"
#include <string>

using namespace std;

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
    Fraction sum = c1.fraction + c2.fraction;
    return Calculator(sum);
}

Calculator operator-(const Calculator &c1, const Calculator &c2)
{
    Fraction dif = c1.fraction - c2.fraction;
    return Calculator(dif);
}

Calculator operator*(const Calculator &c1, const Calculator &c2)
{
    Fraction mult = c1.fraction * c2.fraction;
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
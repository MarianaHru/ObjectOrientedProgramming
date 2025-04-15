// MoneyPrivate.cpp
#include "MoneyPrivate.h"

MoneyPrivate::MoneyPrivate() : Money() {}
MoneyPrivate::MoneyPrivate(long h, unsigned char k) : Money(h, k) {}
MoneyPrivate::MoneyPrivate(const Money &other) : Money(other) {}
MoneyPrivate::MoneyPrivate(const MoneyPrivate &other) : Money(other) {}

MoneyPrivate operator+(const MoneyPrivate &a, const MoneyPrivate &b)
{
    long total = a.hryvnia * 100 + a.kopiyky + b.hryvnia * 100 + b.kopiyky;
    return MoneyPrivate(total / 100, total % 100);
}

MoneyPrivate operator-(const MoneyPrivate &a, const MoneyPrivate &b)
{
    long total = a.hryvnia * 100 + a.kopiyky - (b.hryvnia * 100 + b.kopiyky);
    return MoneyPrivate(total / 100, total % 100);
}

MoneyPrivate operator*(const MoneyPrivate &a, const MoneyPrivate &b)
{
    long long totalA = (long long)a.hryvnia * 100 + a.kopiyky;
    long long totalB = (long long)b.hryvnia * 100 + b.kopiyky;
    long long result = totalA * totalB / 10000;
    return MoneyPrivate(result / 100, result % 100);
}

MoneyPrivate operator/(const MoneyPrivate &a, const MoneyPrivate &b)
{
    if (b.hryvnia == 0 && b.kopiyky == 0)
    {
        return MoneyPrivate(0, 0);
    }
    long double totalA = a.hryvnia * 100.0 + a.kopiyky;
    long double totalB = b.hryvnia * 100.0 + b.kopiyky;
    long long result = (long long)(totalA / totalB * 100);
    return MoneyPrivate(result / 100, result % 100);
}

bool operator==(const MoneyPrivate &a, const MoneyPrivate &b)
{
    return a.hryvnia == b.hryvnia && a.kopiyky == b.kopiyky;
}

bool operator!=(const MoneyPrivate &a, const MoneyPrivate &b)
{
    return !(a == b);
}

bool operator>(const MoneyPrivate &a, const MoneyPrivate &b)
{
    return (a.hryvnia > b.hryvnia) || (a.hryvnia == b.hryvnia && a.kopiyky > b.kopiyky);
}

bool operator<(const MoneyPrivate &a, const MoneyPrivate &b)
{
    return (a.hryvnia < b.hryvnia) || (a.hryvnia == b.hryvnia && a.kopiyky < b.kopiyky);
}

bool operator>=(const MoneyPrivate &a, const MoneyPrivate &b)
{
    return (a > b) || (a == b);
}

bool operator<=(const MoneyPrivate &a, const MoneyPrivate &b)
{
    return (a < b) || (a == b);
}

ostream &operator<<(ostream &out, const MoneyPrivate &m)
{
    out << (string)m;
    return out;
}

istream &operator>>(istream &in, MoneyPrivate &m)
{
    long h;
    int k;
    in >> h >> k;
    m.Init(h, k);
    return in;
}

MoneyPrivate &operator++(MoneyPrivate &m)
{
    if (++m.kopiyky >= 100)
    {
        m.kopiyky = 0;
        ++m.hryvnia;
    }
    return m;
}

MoneyPrivate operator++(MoneyPrivate &m, int)
{
    MoneyPrivate temp = m;
    ++m;
    return temp;
}

MoneyPrivate &operator--(MoneyPrivate &m)
{
    if (m.kopiyky == 0)
    {
        --m.hryvnia;
        m.kopiyky = 99;
    }
    else
    {
        --m.kopiyky;
    }
    return m;
}

MoneyPrivate operator--(MoneyPrivate &m, int)
{
    MoneyPrivate temp = m;
    --m;
    return temp;
}
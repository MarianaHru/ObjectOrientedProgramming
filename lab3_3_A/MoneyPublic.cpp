// MoneyPublic.cpp
#include "MoneyPublic.h"

MoneyPublic::MoneyPublic() : Money() {}
MoneyPublic::MoneyPublic(long h, unsigned char k) : Money(h, k) {}
MoneyPublic::MoneyPublic(const Money &other) : Money(other) {}
MoneyPublic::MoneyPublic(const MoneyPublic &other) : Money(other) {}

MoneyPublic &MoneyPublic::operator=(const MoneyPublic &m)
{
    if (this != &m)
    {
        hryvnia = m.hryvnia;
        kopiyky = m.kopiyky;
    }
    return *this;
}

MoneyPublic operator+(const MoneyPublic &a, const MoneyPublic &b)
{
    long totalKopiyky = a.hryvnia * 100 + a.kopiyky + b.hryvnia * 100 + b.kopiyky;
    return MoneyPublic(totalKopiyky / 100, totalKopiyky % 100);
}

MoneyPublic operator-(const MoneyPublic &a, const MoneyPublic &b)
{
    long totalA = a.hryvnia * 100 + a.kopiyky;
    long totalB = b.hryvnia * 100 + b.kopiyky;
    long result = totalA - totalB;
    return MoneyPublic(result / 100, result % 100);
}

MoneyPublic operator*(const MoneyPublic &a, const MoneyPublic &b)
{
    long long totalKopiykyA = a.hryvnia * 100 + a.kopiyky;
    long long totalKopiykyB = b.hryvnia * 100 + b.kopiyky;
    long long result = (long long)totalKopiykyA * totalKopiykyB / 10000;
    return MoneyPublic(result / 100, result % 100);
}

MoneyPublic operator/(const MoneyPublic &a, const MoneyPublic &b)
{
    if (b.hryvnia == 0 && b.kopiyky == 0)
    {
        return MoneyPublic(0, 0);
    }
    long double totalA = a.hryvnia * 100.0 + a.kopiyky;
    long double totalB = b.hryvnia * 100.0 + b.kopiyky;
    long long result = (long long)(totalA / totalB * 100);
    return MoneyPublic(result / 100, result % 100);
}

bool operator==(const MoneyPublic &a, const MoneyPublic &b)
{
    return a.hryvnia == b.hryvnia && a.kopiyky == b.kopiyky;
}

bool operator!=(const MoneyPublic &a, const MoneyPublic &b)
{
    return !(a == b);
}

bool operator>(const MoneyPublic &a, const MoneyPublic &b)
{
    return (a.hryvnia > b.hryvnia) || (a.hryvnia == b.hryvnia && a.kopiyky > b.kopiyky);
}

bool operator<(const MoneyPublic &a, const MoneyPublic &b)
{
    return (a.hryvnia < b.hryvnia) || (a.hryvnia == b.hryvnia && a.kopiyky < b.kopiyky);
}

bool operator>=(const MoneyPublic &a, const MoneyPublic &b)
{
    return (a > b) || (a == b);
}

bool operator<=(const MoneyPublic &a, const MoneyPublic &b)
{
    return (a < b) || (a == b);
}

MoneyPublic &operator++(MoneyPublic &m)
{
    if (++m.kopiyky >= 100)
    {
        m.kopiyky = 0;
        ++m.hryvnia;
    }
    return m;
}

MoneyPublic operator++(MoneyPublic &m, int)
{
    MoneyPublic temp = m;
    ++m;
    return temp;
}

MoneyPublic &operator--(MoneyPublic &m)
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

MoneyPublic operator--(MoneyPublic &m, int)
{
    MoneyPublic temp = m;
    --m;
    return temp;
}
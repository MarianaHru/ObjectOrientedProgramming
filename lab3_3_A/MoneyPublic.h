#pragma once
#include "Money.h"

class MoneyPublic : public Money
{
public:
    // Конструктори
    MoneyPublic() : Money() {}
    MoneyPublic(long h, unsigned char k) : Money(h, k) {}
    MoneyPublic(const Money &other) : Money(other) {}
    MoneyPublic(const MoneyPublic &other) : Money(other) {}

    using Money::operator string;
    using Money::Display;

    MoneyPublic &operator=(const MoneyPublic &);

    friend MoneyPublic operator*(const MoneyPublic &a, const MoneyPublic &b);
    friend MoneyPublic operator/(const MoneyPublic &a, const MoneyPublic &b);
    friend MoneyPublic operator+(const MoneyPublic &, const MoneyPublic &);
    friend MoneyPublic operator-(const MoneyPublic &, const MoneyPublic &);

    friend MoneyPublic &operator++(MoneyPublic &m);
    friend MoneyPublic operator++(MoneyPublic &m, int);
    friend MoneyPublic &operator--(MoneyPublic &m);
    friend MoneyPublic operator--(MoneyPublic &m, int);

    friend bool operator==(const MoneyPublic &, const MoneyPublic &);
    friend bool operator!=(const MoneyPublic &a, const MoneyPublic &b);
    friend bool operator>(const MoneyPublic &a, const MoneyPublic &b);
    friend bool operator<(const MoneyPublic &a, const MoneyPublic &b);
    friend bool operator>=(const MoneyPublic &a, const MoneyPublic &b);
    friend bool operator<=(const MoneyPublic &a, const MoneyPublic &b);
};
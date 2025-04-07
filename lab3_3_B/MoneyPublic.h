#pragma once
#include "Money.h"

class MoneyPublic : public Money
{
public:
    MoneyPublic();
    MoneyPublic(long h, unsigned char k);
    MoneyPublic(const Money &m);

    MoneyPublic operator+(const MoneyPublic &other) const;
    double operator/(const MoneyPublic &other) const;
    MoneyPublic operator/(double divisor) const;

    MoneyPublic &operator++();   // Префіксний
    MoneyPublic operator++(int); // Постфіксний

    MoneyPublic &operator--();
    MoneyPublic operator--(int);

    bool operator==(const MoneyPublic &other) const;
    bool operator!=(const MoneyPublic &other) const;
};

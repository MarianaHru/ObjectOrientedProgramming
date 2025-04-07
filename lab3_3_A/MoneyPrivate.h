#pragma once
#include "Money.h"

class MoneyPrivate : private Money
{
public:
    MoneyPrivate();
    MoneyPrivate(long hryvna, unsigned char kopek);
    MoneyPrivate(const Money &other);

    Money toBase() const;

    MoneyPrivate operator+(const MoneyPrivate &other) const;
    MoneyPrivate operator/(double divisor) const;
    double operator/(const MoneyPrivate &other) const;

    MoneyPrivate &operator++();
    MoneyPrivate operator++(int);
    MoneyPrivate &operator--();
    MoneyPrivate operator--(int);

    bool operator==(const MoneyPrivate &other) const;
    bool operator!=(const MoneyPrivate &other) const;
};

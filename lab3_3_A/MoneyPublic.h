#pragma once
#include "Money.h"

class MoneyPublic : public Money
{
public:
    MoneyPublic();
    MoneyPublic(long hryvna, unsigned char kopek);
    MoneyPublic(const Money &other);

    MoneyPublic operator+(const MoneyPublic &other) const;
    MoneyPublic operator/(double divisor) const;
    double operator/(const MoneyPublic &other) const;

    MoneyPublic &operator++();   // Префіксний інкремент
    MoneyPublic operator++(int); // Постфіксний інкремент
    MoneyPublic &operator--();
    MoneyPublic operator--(int);

    bool operator==(const MoneyPublic &other) const;
    bool operator!=(const MoneyPublic &other) const;
};

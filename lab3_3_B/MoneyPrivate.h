#pragma once
#include "Money.h"

class MoneyPrivate : private Money
{
public:
    MoneyPrivate();
    MoneyPrivate(long hryvna, unsigned char kopek);

    // Операції
    MoneyPrivate operator+(const MoneyPrivate &other);
    MoneyPrivate operator-(const MoneyPrivate &other);
    bool operator==(const MoneyPrivate &other);

    std::string toString() const;
    void fromString(const std::string &s);
};

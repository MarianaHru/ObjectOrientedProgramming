#pragma once
#include "Money.h"

class MoneyPrivate : private Money
{
public:
    // Конструктори
    MoneyPrivate() : Money() {}
    MoneyPrivate(long h, unsigned char k) : Money(h, k) {}
    MoneyPrivate(const Money &other) : Money(other) {}
    MoneyPrivate(const MoneyPrivate &other) : Money(other) {}

    // Доступ до методів базового класу
    using Money::Display;
    using Money::Init;
    using Money::Read;
    using Money::operator string;

    friend MoneyPrivate operator*(const MoneyPrivate &a, const MoneyPrivate &b);
    friend MoneyPrivate operator/(const MoneyPrivate &a, const MoneyPrivate &b);
    friend MoneyPrivate operator+(const MoneyPrivate &, const MoneyPrivate &);
    friend MoneyPrivate operator-(const MoneyPrivate &, const MoneyPrivate &);
    friend ostream &operator<<(ostream &, const MoneyPrivate &);
    friend istream &operator>>(istream &, MoneyPrivate &);

    friend MoneyPrivate &operator++(MoneyPrivate &m);
    friend MoneyPrivate operator++(MoneyPrivate &m, int);
    friend MoneyPrivate &operator--(MoneyPrivate &m);
    friend MoneyPrivate operator--(MoneyPrivate &m, int);

        friend bool operator==(const MoneyPrivate &a, const MoneyPrivate &b);
    friend bool operator!=(const MoneyPrivate &a, const MoneyPrivate &b);
    friend bool operator>(const MoneyPrivate &a, const MoneyPrivate &b);
    friend bool operator<(const MoneyPrivate &a, const MoneyPrivate &b);
    friend bool operator>=(const MoneyPrivate &a, const MoneyPrivate &b);
    friend bool operator<=(const MoneyPrivate &a, const MoneyPrivate &b);
};
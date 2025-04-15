#ifndef MONEY_H
#define MONEY_H

#include "Pair.h"
#include <iostream>
#include <string>

class Money : public Pair
{
private:
    unsigned char kopek;

public:
    Money();
    Money(long hryvna, unsigned char kopek);
    Money(const Money &other);

    long GetHryvna() const;
    unsigned char GetKopek() const;
    void SetHryvna(long h);
    bool SetKopek(unsigned char k);

    Методи ініціалізації void Init(long hryvna, unsigned char kopek);

    void fromString(const std::string &s);

    friend Money operator+(const Money &m1, const Money &m2);
    friend Money operator-(const Money &m1, const Money &m2);
    friend double operator/(const Money &m1, const Money &m2);
    friend Money operator/(const Money &m, double divisor);

    Money &operator++();
    Money operator++(int);
    Money &operator--();
    Money operator--(int);

        Money &operator=(const Money &other);

    std::string toString() const;
};

// Зовнішня функція makeMoney
Money makeMoney(long hryvna, unsigned char kopek);

#endif
// Money.h
#pragma once
#include "Object.h"
#include <iostream>
#include <string>

class Money : public Object
{
private:
    long hryvna;
    unsigned char kopek;

public:
    Money();
    Money(long hryvna, unsigned char kopek);
    Money(const Money &other);

    void Init(long h, unsigned char k);

    void Read();
    void display() const override;

    std::string toString() const override;
    explicit operator std::string() const;

    Money &operator=(const Money &other);

    Money operator+(const Money &other) const;
    double operator/(const Money &other) const;
    Money operator/(double divisor) const;

    Money &operator++();
    Money operator++(int);
    Money &operator--();
    Money operator--(int);

    friend std::istream &operator>>(std::istream &in, Money &money);
    friend std::ostream &operator<<(std::ostream &out, const Money &money);
};

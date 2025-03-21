// Fraction.h
#pragma once
#include <string>
#include <iostream>

class Fraction
{
private:
    long long integerPart;
    unsigned short fractionalPart;

public:
    Fraction();
    Fraction(long long integer, unsigned short fractional);
    void Init(long long integer, unsigned short fractional);
    void Read();
    void Display() const;
    std::string toString() const;

    long long GetIntegerPart() const;
    unsigned short GetFractionalPart() const;
    void SetIntegerPart(long long integer);
    void SetFractionalPart(unsigned short fractional);

    Fraction operator+(const Fraction &other) const;
    Fraction operator-(const Fraction &other) const;
    Fraction operator*(const Fraction &other) const;
    bool operator==(const Fraction &other) const;
    bool operator!=(const Fraction &other) const;
    bool operator<(const Fraction &other) const;
    bool operator>(const Fraction &other) const;
};

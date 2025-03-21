// Calculator.h
#pragma once
#include <iostream>
#include <string>

class Calculator
{
public:
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

    static Fraction Add(const Fraction &a, const Fraction &b);
    static Fraction Subtract(const Fraction &a, const Fraction &b);
    static Fraction Multiply(const Fraction &a, const Fraction &b);
    static bool Compare(const Fraction &a, const Fraction &b);
};

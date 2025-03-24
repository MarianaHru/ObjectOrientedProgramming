// Fraction.h
#pragma once
#include <iostream>
#include <string>
#include <sstream>

class Calculator
{
public:
    class Fraction
    {
    private:
        long whole;
        unsigned char fr;

    public:
        Fraction(long whole = 0, unsigned char fr = 0);
        long GetWhole() const { return whole; }
        unsigned char GetFractional() const { return fr; }
        void SetWhole(long value) { whole = value; }
        bool SetFractional(unsigned char value);
        bool Init(long whole, unsigned char fr);
        void Read();
        void Display() const;
        std::string toString() const;
        Fraction operator+(const Fraction &other) const;
        Fraction operator-(const Fraction &other) const;
        Fraction operator*(const Fraction &other) const;
        bool operator==(const Fraction &other) const;
        bool operator!=(const Fraction &other) const;
        bool operator<(const Fraction &other) const;
        bool operator>(const Fraction &other) const;
    };

private:
    Fraction fraction;

public:
    Fraction GetFraction() const { return fraction; }
    void SetFraction(Fraction value) { fraction = value; }
    void Init(long whole, unsigned char fr);
    void Read();
    void Display();
    std::string toString();
    Calculator operator+(const Calculator &other) const;
    Calculator operator-(const Calculator &other) const;
    Calculator operator*(const Calculator &other) const;
    bool operator==(const Calculator &other) const;
    bool operator!=(const Calculator &other) const;
    bool operator<(const Calculator &other) const;
    bool operator>(const Calculator &other) const;
};

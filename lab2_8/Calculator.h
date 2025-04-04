#pragma once
#include <iostream>
#include <iomanip>

using namespace std;

class Calculator
{
private:
public:
    class Fraction
    {
    private:
        long whole;
        unsigned char frac;

    public:
        Fraction();
        Fraction(long w, unsigned char f);
        Fraction(const Fraction &);
        ~Fraction();

        long GetFirst() const { return whole; }
        unsigned char GetSecond() const { return frac; }

        void SetFirst(long first) { whole = first; }
        bool SetSecond(unsigned char second) { frac = second; }

        Fraction &operator=(const Fraction &);

        friend ostream &operator<<(ostream &os, const Fraction &f);
        friend istream &operator>>(istream &is, Fraction &f);
        operator string() const;

        friend Fraction operator+(const Fraction &f1, const Fraction &f2);
        friend Fraction operator-(const Fraction &f1, const Fraction &f2);
        friend Fraction operator*(const Fraction &f1, const Fraction &f2);

        friend bool operator==(const Fraction &f1, const Fraction &f2);
        friend bool operator!=(const Fraction &f1, const Fraction &f2);
        friend bool operator<(const Fraction &f1, const Fraction &f2);
        friend bool operator>(const Fraction &f1, const Fraction &f2);
        friend bool operator<=(const Fraction &f1, const Fraction &f2);
        friend bool operator>=(const Fraction &f1, const Fraction &f2);
    };
    Calculator::Fraction GetFraction() const { return fraction; }
    void SetFraction(Fraction value) { fraction = value; }

    Calculator();
    Calculator(Fraction value);
    Calculator(const Calculator &);
    ~Calculator();

    Calculator &operator=(const Calculator &);

    friend ostream &operator<<(ostream &os, const Calculator &c);
    friend istream &operator>>(istream &is, Calculator &c);
    operator string() const;

    friend Calculator operator+(const Calculator &c1, const Calculator &c2);
    friend Calculator operator-(const Calculator &c1, const Calculator &c2);
    friend Calculator operator*(const Calculator &c1, const Calculator &c2);

    friend bool operator==(const Calculator &c1, const Calculator &c2);
    friend bool operator!=(const Calculator &c1, const Calculator &c2);
    friend bool operator<(const Calculator &c1, const Calculator &c2);
    friend bool operator>(const Calculator &c1, const Calculator &c2);
    friend bool operator<=(const Calculator &c1, const Calculator &c2);
    friend bool operator>=(const Calculator &c1, const Calculator &c2);

private:
    Fraction fraction;
};
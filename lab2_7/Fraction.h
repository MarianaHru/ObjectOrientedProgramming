#pragma once
#include <string>
#include <sstream>

using namespace std;

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
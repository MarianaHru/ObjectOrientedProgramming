#pragma once
#include <string>
#include <sstream>

using namespace std;

class Fraction
{
private:
    long whole;
    unsigned char fr;

public:
    Fraction(long whole = 0, unsigned char fr = 0);

    long GetFirst() const { return whole; }
    unsigned char GetSecond() const { return fr; }

    void SetFirst(long first) { whole = first; }
    bool SetSecond(unsigned char second);

    bool Init(long wh, unsigned char fr);
    void Display() const;
    void Read();
    string toString() const;

    Fraction operator+(const Fraction &other) const;
    Fraction operator-(const Fraction &other) const;
    Fraction operator*(const Fraction &other) const;
    bool operator==(const Fraction &other) const;
    bool operator!=(const Fraction &other) const;
    bool operator<(const Fraction &other) const;
    bool operator>(const Fraction &other) const;
    bool operator<=(const Fraction &other) const;
    bool operator>=(const Fraction &other) const;
};
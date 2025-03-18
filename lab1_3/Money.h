#pragma once
#include <string>
#include <sstream>

using namespace std;

class Money
{
private:
    long hryvna;
    unsigned char kopek;

public:
    Money(long hryvna = 0, unsigned char kopek = 0);

    long GetFirst() const { return hryvna; }
    unsigned char GetSecond() const { return kopek; }

    void SetFirst(long first) { hryvna = first; }
    bool SetSecond(unsigned char second);

    bool Init(long hr, unsigned char kop);
    void Display() const;
    void Read();
    string toString() const;

    Money operator+(const Money &other) const;
    double operator/(const Money &other) const;
    Money operator/(double divisor) const;
};

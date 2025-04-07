#pragma once
#include <iostream>
#include <string>

using namespace std;

class Money
{
protected:
    long hryvna;
    unsigned char kopek;

public:
    Money();
    Money(long hryvna, unsigned char kopek);
    Money(const Money &other);

    long GetHryvna() const;
    unsigned char GetKopek() const;
    void SetHryvna(long h);
    bool SetKopek(unsigned char k);

    string toString() const;
    void fromString(const string &s);

    friend ostream &operator<<(ostream &out, const Money &m);
    friend istream &operator>>(istream &in, Money &m);
};

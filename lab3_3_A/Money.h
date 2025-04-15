#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Money
{
protected:
    long hryvnia;
    unsigned char kopiyky;

public:
    Money();
    Money(long, unsigned char);
    Money(const Money &);

    void Init(long, unsigned char);
    void Read();
    void Display() const;

    explicit operator string() const;

    friend ostream &operator<<(ostream &, const Money &);
    friend istream &operator>>(istream &, Money &);
};
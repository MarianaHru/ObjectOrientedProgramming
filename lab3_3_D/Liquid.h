// Liquid.h
#pragma once
#include <iostream>
#include <string>
using namespace std;

class Liquid
{
protected:
    string name;
    double density;

public:
    Liquid();
    Liquid(string, double);

    void Init(string, double);
    void Read();
    void Display() const;

    friend ostream &operator<<(ostream &, const Liquid &);
    friend istream &operator>>(istream &, Liquid &);

    explicit operator string() const;
};
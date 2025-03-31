// Liquid.h
#pragma once
#include <string>
#include <iostream>
using namespace std;

class Liquid
{
private:
    string name;
    double density;

public:
    Liquid();
    Liquid(string name, double density);
    Liquid(const Liquid &other);
    Liquid &operator=(const Liquid &other);
    void Init(string name, double density);
    void Read();
    void Display() const;

    string getName() const;
    double getDensity() const;
    void setName(string name);
    void setDensity(double density);

    friend ostream &operator<<(ostream &out, const Liquid &l);
    friend istream &operator>>(istream &in, Liquid &l);
    operator string() const;
};

#pragma once
#include "Object.h"
#include <string>
#include <iostream>

using namespace std;

class Liquid : public Object
{
protected:
    string name;
    double density;

public:
    Liquid();
    Liquid(const string &name, double density);
    Liquid(const Liquid &other);

    void Init(const string &name, double density);
    void Read();
    void Display() const;

    void setName(const string &name);
    void setDensity(double density);
    string getName() const;
    double getDensity() const;

    Liquid &operator=(const Liquid &other);

    friend ostream &operator<<(ostream &out, const Liquid &l);
    friend istream &operator>>(istream &in, Liquid &l);
    explicit operator string() const;

    Liquid &operator++();   // префікс
    Liquid operator++(int); // постфікс
    Liquid &operator--();
    Liquid operator--(int);

    virtual ~Liquid() = default;
};

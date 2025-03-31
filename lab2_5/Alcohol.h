// Alcohol.h
#pragma once
#include "Liquid.h"

class Alcohol
{
private:
    Liquid liquid;
    double strength;

public:
    Alcohol();
    Alcohol(Liquid liquid, double strength);
    Alcohol(const Alcohol &other);

    Alcohol &operator=(const Alcohol &other);
    void Init(string spec, Liquid liquid);
    void Read();
    void Display() const;

    friend ostream &operator<<(ostream &out, const Alcohol &a);
    friend istream &operator>>(istream &in, Alcohol &a);
    operator string() const;

    Alcohol &operator++();
    Alcohol operator++(int);
    Alcohol &operator--();
    Alcohol operator--(int);

    void setStrength(double strength);
};

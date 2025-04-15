#pragma once
#include "Liquid.h"

class Alcohol : public Liquid
{
private:
    double strength;

public:
    Alcohol();
    Alcohol(const string &name, double density, double strength);
    Alcohol(const Alcohol &other);

    void Init(const string &strengthStr, const Liquid &liquid);
    void Read();
    void Display() const;

    void setStrength(double strength);
    double getStrength() const;

    Alcohol &operator=(const Alcohol &other);

    friend ostream &operator<<(ostream &out, const Alcohol &a);
    friend istream &operator>>(istream &in, Alcohol &a);
    explicit operator string() const;

    Alcohol &operator++();
    Alcohol operator++(int);
    Alcohol &operator--();
    Alcohol operator--(int);

    ~Alcohol() = default;
};

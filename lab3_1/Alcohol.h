// Derived class: Alcohol.h
#ifndef ALCOHOL_H
#define ALCOHOL_H

#include "Liquid.h"

class Alcohol : public Liquid
{
private:
    double strength;

public:
    Alcohol();
    Alcohol(const std::string &name, double density, double strength);
    Alcohol(const Liquid &liquid, double strength);
    Alcohol(const Alcohol &other);

    double getStrength() const;
    void setStrength(double strength);

    void Init(const std::string &name, double density, double strength);
    void Read();
    void Display() const;

    operator std::string() const;

    Alcohol &operator=(const Alcohol &other);

    friend std::ostream &operator<<(std::ostream &out, const Alcohol &alcohol);
    friend std::istream &operator>>(std::istream &in, Alcohol &alcohol);

    Alcohol &operator++();
    Alcohol operator++(int);
    Alcohol &operator--();
    Alcohol operator--(int);
};

#endif

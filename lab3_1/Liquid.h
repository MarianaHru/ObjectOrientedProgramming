// Base class: Liquid.h
#ifndef LIQUID_H
#define LIQUID_H

#include <iostream>
#include <string>

class Liquid
{
protected:
    std::string name;
    double density;

public:
    Liquid();
    Liquid(const std::string &name, double density);
    Liquid(const Liquid &other);

    virtual ~Liquid() = default;

    std::string getName() const;
    double getDensity() const;

    void setName(const std::string &name);
    void setDensity(double density);

    void Init(const std::string &name, double density);
    void Read();
    void Display() const;

    operator std::string() const;

    Liquid &operator=(const Liquid &other);

    friend std::ostream &operator<<(std::ostream &out, const Liquid &liquid);
    friend std::istream &operator>>(std::istream &in, Liquid &liquid);
};

#endif

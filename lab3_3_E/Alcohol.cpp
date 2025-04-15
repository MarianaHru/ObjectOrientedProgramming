#include "Alcohol.h"
#include <sstream>

Alcohol::Alcohol() : Liquid(), strength(0.0) {}

Alcohol::Alcohol(const string &name, double density, double strength)
    : Liquid(name, density), strength(strength) {}

Alcohol::Alcohol(const Alcohol &other)
    : Liquid(other), strength(other.strength) {}

void Alcohol::Init(const string &strengthStr, const Liquid &liquid)
{
    *this = Alcohol(liquid.getName(), liquid.getDensity(), stod(strengthStr));
}

void Alcohol::Read()
{
    Liquid::Read();
    cout << "Enter strength (%): ";
    cin >> strength;
}

void Alcohol::Display() const
{
    cout << *this;
}

void Alcohol::setStrength(double strength)
{
    this->strength = strength;
}

double Alcohol::getStrength() const
{
    return strength;
}

Alcohol &Alcohol::operator=(const Alcohol &other)
{
    if (this != &other)
    {
        Liquid::operator=(other);
        strength = other.strength;
    }
    return *this;
}

ostream &operator<<(ostream &out, const Alcohol &a)
{
    out << string(a);
    return out;
}

istream &operator>>(istream &in, Alcohol &a)
{
    in >> static_cast<Liquid &>(a);
    cout << "Enter strength (%): ";
    in >> a.strength;
    return in;
}

Alcohol::operator string() const
{
    stringstream ss;
    ss << (Liquid::operator string())
       << "Strength: " << strength << "%" << endl;
    return ss.str();
}

Alcohol &Alcohol::operator++()
{
    ++strength;
    return *this;
}

Alcohol Alcohol::operator++(int)
{
    Alcohol temp(*this);
    strength++;
    return temp;
}

Alcohol &Alcohol::operator--()
{
    --strength;
    return *this;
}

Alcohol Alcohol::operator--(int)
{
    Alcohol temp(*this);
    strength--;
    return temp;
}

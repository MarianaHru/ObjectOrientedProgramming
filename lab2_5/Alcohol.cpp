// Alcohol.cpp
#include "Alcohol.h"

Alcohol::Alcohol() : liquid(), strength(0.0) {}
Alcohol::Alcohol(Liquid liquid, double strength) : liquid(liquid), strength(strength) {}
Alcohol::Alcohol(const Alcohol &other) : liquid(other.liquid), strength(other.strength) {}

Alcohol &Alcohol::operator=(const Alcohol &other)
{
    if (this != &other)
    {
        liquid = other.liquid;
        strength = other.strength;
    }
    return *this;
}

void Alcohol::Init(string spec, Liquid liquid)
{
    this->liquid = liquid;
    this->strength = stod(spec);
}

void Alcohol::Read()
{
    string spec;
    cout << "Enter liquid details:" << endl;
    liquid.Read();
    cout << "Enter alcohol strength (%): ";
    cin >> spec;
    Init(spec, liquid);
}

void Alcohol::Display() const
{
    cout << endl;
    cout << "man = ";
    liquid.Display();
    cout << "spec = " << strength << "%" << endl;
}

ostream &operator<<(ostream &out, const Alcohol &a)
{
    out << string(a);
    return out;
}
istream &operator>>(istream &in, Alcohol &a)
{
    string spec;
    cout << endl;
    cout << "man = ? ";
    in >> a.liquid;
    cout << "spec =? ";
    in >> spec;
    a.setStrength(stod(spec));
    return in;
}

void Alcohol::setStrength(double strength)
{
    this->strength = strength;
}

Alcohol::operator string() const
{
    return string(liquid) + " | Strength: " + to_string(strength) + "%";
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

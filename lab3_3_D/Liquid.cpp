// Liquid.cpp
#include "Liquid.h"

Liquid::Liquid() : name(""), density(0) {}

Liquid::Liquid(string n, double d) : name(n), density(d < 0 ? 0 : d) {}

void Liquid::Init(string n, double d)
{
    name = n;
    density = (d < 0 ? 0 : d);
}

void Liquid::Read()
{
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter density: ";
    cin >> density;
    if (density < 0)
        density = 0;
}

void Liquid::Display() const
{
    cout << "Name: " << name << ", Density: " << density << endl;
}

ostream &operator<<(ostream &out, const Liquid &l)
{
    out << string(l);
    return out;
}

istream &operator>>(istream &in, Liquid &l)
{
    cout << "Enter name: ";
    in >> l.name;
    cout << "Enter density: ";
    in >> l.density;
    if (l.density < 0)
        l.density = 0;
    return in;
}

Liquid::operator string() const
{
    return "Name: " + name + ", Density: " + to_string(density);
}

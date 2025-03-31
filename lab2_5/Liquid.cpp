// Liquid.cpp
#include "Liquid.h"

Liquid::Liquid() : name("Unknown"), density(0.0) {}
Liquid::Liquid(string name, double density) : name(name), density(density) {}
Liquid::Liquid(const Liquid &other) : name(other.name), density(other.density) {}

Liquid &Liquid::operator=(const Liquid &other)
{
    if (this != &other)
    {
        name = other.name;
        density = other.density;
    }
    return *this;
}

void Liquid::Init(string name, double density)
{
    this->name = name;
    this->density = density;
}

void Liquid::Read()
{
    cout << "Enter liquid name: ";
    cin >> name;
    cout << "Enter density: ";
    cin >> density;
}

void Liquid::Display() const
{
    cout << "Liquid: " << name << " | Density: " << density << endl;
}

string Liquid::getName() const { return name; }
double Liquid::getDensity() const { return density; }
void Liquid::setName(string name) { this->name = name; }
void Liquid::setDensity(double density) { this->density = (density >= 0) ? density : 0; }

ostream &operator<<(ostream &out, const Liquid &l)
{
    out << string(l);
    return out;
}
istream &operator>>(istream &in, Liquid &l)
{
    l.Read();
    return in;
}
Liquid::operator string() const { return "Liquid: " + name + " | Density: " + to_string(density); }

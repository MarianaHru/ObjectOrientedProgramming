#include "Alcohol.h"
#include <sstream>

int Alcohol::Liquid::counter = 0;
int Alcohol::counter = 0;

// Реалізація методів класу Liquid
Alcohol::Liquid::Liquid() : name(""), density(0) { counter++; }
Alcohol::Liquid::Liquid(string name, double density) : name(name), density(density) { counter++; }
Alcohol::Liquid::Liquid(const Liquid &l) : name(l.name), density(l.density) { counter++; }
Alcohol::Liquid::~Liquid() { counter--; }
Alcohol::Liquid &Alcohol::Liquid::operator=(const Liquid &l)
{
    name = l.name;
    density = l.density;
    return *this;
}
void Alcohol::Liquid::Display() const { cout << string(*this) << endl; }
void Alcohol::Liquid::Read()
{
    cout << "Enter liquid name: ";
    cin >> name;
    cout << "Enter density: ";
    cin >> density;
}
Alcohol::Liquid::operator string() const
{
    ostringstream oss;
    oss << "Liquid: " << name << " | Density: " << density;
    return oss.str();
}
int Alcohol::Liquid::getCounter() { return counter; }

ostream &operator<<(ostream &out, const Alcohol::Liquid &l)
{
    out << string(l);
    return out;
}

istream &operator>>(istream &in, Alcohol::Liquid &l)
{
    cout << "Enter liquid name: ";
    in >> l.name;
    cout << "Enter density: ";
    in >> l.density;
    return in;
}

// Реалізація методів класу Alcohol
Alcohol::Alcohol() : liquid(), strength(0) { counter++; }
Alcohol::Alcohol(string name, double density, double strength) : liquid(name, density), strength(strength) { counter++; }
Alcohol::Alcohol(const Alcohol &a) : liquid(a.liquid), strength(a.strength) { counter++; }
Alcohol::~Alcohol() { counter--; }
Alcohol &Alcohol::operator=(const Alcohol &a)
{
    liquid = a.liquid;
    strength = a.strength;
    return *this;
}
void Alcohol::Display() const { cout << string(*this) << endl; }
void Alcohol::Read()
{
    cout << "Liquid = ? " << endl;
    cin >> liquid;
    cout << "strength = ? ";
    cin >> strength;
}
Alcohol::operator string() const
{
    ostringstream oss;
    oss << string(liquid) << " | Strength: " << strength << "%";
    return oss.str();
}
Alcohol &Alcohol::operator++()
{
    strength++;
    return *this;
}
Alcohol &Alcohol::operator--()
{
    strength--;
    return *this;
}
Alcohol Alcohol::operator++(int)
{
    Alcohol temp(*this);
    strength++;
    return temp;
}
Alcohol Alcohol::operator--(int)
{
    Alcohol temp(*this);
    strength--;
    return temp;
}
int Alcohol::getCounter() { return counter; }

void Alcohol::Init(string name, double density, double strength)
{
    liquid = Liquid(name, density);
    this->strength = strength;
}

ostream &operator<<(ostream &out, const Alcohol &a)
{
    out << string(a);
    return out;
}

istream &operator>>(istream &in, Alcohol &a)
{
    cout << "Liquid = ? " << endl;
    in >> a.liquid;
    cout << "strength = ? ";
    in >> a.strength;
    return in;
}
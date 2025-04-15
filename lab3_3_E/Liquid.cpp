#include "Liquid.h"
#include <sstream>

Liquid::Liquid() : name(""), density(0.0) {}

Liquid::Liquid(const string &name, double density)
    : name(name), density(density) {}

Liquid::Liquid(const Liquid &other)
    : name(other.name), density(other.density) {}

void Liquid::Init(const string &name, double density)
{
    this->name = name;
    this->density = density;
}

void Liquid::Read()
{
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter density: ";
    cin >> density;
}

void Liquid::Display() const
{
    cout << *this;
}

void Liquid::setName(const string &name)
{
    this->name = name;
}

void Liquid::setDensity(double density)
{
    this->density = density;
}

string Liquid::getName() const
{
    return name;
}

double Liquid::getDensity() const
{
    return density;
}

Liquid &Liquid::operator=(const Liquid &other)
{
    if (this != &other)
    {
        name = other.name;
        density = other.density;
    }
    return *this;
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
    return in;
}

Liquid::operator string() const
{
    stringstream ss;
    ss << "Name: " << name << "\nDensity: " << density << endl;
    return ss.str();
}

Liquid &Liquid::operator++()
{
    ++density;
    return *this;
}

Liquid Liquid::operator++(int)
{
    Liquid temp(*this);
    density++;
    return temp;
}

Liquid &Liquid::operator--()
{
    --density;
    return *this;
}

Liquid Liquid::operator--(int)
{
    Liquid temp(*this);
    density--;
    return temp;
}

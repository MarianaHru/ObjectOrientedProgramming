
// Liquid.cpp
#include "Liquid.h"

void Liquid::setDensity(double density)
{
    if (density < 0)
    {
        cout << "Density cannot be negative. Setting to 0." << endl;
        this->density = 0;
    }
    else
    {
        this->density = density;
    }
}

void Liquid::Init(string name, double density)
{
    setName(name);
    setDensity(density);
}

string Liquid::toString() const
{
    return "Liquid: " + name + " | Density: " + to_string(density);
}

void Liquid::Display() const
{
    cout << toString() << endl;
}

void Liquid::Read()
{
    string name;
    double density;
    cout << "Enter liquid name: ";
    cin >> name;
    cout << "Enter density: ";
    cin >> density;
    Init(name, density);
}
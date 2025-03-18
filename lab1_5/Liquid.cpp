
#include "Liquid.h"

void Liquid::Init(string name, double density)
{
    setName(name);
    setDensity(density);
}

void Liquid::Display() const
{
    cout << "Liquid: " << name << " | Density: " << density << endl;
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
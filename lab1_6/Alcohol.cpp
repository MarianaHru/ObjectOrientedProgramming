#include "Alcohol.h"

// Реалізація методів класу Alcohol::Liquid
void Alcohol::Liquid::Init(string name, double density)
{
    setName(name);
    setDensity(density);
}

void Alcohol::Liquid::Display() const
{
    cout << toString() << endl;
}

void Alcohol::Liquid::Read()
{
    string name;
    double density;
    cout << "Enter liquid name: ";
    cin >> name;
    cout << "Enter density: ";
    cin >> density;
    Init(name, density);
}

string Alcohol::Liquid::toString() const
{
    ostringstream oss;
    oss << "Liquid: " << name << " | Density: " << density;
    return oss.str();
}

// Реалізація методів класу Alcohol
void Alcohol::Init(Liquid liquid, double strength)
{
    setLiquid(liquid);
    setStrength(strength);
}

void Alcohol::Display() const
{
    cout << toString() << endl;
}

void Alcohol::Read()
{
    Liquid liquid;
    double strength;
    cout << "Enter liquid details:" << endl;
    liquid.Read();
    cout << "Enter alcohol strength (%): ";
    cin >> strength;
    Init(liquid, strength);
}

string Alcohol::toString() const
{
    ostringstream oss;
    oss << liquid.toString() << " | Strength: " << strength << "%";
    return oss.str();
}
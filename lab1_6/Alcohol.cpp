#include "Alcohol.h"

// Реалізація методів класу Alcohol::Liquid
void Alcohol::Liquid::Init(string name, double density)
{
    setName(name);
    setDensity(density);
}

void Alcohol::Liquid::Display() const
{
    cout << "Liquid: " << name << " | Density: " << density << endl;
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

// Реалізація методів класу Alcohol
void Alcohol::Init(Liquid liquid, double strength)
{
    setLiquid(liquid);
    setStrength(strength);
}

void Alcohol::Display() const
{
    cout << "Alcohol details:" << endl;
    liquid.Display();
    cout << "Strength: " << strength << "%" << endl;
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

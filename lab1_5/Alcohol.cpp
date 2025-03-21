
// Alcohol.cpp
#include "Alcohol.h"

void Alcohol::Init(Liquid liquid, double strength)
{
    setLiquid(liquid);
    setStrength(strength);
}

string Alcohol::toString() const
{
    return liquid.toString() + " | Strength: " + to_string(strength) + "%";
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
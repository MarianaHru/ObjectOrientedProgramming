
#include "Alcohol.h"

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
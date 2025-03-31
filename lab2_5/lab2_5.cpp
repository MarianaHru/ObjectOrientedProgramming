// main.cpp
#include "Alcohol.h"
#include <iostream>
using namespace std;

#pragma pack(1)
struct PackedAlcohol
{
    Alcohol a;
};
#pragma pack()

#ifndef UNIT_TESTING

int main()
{
    Alcohol a1;
    cin >> a1;
    cout << a1 << endl;

    Liquid l1("Water", 1.0);
    Alcohol a2;
    a2.Init("40.0", l1);
    cout << a2 << endl;

    Alcohol drinks[3];
    for (int i = 0; i < 3; i++)
    {
        cout << "Enter details for drink " << i + 1 << ":\n";
        drinks[i].Read();
    }

    cout << "\nAlcohol list:" << endl;
    for (const auto &drink : drinks)
    {
        drink.Display();
    }

    cout << "Size of Alcohol class without #pragma pack(1): " << sizeof(Alcohol) << " bytes" << endl;
    cout << "Size of Alcohol class with #pragma pack(1): " << sizeof(PackedAlcohol) << " bytes" << endl;

    return 0;
}
#endif

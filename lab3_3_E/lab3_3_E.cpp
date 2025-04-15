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
    cout << "Created objects: " << Object::Count() << endl;

    Alcohol a1;
    cin >> a1;
    cout << a1 << endl;

    Liquid l1("Water", 1.0);
    Alcohol a2;
    a2.Init("40.0", l1);
    cout << a2 << endl;

    Alcohol drinks[3];
    for (int i = 0; i < 3; ++i)
    {
        cout << "\nEnter drink " << i + 1 << ":\n";
        drinks[i].Read();
    }

    cout << "\nAlcohol list:\n";
    for (const auto &drink : drinks)
        drink.Display();

    Alcohol a3 = a2++;
    cout << "\nPostfix ++:\n"
         << a3 << endl;

    Alcohol a4 = ++a2;
    cout << "\nPrefix ++:\n"
         << a4 << endl;

    cout << "Current object count: " << Object::Count() << endl;

    cout << "\nSize with #pragma pack(1): " << sizeof(PackedAlcohol) << " bytes\n";
    cout << "Size without #pragma pack: " << sizeof(Alcohol) << " bytes\n";

    return 0;
}
#endif


// main.cpp
#include "Alcohol.h"

#ifndef UNIT_TESTING

int main()
{
    Alcohol a1;
    a1.Read();
    a1.Display();

    Liquid l1;
    l1.Init("Water", 1.0);
    Alcohol a2;
    a2.Init(l1, 40.0);
    a2.Display();

    // Масив об'єктів
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

    return 0;
}

#endif

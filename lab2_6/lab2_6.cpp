#include "Alcohol.h"
#ifndef UNIT_TESTING
int main()
{
    cout << "Alcohol objects: " << Alcohol::getCounter() << endl;
    cout << "Liquid objects: " << Alcohol::Liquid::getCounter() << endl;

    Alcohol a1;
    cout << "After creating a1: " << Alcohol::getCounter() << endl;
    cin >> a1;
    cout << a1 << endl;

    Alcohol::Liquid l1;
    cout << "After creating l1: " << Alcohol::Liquid::getCounter() << endl;

    {
        Alcohol a2("Rum", 0.95, 40);
        cout << "Alcohol objects inside block: " << Alcohol::getCounter() << endl;
        cout << a2 << endl;

        Alcohol::Liquid l2("Water", 1.0);
        cout << "Liquid objects inside block: " << Alcohol::Liquid::getCounter() << endl;
    }

    cout << "After exiting block: " << Alcohol::getCounter() << endl;
    cout << "Liquid objects after block: " << Alcohol::Liquid::getCounter() << endl;

    Alcohol a3;
    a3.Init("Whiskey", 0.94, 43);
    cout << "a3 after Init: " << a3 << endl;

    cout << "Enter new alcohol data: " << endl;
    Alcohol a4;
    cin >> a4;
    cout << a4 << endl;

    return 0;
}
#endif
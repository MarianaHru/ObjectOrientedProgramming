// main.cpp
#include <iostream>
#include "AlcoholPublic.h"
#include "AlcoholPrivate.h"
using namespace std;

#ifndef UNIT_TESTING

int main()
{
    AlcoholPublic ap("Wine", 0.8, 40);
    AlcoholPrivate apr("Whiskey", 0.9, 45);

    cout << "\nAlcoholPublic object:" << endl;
    ap.Display();

    cout << "\nAlcoholPrivate object:" << endl;
    apr.Display();

    cout << "\nUsing operator string():" << endl;
    cout << string(ap) << endl;
    cout << apr << endl;

    cout << "\nPostfix increment AlcoholPublic:" << endl;
    ap++;
    ap.Display();

    cout << "\nPrefix decrement AlcoholPrivate:" << endl;
    --apr;
    apr.Display();

    return 0;
}
#endif
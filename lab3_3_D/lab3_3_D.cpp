// main.cpp
#include <iostream>
#include "AlcoholPublic.h"
#include "AlcoholPrivate.h"
using namespace std;

#ifndef UNIT_TESTING

int main()
{
    AlcoholPublic ap1("Wine", 0.8, 40);
    AlcoholPrivate apr1("Whiskey", 0.9, 45);

    cout << "\nInitial AlcoholPublic object (ap1):" << endl;
    ap1.Display();

    cout << "\nInitial AlcoholPrivate object (apr1):" << endl;
    apr1.Display();

    // Використання конструктора копіювання
    AlcoholPublic ap2 = ap1;
    AlcoholPrivate apr2 = apr1;

    cout << "\nCopied AlcoholPublic object (ap2):" << endl;
    ap2.Display();

    cout << "\nCopied AlcoholPrivate object (apr2):" << endl;
    apr2.Display();

    // Зміна оригінального об'єкта, щоб побачити, що копія не змінилася
    ap1++;
    --apr1;

    cout << "\nOriginal AlcoholPublic object (ap1) after increment:" << endl;
    ap1.Display();

    cout << "\nCopied AlcoholPublic object (ap2) remains the same:" << endl;
    ap2.Display();

    cout << "\nOriginal AlcoholPrivate object (apr1) after decrement:" << endl;
    apr1.Display();

    cout << "\nCopied AlcoholPrivate object (apr2) remains the same:" << endl;
    apr2.Display();

    // Використання оператора присвоєння
    AlcoholPublic ap3("Beer", 1.0, 5);
    AlcoholPrivate apr3("Vodka", 0.95, 40);

    cout << "\nInitial AlcoholPublic object (ap3):" << endl;
    ap3.Display();

    cout << "\nInitial AlcoholPrivate object (apr3):" << endl;
    apr3.Display();

    ap3 = ap1;
    apr3 = apr1;

    cout << "\nAlcoholPublic object (ap3) after assignment from ap1:" << endl;
    ap3.Display();

    cout << "\nAlcoholPrivate object (apr3) after assignment from apr1:" << endl;
    apr3.Display();

    cout << "\nUsing operator string():" << endl;
    cout << string(ap1) << endl;
    cout << apr1 << endl;

    cout << "\nPostfix increment AlcoholPublic (ap1):" << endl;
    AlcoholPublic ap4 = ap1++;
    ap1.Display();
    cout << "Value returned by postfix increment (ap4):" << endl;
    ap4.Display();

    cout << "\nPrefix decrement AlcoholPrivate (apr1):" << endl;
    AlcoholPrivate apr4 = --apr1;
    apr1.Display();
    cout << "Value returned by prefix decrement (apr4):" << endl;
    apr4.Display();

    return 0;
}
#endif
#include <iostream>
#include "Money.h"

using namespace std;

#ifndef UNIT_TESTING

int main()
{
#pragma pack(1)
    cout << "Size of Money with #pragma pack(1): " << sizeof(Money) << " bytes" << endl;
#pragma pack()
    cout << "Size of Money without #pragma pack(1): " << sizeof(Money) << " bytes" << endl;

    Money m1, m2(10, 50), m3(m2);

    cout << "Enter first amount:" << endl;
    cin >> m1;
    cout << "m1: " << m1 << endl;
    cout << "m2 (initialized): " << m2 << endl;
    cout << "m3 (copied from m2): " << m3 << endl;

    Money sum = m1 + m2;
    cout << "Sum: " << sum << endl;

    if (m2 != Money(0, 0))
    {
        double div = m1 / m2;
        cout << "Division m1 / m2: " << div << endl;
    }

    cout << "Prefix increment: " << ++m1 << endl;
    cout << "Postfix increment: " << m1++ << endl;
    cout << "After increment: " << m1 << endl;

    cout << "Prefix decrement: " << --m1 << endl;
    cout << "Postfix decrement: " << m1-- << endl;
    cout << "After decrement: " << m1 << endl;

    return 0;
}
#endif
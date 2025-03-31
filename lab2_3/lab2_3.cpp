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

    cout << "Enter first amount (format: hryvna,kopek):" << endl;
    string input;
    getline(cin, input);
    m1.fromString(input);

    cout << "m1: " << m1.toString() << endl;
    cout << "m2 (initialized): " << m2.toString() << endl;
    cout << "m3 (copied from m2): " << m3.toString() << endl;

    Money sum = m1 + m2;
    cout << "Sum: " << sum.toString() << endl;

    if (m2 != Money(0, 0))
    {
        double div = m1 / m2;
        cout << "Division m1 / m2: " << div << endl;
    }
    else
    {
        cout << "Cannot divide by zero money" << endl;
    }

    cout << "Prefix increment: " << (++m1).toString() << endl;
    cout << "Postfix increment: " << (m1++).toString() << endl;
    cout << "After increment: " << m1.toString() << endl;

    cout << "Prefix decrement: " << (--m1).toString() << endl;
    cout << "Postfix decrement: " << (m1--).toString() << endl;
    cout << "After decrement: " << m1.toString() << endl;

    // Додано перевірку на нерівність
    if (m1 != m2)
    {
        cout << "m1 is not equal to m2" << endl;
    }
    else
    {
        cout << "m1 is equal to m2" << endl;
    }

    return 0;
}
#endif
#include <iostream>
#include <iomanip>
#include "Money.h"

using namespace std;

#ifndef UNIT_TESTING

int main()
{
    Money m1, m2;

    m1.Read();
    m1.Display();
    cout << endl;

    m2.Read();
    m2.Display();
    cout << endl;

    double divisor;

    cout << "Enter divisor: ";
    cin >> divisor;

    Money sum = m1 + m2;
    cout << "Sum: " << sum.toString() << endl;

    double div = m1 / m2;

    cout << "Division is: " << div << endl;

    if (divisor != 0)
    {
        Money result = m1 / divisor;
        cout << "1. Division by " << divisor << " is: " << result.toString() << endl;
    }
    else
    {
        cout << "Error: divisor is 0" << endl;
    }
    if (divisor != 0)
    {
        Money result = m2 / divisor;
        cout << "2. Division by " << divisor << " is: " << result.toString() << endl;
    }
    else
    {
        cout << "Error: divisor is 0" << endl;
    }

    return 0;
}

#endif
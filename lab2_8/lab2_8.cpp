#include <iostream>
#include <iomanip>
#include "Calculator.h"

using namespace std;
#ifndef UNIT_TESTING
int main()
{
    Calculator c1, c2;

    cout << "Enter first fraction: " << endl;
    cin >> c1;

    cout << "Enter second fraction: " << endl;
    cin >> c2;

    cout << "First fraction: " << c1 << endl;
    cout << "Second fraction: " << c2 << endl;

    Calculator sum = c1 + c2;
    cout << "Sum: " << sum << endl;

    Calculator diff = c1 - c2;
    cout << "Different: " << diff << endl;

    Calculator mult = c1 * c2;
    cout << "Multiplication: " << mult << endl;

    if (c1 == c2)
    {
        cout << "The numbers are equal" << endl;
    }
    else if (c1 != c2)
    {
        cout << "The numbers aren't equal" << endl;
    }

    if (c1 < c2)
    {
        cout << "The first number is less than second" << endl;
    }
    else if (c1 > c2)
    {
        cout << "The second number is greater than second" << endl;
    }

    if (c1 <= c2)
    {
        cout << "The first number is less-equal than second" << endl;
    }
    else if (c1 >= c2)
    {
        cout << "the first number is greater-equal than second" << endl;
    }

    return 0;
}
#endif
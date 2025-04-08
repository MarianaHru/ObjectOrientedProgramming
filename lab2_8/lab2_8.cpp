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
    cout << "Difference: " << diff << endl;

    Calculator mult = c1 * c2;
    cout << "Multiplication: " << mult << endl;

    if (c1 == c2)
        cout << "The numbers are equal" << endl;
    else
        cout << "The numbers aren't equal" << endl;

    if (c1 < c2)
        cout << "The first number is less than second" << endl;
    else if (c1 > c2)
        cout << "The first number is greater than second" << endl;

    if (c1 <= c2)
        cout << "The first number is less or equal to the second" << endl;
    else
        cout << "The first number is greater than or equal to the second" << endl;

    cout << "\nActive Calculator objects: " << Calculator::GetCount() << endl;
    cout << "Active Fraction objects: " << Calculator::Fraction::GetCount() << endl;

    return 0;
}
#endif

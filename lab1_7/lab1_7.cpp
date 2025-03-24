#include <iostream>
#include <iomanip>
#include "Calculator.h"

using namespace std;
#ifndef UNIT_TESTING
int main()
{
    Calculator n1, n2;

    n1.Read();
    n1.Display();
    cout << endl;

    n2.Read();
    n2.Display();
    cout << endl;

    Calculator sum = n1 + n2;
    cout << "Sum: " << sum.toString() << endl;

    Calculator diff = n1 - n2;
    cout << "Different: " << diff.toString() << endl;

    Calculator mult = n1 * n2;
    cout << "Multiplication: " << mult.toString() << endl;

    if (n1 == n2)
    {
        cout << "The numbers are equal" << endl;
    }
    else if (n1 != n2)
    {
        cout << "The numbers aren't equal" << endl;
    }

    if (n1 < n2)
    {
        cout << "The first number is less than second" << endl;
    }

    if (n1 > n2)
    {
        cout << "The second number is greater than second";
    }

    return 0;
}
#endif
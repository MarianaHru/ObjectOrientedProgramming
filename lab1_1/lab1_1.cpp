#include "Fraction.h"
#include "Fracrion.cpp"

#ifndef UNIT_TESTING

int main()
{
    int num, denom;
    cout << "Enter numerator: ";
    cin >> num;
    cout << "Enter denominator: ";
    cin >> denom;

    Fraction fraction(num, denom);
    cout << "Fraction: ";
    fraction.Display();
    cout << "Integer part: " << fraction.ipart() << endl;

    return 0;
}

#endif

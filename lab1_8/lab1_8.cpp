// main.cpp
#include "Fraction.h"
#include <iostream>

using namespace std;
#ifndef UNIT_TESTING
int main()
{
    Calculator calc1, calc2, result;

    cout << "Enter first fraction:" << endl;
    calc1.Read();

    cout << "Enter second fraction:" << endl;
    calc2.Read();

    cout << "\nFirst fraction: ";
    calc1.Display();

    cout << "Second fraction: ";
    calc2.Display();

    // Додавання
    result = calc1 + calc2;
    cout << "Sum: ";
    result.Display();

    // Віднімання
    result = calc1 - calc2;
    cout << "Difference: ";
    result.Display();

    // Множення
    result = calc1 * calc2;
    cout << "Product: ";
    result.Display();

    // Порівняння
    cout << "Comparison results:" << endl;
    cout << "calc1 == calc2: " << (calc1 == calc2 ? "true" : "false") << endl;
    cout << "calc1 != calc2: " << (calc1 != calc2 ? "true" : "false") << endl;
    cout << "calc1 < calc2: " << (calc1 < calc2 ? "true" : "false") << endl;
    cout << "calc1 > calc2: " << (calc1 > calc2 ? "true" : "false") << endl;

    return 0;
}
#endif
#include "Calculator.h"
#include <iostream>

#ifndef UNIT_TESTING

int main()
{
    Calculator::Fraction f1, f2;
    f1.Read();
    f2.Read();

    std::cout << "First fraction: ";
    f1.Display();
    std::cout << "Second fraction: ";
    f2.Display();

    Calculator::Fraction sum = Calculator::Add(f1, f2);
    std::cout << "Sum: ";
    sum.Display();

    Calculator::Fraction difference = Calculator::Subtract(f1, f2);
    std::cout << "Difference: ";
    difference.Display();

    Calculator::Fraction product = Calculator::Multiply(f1, f2);
    std::cout << "Product: ";
    product.Display();

    std::cout << "Comparison (Equal): " << (Calculator::Compare(f1, f2) ? "Yes" : "No") << std::endl;

    return 0;
}

#endif
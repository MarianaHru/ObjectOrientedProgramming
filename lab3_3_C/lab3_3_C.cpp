// main.cpp
#include "Money.h"
#include <iostream>
#ifndef UNIT_TESTING
int main()
{
    Money a(10, 50);
    Money b(5, 75);

    std::cout << "Money A: " << a << std::endl;
    std::cout << "Money B: " << b << std::endl;

    Money sum = a + b;
    std::cout << "Sum: " << sum << std::endl;

    Money div = a / 2.0;
    std::cout << "A divided by 2: " << div << std::endl;

    double ratio = a / b;
    std::cout << "A divided by B: " << ratio << std::endl;

    std::cout << "Prefix ++A: " << ++a << std::endl;
    std::cout << "Postfix B++: " << b++ << std::endl;
    std::cout << "Now B: " << b << std::endl;

    std::cout << "Prefix --A: " << --a << std::endl;
    std::cout << "Postfix B--: " << b-- << std::endl;
    std::cout << "Now B: " << b << std::endl;

    std::string str = static_cast<std::string>(a);
    std::cout << "A as string: " << str << std::endl;

    return 0;
}
#endif
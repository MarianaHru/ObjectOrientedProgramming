#include <iostream>
#include "Fraction.h"

#ifndef UNIT_TESTING
int main()
{
    Fraction f1;
    Fraction f2(3, 4);
    Fraction f3 = f2;
    Fraction f4 = makeFraction(5, 6);

    std::cout << "f1: " << f1 << std::endl;
    std::cout << "f2: " << f2 << std::endl;
    std::cout << "f3: " << f3 << std::endl;
    std::cout << "f4: " << f4 << std::endl;

    Fraction f5;
    std::cin >> f5;
    std::cout << "Ви ввели: " << f5 << std::endl;

    std::cout << "Префіксний інкремент f2: " << ++f2 << std::endl;
    std::cout << "Постфіксний інкремент f2: " << f2++ << std::endl;
    std::cout << "Префіксний декремент f2: " << --f2 << std::endl;
    std::cout << "Постфіксний декремент f2: " << f2-- << std::endl;

    std::string strF2 = f2.toString();
    std::cout << "f2 у рядковому вигляді: " << strF2 << std::endl;

    return 0;
}
#endif

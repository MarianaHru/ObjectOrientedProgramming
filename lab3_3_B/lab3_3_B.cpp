#include "Money.h"
#include "Pair.h"
#include <iostream>
#include <string>
#ifndef UNIT_TESTING
int main()
{
    std::cout << "Демонстрація класу Pair:" << std::endl;
    Pair p1;
    std::cout << "Початкове значення p1: " << p1 << std::endl;

    std::cout << "Введіть значення для p1 (формат: (число,число)): ";
    std::cin >> p1;
    std::cout << "Значення p1 після введення: " << p1 << std::endl;

    std::cout << "\nДемонстрація класу Money:" << std::endl;
    Money m1;
    std::cout << "Початкове значення m1: " << m1 << std::endl;

    std::cout << "Введіть значення для m1 (формат: (гривні,копійки)): ";
    std::cin >> m1;
    std::cout << "Значення m1 після введення: " << m1 << std::endl;
    std::cout << "m1 у форматі гривні,копійки: " << m1.toString() << std::endl;

    Money m2(50, 75);
    std::cout << "m2: " << m2 << std::endl;

    Money sum = m1 + m2;
    std::cout << "Сума m1 та m2: " << sum << std::endl;

    if (m1 > m2)
    {
        std::cout << "m1 більша за m2" << std::endl;
    }
    else
    {
        std::cout << "m2 більша або дорівнює m1" << std::endl;
    }

    return 0;
}
#endif
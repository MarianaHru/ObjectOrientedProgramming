// Main.cpp
#include "Liquid.h"
#include "Alcohol.h"
#include <iostream>
#include <vector>

// Функція, яка приймає та повертає об'єкти базового класу
Liquid processLiquid(Liquid liquid)
{
    std::cout << "Обробка рідини всередині функції: " << liquid << std::endl;
    return liquid;
}
#ifndef UNIT_TESTING
int main()
{
    // Створення об'єктів різними способами
    Liquid water1;
    Liquid water2("Питна вода", 1.0);
    Liquid water3(water2);

    Alcohol wine1;
    Alcohol wine2("Виноградний сік", 1.05, 12.5);
    Alcohol wine3(wine2);
    Alcohol wine4(water2, 5.0); // Створення Alcohol з об'єкта Liquid

    std::cout << "Обробка рідини water1:\n";
    water1.Read();
    std::cout << "water1: " << water1 << std::endl;

    std::cout << "\nОбробка рідини water2: " << water2 << std::endl;
    std::cout << "Обробка рідини water3: " << water3 << std::endl;

    std::cout << "\nОбробка алкоголю wine1:\n";
    wine1.Read();
    std::cout << "wine1: " << wine1 << std::endl;

    std::cout << "\nОбробка алкоголю wine2: " << wine2 << std::endl;
    std::cout << "Обробка алкоголю wine3: " << wine3 << std::endl;
    std::cout << "Обробка алкоголю wine4: " << wine4 << std::endl;

    // Демонстрація методів отримання та встановлення
    std::cout << "\nДемонстрація методів:\n";
    water1.setName("Очищена вода");
    water1.setDensity(0.998);
    std::cout << "water1 після змін: " << water1 << std::endl;
    std::cout << "Назва water2: " << water2.getName() << ", густина: " << water2.getDensity() << std::endl;

    wine1.setName("Яблучний сік");
    wine1.setDensity(1.01);
    wine1.setStrength(6.0);
    std::cout << "wine1 після змін: " << wine1 << std::endl;
    std::cout << "Назва wine2: " << wine2.getName() << ", густина: " << wine2.getDensity()
              << ", міцність: " << wine2.getStrength() << std::endl;

    // Демонстрація оператора приведення до рядка
    std::cout << "\nПеретворення до рядка:\n";
    std::string water1_str = static_cast<std::string>(water1);
    std::string wine2_str = static_cast<std::string>(wine2);
    std::cout << "water1 як рядок: " << water1_str << std::endl;
    std::cout << "wine2 як рядок: " << wine2_str << std::endl;

    // Демонстрація операторів введення/виведення (вже використовується вище)

    // Демонстрація функції, що приймає та повертає базовий клас
    std::cout << "\nДемонстрація функції processLiquid:\n";
    Liquid processedWater = processLiquid(water2);
    std::cout << "Обробка рідини після функції: " << processedWater << std::endl;

    // Демонстрація принципу підстановки
    std::cout << "\nДемонстрація принципу підстановки:\n";
    Liquid *liquidPtr1 = &water1;
    std::cout << "Об'єкт Liquid через покажчик: " << *liquidPtr1 << std::endl;

    Liquid *liquidPtr2 = &wine2; // Покажчик на базовий клас вказує на об'єкт похідного класу
    std::cout << "Об'єкт Alcohol через покажчик на Liquid: " << *liquidPtr2 << std::endl;
    // Зверніть увагу, що через покажчик на базовий клас ви можете отримати доступ лише до членів базового класу.

    // Демонстрація масивів об'єктів
    std::cout << "\nДемонстрація масивів об'єктів:\n";
    Liquid liquidArray[2];
    std::cout << "Введіть дані для першої рідини в масиві:\n";
    liquidArray[0].Read();
    std::cout << "Введіть дані для другої рідини в масиві:\n";
    liquidArray[1].Read();

    std::cout << "\nМасив рідин:\n";
    for (const auto &liquid : liquidArray)
    {
        std::cout << liquid << std::endl;
    }

    std::vector<Alcohol> alcoholVector(2);
    std::cout << "\nВведіть дані для першого напою в векторі:\n";
    std::cin >> alcoholVector[0];
    std::cout << "\nВведіть дані для другого напою в векторі:\n";
    std::cin >> alcoholVector[1];

    std::cout << "\nВектор напоїв:\n";
    for (const auto &alcohol : alcoholVector)
    {
        std::cout << alcohol << std::endl;
    }

    // Демонстрація операторів інкременту та декременту для Alcohol
    std::cout << "\nДемонстрація операторів інкременту та декременту:\n";
    std::cout << "wine2 до інкременту: " << wine2 << std::endl;
    ++wine2;
    std::cout << "wine2 після префіксного інкременту: " << wine2 << std::endl;
    wine2++;
    std::cout << "wine2 після постфіксного інкременту: " << wine2 << std::endl;
    --wine2;
    std::cout << "wine2 після префіксного декременту: " << wine2 << std::endl;
    wine2--;
    std::cout << "wine2 після постфіксного декременту: " << wine2 << std::endl;

    return 0;
}
#endif
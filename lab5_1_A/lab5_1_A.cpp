#include "Fraction.h"
#include <iostream>
#ifndef UNIT_TESTING
int main()
{
    try
    {
        Fraction f1(5, 0); // Створює std::invalid_argument (передається за значенням)
    }
    catch (std::invalid_argument e)
    { // ЗА ЗНАЧЕННЯМ
        std::cout << "[catch by VALUE] std::invalid_argument: " << e.what() << '\n';
    }

    try
    {
        Fraction f2;
        f2.setSecond(0); // Той самий виняток, але інший спосіб
    }
    catch (const std::invalid_argument &e)
    { // ЗА ПОСИЛАННЯМ
        std::cout << "[catch by REFERENCE] std::invalid_argument: " << e.what() << '\n';
    }

    try
    {
        Fraction f3;
        f3.setFirst(-10); // Кидає OwnException (власний виняток)
    }
    catch (OwnException e)
    { // ЗА ЗНАЧЕННЯМ
        std::cout << "[catch by VALUE] OwnException: " << e.what() << '\n';
    }

    try
    {
        Fraction f4;
        f4.Init(-5, 0); // Викидає FractionException за посиланням або вказівником
    }
    catch (FractionException &e)
    { // ЗА ПОСИЛАННЯМ
        std::cout << "[catch by REFERENCE] FractionException: " << e.what() << '\n';
    }
    catch (FractionException *e)
    { // ЗА ВКАЗІВНИКОМ
        std::cout << "[catch by POINTER] FractionException: " << e->what() << '\n';
        delete e;
    }

    try
    {
        throw std::bad_exception(); // ЯВНО кидаємо std::bad_exception
    }
    catch (std::bad_exception &)
    { // за посиланням (можна й за значенням)
        std::cout << "[catch] std::bad_exception caught\n";
    }

    return 0;
}
#endif
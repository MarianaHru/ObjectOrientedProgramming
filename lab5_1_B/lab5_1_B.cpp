#include "Money.h"
#include "MoneyException.h"
#include <iostream>
#ifndef UNIT_TESTING
int main()
{
    try
    {
        Money m1(10, 50);
        Money m2(5, 75);

        std::cout << "m1 = " << m1 << "\n";
        std::cout << "m2 = " << m2 << "\n";

        Money sum = m1 + m2;
        std::cout << "Сума: " << sum << "\n";

        double ratio = m1 / m2;
        std::cout << "Відношення m1/m2: " << ratio << "\n";

        Money divided = m1 / 2.0;
        std::cout << "m1 поділений на 2: " << divided << "\n";

        ++m1;
        std::cout << "Після ++m1: " << m1 << "\n";

        m1--;
        std::cout << "Після m1--: " << m1 << "\n";

        // 1. Виняток за значенням
        try
        {
            throw MoneySimpleException("Виняток за значенням");
        }
        catch (MoneySimpleException e)
        {
            std::cerr << "[За значенням] " << e.getMessage() << "\n";
        }

        // 2. Виняток за посиланням
        try
        {
            throw MoneySimpleException("Виняток за посиланням");
        }
        catch (const MoneySimpleException &e)
        {
            std::cerr << "[За посиланням] " << e.getMessage() << "\n";
        }

        // 3. Виняток за вказівником
        try
        {
            throw new MoneySimpleException("Виняток за вказівником");
        }
        catch (MoneySimpleException *e)
        {
            std::cerr << "[За вказівником] " << e->getMessage() << "\n";
            delete e;
        }
    }
    catch (const MoneySimpleException &e)
    {
        std::cerr << "MoneySimpleException: " << e.getMessage() << "\n";
    }
    catch (const MoneyTooSmallException &e)
    {
        std::cerr << "MoneyTooSmallException: " << e.what() << "\n";
    }
    catch (const std::exception &e)
    {
        std::cerr << "Стандартний виняток: " << e.what() << "\n";
    }

    return 0;
}
#endif

// #include <iostream>
// #include "Money.h"
// #include "MoneyException.h"

// int main()
// {
//     try
//     {
//         Money m1(10, 50);
//         Money m2(5, 75);

//         std::cout << "m1 = " << m1 << std::endl;
//         std::cout << "m2 = " << m2 << std::endl;

//         Money sum = m1 + m2;
//         std::cout << "Сума: " << sum << std::endl;

//         double ratio = m1 / m2;
//         std::cout << "Відношення m1/m2: " << ratio << std::endl;

//         Money half = m1 / 2;
//         std::cout << "m1 поділений на 2: " << half << std::endl;

//         ++m1;
//         std::cout << "Після ++m1: " << m1 << std::endl;

//         m1--;
//         std::cout << "Після m1--: " << m1 << std::endl;

//         // Виклик винятку: некоректні копійки
//         Money wrong(10, 150);
//     }
//     catch (const MoneySimpleException &e)
//     {
//         std::cerr << "Виняток: " << e.what() << std::endl;
//     }

//     try
//     {
//         Money m1(10, 50);
//         Money zero(0, 0); // Виняток: ділення на 0
//         double res = m1 / zero;
//         std::cout << "Результат ділення на нуль: " << res << std::endl;
//     }
//     catch (const MoneyTooSmallException &e)
//     {
//         std::cerr << "Виняток: " << e.what() << std::endl;
//     }

//     return 0;
// }

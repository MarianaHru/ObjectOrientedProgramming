#include "Money.h"
#include "MoneyException.h"
#include <iostream>
#ifndef UNIT_TESTING
int main()
{
    try
    {
        // Створення об'єктів Money
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

        // --- Генерація винятків ---

        // 1. Декремент до нуля -> std::underflow_error (передача за вказівником)
        Money zero(0, 0);
        zero--; // зловимо під час catch (std::underflow_error*)

        // 2. Некоректні копійки (std::invalid_argument через конструктор)
        Money wrongKopek(5, 150); // копійки більше 100 -> стандартний виняток

        // 3. Невірний формат рядка (невірна валюта) -> MoneyException
        Money wrongCurrency;
        wrongCurrency.fromString("100,50 USD"); // валюта не "UAH" -> власний виняток

        // 4. Ділення на нульовий Money об'єкт -> std::domain_error
        Money mzero(0, 0);
        double res = m1 / mzero; // поділ на 0 гривень

        // 5. Спеціально кидаємо виняток-нащадок
        throw MoneyTooSmallException("Сума занадто мала!"); // за значенням
    }
    catch (MoneyTooSmallException ex) // власний виняток-нащадок за значенням
    {
        std::cerr << "MoneyTooSmallException: " << ex.what() << '\n';
    }
    catch (MoneyException &ex) // власний виняток за посиланням
    {
        std::cerr << "MoneyException: " << ex.what() << '\n';
    }
    catch (std::invalid_argument &ex) // стандартний виняток за посиланням
    {
        std::cerr << "Invalid Argument: " << ex.what() << '\n';
    }
    catch (std::domain_error &ex) // стандартний виняток за посиланням
    {
        std::cerr << "Domain Error: " << ex.what() << '\n';
    }
    catch (std::underflow_error *ex) // стандартний виняток за вказівником
    {
        std::cerr << "Underflow Error: " << ex->what() << '\n';
        delete ex; // обов'язково очищаємо пам'ять
    }
    catch (...)
    {
        std::cerr << "Невідомий виняток!\n";
    }

    return 0;
}
#endif

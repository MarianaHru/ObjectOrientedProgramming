#include <iostream>
#include "MoneyPrivate.h"

int main()
{
    // Створення об'єктів MoneyPrivate
    MoneyPrivate m1, m2(10, 50);

    std::cout << "Enter first amount (format: hryvna,kopek):\n";
    std::string input;
    std::getline(std::cin, input);
    m1.fromString(input);

    std::cout << "m1: " << m1.toString() << std::endl;
    std::cout << "m2: " << m2.toString() << std::endl;

    MoneyPrivate sum = m1 + m2;
    std::cout << "Sum: " << sum.toString() << std::endl;

    // Перевірка ділення
    try
    {
        double div = m1 / m2;
        std::cout << "Division m1 / m2: " << div << std::endl;
    }
    catch (const std::invalid_argument &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}

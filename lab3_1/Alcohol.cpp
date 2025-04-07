// Implementation: Alcohol.cpp
#include "Alcohol.h"
#include <iostream>
#include <stdexcept>

// Конструктори
Alcohol::Alcohol() : Liquid(), strength(0.0) {}

Alcohol::Alcohol(const std::string &name, double density, double strength)
    : Liquid(name, density), strength(strength)
{
    if (strength < 0)
    {
        throw std::invalid_argument("Міцність не може бути від'ємною.");
    }
}

Alcohol::Alcohol(const Liquid &liquid, double strength)
    : Liquid(liquid), strength(strength)
{
    if (strength < 0)
    {
        throw std::invalid_argument("Міцність не може бути від'ємною.");
    }
}

Alcohol::Alcohol(const Alcohol &other)
    : Liquid(other), strength(other.strength) {}

// Методи отримання та встановлення значень
double Alcohol::getStrength() const
{
    return strength;
}

void Alcohol::setStrength(double strength)
{
    if (strength < 0)
    {
        throw std::invalid_argument("Міцність не може бути від'ємною.");
    }
    this->strength = strength;
}

// Ініціалізація
void Alcohol::Init(const std::string &name, double density, double strength)
{
    Liquid::Init(name, density);
    setStrength(strength);
}

void Alcohol::Read()
{
    std::string inputName;
    double inputDensity;
    double inputStrength;

    std::cout << "Введіть назву алкоголю: ";
    std::cin >> inputName;
    std::cout << "Введіть густину алкоголю: ";
    std::cin >> inputDensity;
    std::cout << "Введіть міцність алкоголю: ";
    std::cin >> inputStrength;

    Init(inputName, inputDensity, inputStrength);
}

void Alcohol::Display() const
{
    Liquid::Display();
    std::cout << "Міцність: " << strength << "%" << std::endl;
}

// Перетворення до рядка
Alcohol::operator std::string() const
{
    return Liquid::operator std::string() + ", Міцність: " + std::to_string(strength) + "%";
}

std::ostream &operator<<(std::ostream &out, const Alcohol &alcohol)
{
    out << std::string(alcohol);
    return out;
}

std::istream &operator>>(std::istream &in, Alcohol &alcohol)
{
    std::string inputName;
    double inputDensity;
    double inputStrength;

    std::cout << "Введіть назву алкоголю: ";
    in >> inputName;
    std::cout << "Введіть густину алкоголю: ";
    in >> inputDensity;
    std::cout << "Введіть міцність алкоголю: ";
    in >> inputStrength;

    alcohol.Init(inputName, inputDensity, inputStrength);
    return in;
}

// Оператори інкременту та декременту
Alcohol &Alcohol::operator++()
{
    setStrength(strength + 1);
    return *this;
}

Alcohol Alcohol::operator++(int)
{
    Alcohol temp(*this);
    setStrength(strength + 1);
    return temp;
}

Alcohol &Alcohol::operator--()
{
    setStrength(strength - 1);
    return *this;
}

Alcohol Alcohol::operator--(int)
{
    Alcohol temp(*this);
    setStrength(strength - 1);
    return temp;
}

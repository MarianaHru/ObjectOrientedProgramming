// Implementation: Liquid.cpp
#include "Liquid.h"
#include <iostream>
#include <stdexcept>

// Конструктори
Liquid::Liquid() : name("Unknown"), density(0.0) {}

Liquid::Liquid(const std::string &name, double density) : name(name), density(density)
{
    if (density < 0)
    {
        throw std::invalid_argument("Density cannot be negative.");
    }
}

Liquid::Liquid(const Liquid &other) : name(other.name), density(other.density) {}

// Методи отримання значень
std::string Liquid::getName() const
{
    return name;
}

double Liquid::getDensity() const
{
    return density;
}

// Методи встановлення значень
void Liquid::setName(const std::string &name)
{
    this->name = name;
}

void Liquid::setDensity(double density)
{
    if (density < 0)
    {
        throw std::invalid_argument("Density cannot be negative.");
    }
    this->density = density;
}

// Ініціалізація
void Liquid::Init(const std::string &name, double density)
{
    setName(name);
    setDensity(density);
}

void Liquid::Read()
{
    std::string inputName;
    double inputDensity;

    std::cout << "Enter liquid name: ";
    std::cin >> inputName;
    std::cout << "Enter liquid density: ";
    std::cin >> inputDensity;

    Init(inputName, inputDensity);
}

void Liquid::Display() const
{
    std::cout << "Liquid Name: " << name << "\nDensity: " << density << std::endl;
}

// Перетворення до рядка
Liquid::operator std::string() const
{
    return "Liquid(Name: " + name + ", Density: " + std::to_string(density) + ")";
}

std::ostream &operator<<(std::ostream &out, const Liquid &liquid)
{
    out << std::string(liquid);
    return out;
}

std::istream &operator>>(std::istream &in, Liquid &liquid)
{
    std::string inputName;
    double inputDensity;

    std::cout << "Enter liquid name: ";
    in >> inputName;
    std::cout << "Enter liquid density: ";
    in >> inputDensity;

    liquid.Init(inputName, inputDensity);
    return in;
}

Liquid &Liquid::operator=(const Liquid &other)
{
    if (this != &other)
    {
        name = other.name;
        density = other.density;
    }
    return *this;
}

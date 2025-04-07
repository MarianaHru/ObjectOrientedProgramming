// Base class: Liquid.h
#ifndef LIQUID_H
#define LIQUID_H

#include <iostream>
#include <string>

class Liquid
{
protected:
    std::string name;
    double density;

public:
    // Конструктори
    Liquid();
    Liquid(const std::string &name, double density);
    Liquid(const Liquid &other);

    // Деструктор
    virtual ~Liquid() = default;

    // Методи отримання значень
    std::string getName() const;
    double getDensity() const;

    // Методи встановлення значень
    void setName(const std::string &name);
    void setDensity(double density);

    // Ініціалізація
    void Init(const std::string &name, double density);
    void Read();
    void Display() const;

    // Перетворення до рядка
    operator std::string() const;

    friend std::ostream &operator<<(std::ostream &out, const Liquid &liquid);
    friend std::istream &operator>>(std::istream &in, Liquid &liquid);
};

#endif

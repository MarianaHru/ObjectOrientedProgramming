// Derived class: Alcohol.h
#ifndef ALCOHOL_H
#define ALCOHOL_H

#include "Liquid.h"

class Alcohol : public Liquid
{
private:
    double strength;

public:
    // Конструктори
    Alcohol();
    Alcohol(const std::string &name, double density, double strength);
    Alcohol(const Liquid &liquid, double strength);
    Alcohol(const Alcohol &other);

    // Методи отримання та встановлення значень
    double getStrength() const;
    void setStrength(double strength);

    // Ініціалізація
    void Init(const std::string &name, double density, double strength);
    void Read();
    void Display() const;

    // Перетворення до рядка
    operator std::string() const;

    friend std::ostream &operator<<(std::ostream &out, const Alcohol &alcohol);
    friend std::istream &operator>>(std::istream &in, Alcohol &alcohol);

    // Оператори інкременту та декременту
    Alcohol &operator++();   // Префіксний інкремент
    Alcohol operator++(int); // Постфіксний інкремент
    Alcohol &operator--();   // Префіксний декремент
    Alcohol operator--(int); // Постфіксний декремент
};

#endif

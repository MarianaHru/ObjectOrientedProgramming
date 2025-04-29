// #ifndef FRACTION_H
// #define FRACTION_H

// #include <iostream>
// #include <string>
// #include <stdexcept>

// class OwnException // власний виняток
// {
// private:
//     std::string message;

// public:
//     OwnException(const std::string &msg) : message(msg) {}
//     std::string what() const { return message; }
// };

// class FractionException : public std::logic_error // виняток-нащадок стандартного
// {
// public:
//     FractionException(const std::string &msg) : std::logic_error(msg) {}
// };

// class Fraction
// {
// private:
//     int first;
//     int second;

// public:
//     // Конструктори
//     Fraction() noexcept;
//     Fraction(int f, int s) throw(std::invalid_argument, FractionException, OwnException);
//     Fraction(const Fraction &other) noexcept;

//     // Методи доступу
//     int getFirst() const noexcept;
//     int getSecond() const noexcept;
//     void setFirst(int f) noexcept;
//     void setSecond(int s) throw(std::invalid_argument);

//     void Init(int f, int s) throw(std::invalid_argument, FractionException, OwnException);

//     int ipart() const throw(std::bad_exception);

//     // Оператор приведення до рядка
//     explicit operator std::string() const noexcept;

//     Fraction &operator=(const Fraction &other) noexcept;

//     // Оператори інкременту та декременту
//     Fraction &operator++() noexcept;
//     Fraction operator++(int) noexcept;
//     Fraction &operator--() noexcept;
//     Fraction operator--(int) noexcept;

//     // Дружні оператори введення/виведення
//     friend std::ostream &operator<<(std::ostream &out, const Fraction &f);
//     friend std::istream &operator>>(std::istream &in, Fraction &f);
// };

// Fraction makeFraction(int f, int s) throw(std::invalid_argument, FractionException, OwnException);

// #endif

#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <string>
#include <stdexcept>

class OwnException // власний виняток
{
private:
    std::string message;

public:
    OwnException(const std::string &msg) : message(msg) {}
    std::string what() const { return message; }
};

class FractionException : public std::logic_error // виняток-нащадок стандартного
{
public:
    FractionException(const std::string &msg) : std::logic_error(msg) {}
};

class Fraction
{
private:
    int first;
    int second;

public:
    // Конструктори
    Fraction() noexcept;
    Fraction(int f, int s) noexcept(false); // Змінено
    Fraction(const Fraction &other) noexcept;

    // Методи доступу
    int getFirst() const noexcept;
    int getSecond() const noexcept;
    void setFirst(int f) noexcept;
    void setSecond(int s) noexcept(false); // Змінено

    void Init(int f, int s) noexcept(false); // Змінено

    int ipart() const noexcept(false); // Змінено

    // Оператор приведення до рядка
    explicit operator std::string() const noexcept;

    Fraction &operator=(const Fraction &other) noexcept;

    Fraction &operator++() noexcept;
    Fraction operator++(int) noexcept;
    Fraction &operator--() noexcept;
    Fraction operator--(int) noexcept;

    friend std::ostream &operator<<(std::ostream &out, const Fraction &f);
    friend std::istream &operator>>(std::istream &in, Fraction &f);
};

Fraction makeFraction(int f, int s) noexcept(false); // Змінено

#endif
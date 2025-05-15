// Array.cpp
#include "Array.h"
#include <stdexcept>
#include <iostream>

// Конструктор для ініціалізації масиву заданого розміру та значення
Array::Array(int n, unsigned char val)
{
    // Перевірка на коректність розміру масиву
    if (n < 0 || n > MAX_SIZE)
    {
        throw std::out_of_range("Invalid array size"); // Викидає виключення, якщо розмір некоректний
    }
    size = n; // Задаємо розмір масиву
    // Ініціалізація елементів масиву заданим значенням
    for (int i = 0; i < size; ++i)
    {
        data[i] = val;
    }
}

// Геттер для отримання розміру масиву
int Array::getSize() const
{
    return size; // Повертає розмір масиву
}

// Функція для перевірки коректності індексу
bool Array::rangeCheck(int index) const
{
    return index >= 0 && index < size; // Повертає true, якщо індекс в межах масиву
}

// Перевантаження оператора індексації для доступу до елементів масиву
unsigned char &Array::operator[](int index)
{
    // Якщо індекс некоректний, викидає виключення
    if (!rangeCheck(index))
    {
        throw std::out_of_range("Index out of range");
    }
    return data[index]; // Повертає посилання на елемент масиву
}

// Перевантаження оператора індексації для доступу до елементів масиву (const версія)
const unsigned char &Array::operator[](int index) const
{
    // Якщо індекс некоректний, викидає виключення
    if (!rangeCheck(index))
    {
        throw std::out_of_range("Index out of range");
    }
    return data[index]; // Повертає константне посилання на елемент масиву
}

// Функція для додавання двох масивів
Array *Array::add(const Array &other) const
{
    // Перевірка на рівність розміру масивів
    if (getSize() != other.getSize())
    {
        throw std::invalid_argument("Arrays must be the same size to add"); // Викидає виключення, якщо масиви різного розміру
    }

    // Створення нового масиву для результату
    Array *result = new Array(getSize());
    // Додавання елементів масивів поелементно
    for (int i = 0; i < getSize(); ++i)
    {
        (*result)[i] = this->operator[](i) + other[i]; // Операція додавання без модуля 256
    }

    return result;
}

// Віртуальна функція для віднімання масивів
Array *Array::subtract(const Array &other) const
{
    throw std::logic_error("subtract() must be overridden in derived class");
}

// Віртуальна функція для множення масивів
Array *Array::multiply(const Array &other) const
{
    throw std::logic_error("multiply() must be overridden in derived class");
}

// Віртуальна функція для ділення масивів
Array *Array::divide(const Array &other) const
{
    throw std::logic_error("divide() must be overridden in derived class");
}

// Віртуальна функція для виведення масиву
void Array::print() const
{
    throw std::logic_error("print() must be overridden in derived class");
}

// Віртуальна функція для порівняння масивів
int Array::compare(const Array &other) const
{
    throw std::logic_error("compare() must be overridden in derived class");
}

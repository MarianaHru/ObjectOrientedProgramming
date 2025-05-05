#include "Array.h"
#include <iostream>
#include <stdexcept>
using namespace std;

// Конструктор для створення масиву заданого розміру
Array::Array(const Array::size_type &n)
{
    if (n == 0)
        throw invalid_argument("Size must be greater than zero");
    First = 0;
    Count = Size = n;
    elems = new value_type[Size]; // Виділення пам'яті для масиву
    for (size_type i = 0; i < Size; i++)
        elems[i] = 0; // Ініціалізація всіх елементів нулями
}

// Конструктор для створення масиву з діапазону значень
Array::Array(const iterator first, const iterator last)
{
    if (first > last)
        throw invalid_argument("Invalid range"); // Виключення, якщо діапазон неправильний
    First = 0;
    Count = Size = static_cast<size_type>(last - first) + 1;
    elems = new value_type[Size]; // Виділення пам'яті для масиву
    for (size_type i = 0; i < Size; ++i)
        elems[i] = 0; // Ініціалізація всіх елементів нулями
}

// Конструктор для створення масиву з індексами
Array::Array(const size_type first, const size_type last)
{
    if (first > last)
        throw invalid_argument("Invalid index range"); // Виключення, якщо діапазон неправильний
    First = first;
    Count = Size = (last - first) + 1;
    elems = new value_type[Size]; // Виділення пам'яті для масиву
    for (size_type i = 0; i < Size; ++i)
        elems[i] = 0; // Ініціалізація всіх елементів нулями
}

// Конструктор копіювання для створення нового масиву на основі іншого
Array::Array(const Array &t)
    : Size(t.Size), Count(t.Count), First(t.First), elems(new value_type[t.Size])
{
    for (size_type i = 0; i < Size; ++i)
        elems[i] = t.elems[i]; // Копіювання елементів з іншого масиву
}

// Оператор присвоєння для копіювання одного масиву в інший
Array &Array::operator=(const Array &t)
{
    if (this != &t)
    {
        Array tmp(t); // Створення тимчасового об'єкта масиву
        swap(tmp);    // Обмін даними між поточним і тимчасовим масивом
    }
    return *this; // Повернення цього об'єкта
}

// Деструктор для звільнення пам'яті
Array::~Array()
{
    delete[] elems;  // Звільнення пам'яті, виділеної під масив
    elems = nullptr; // Встановлення вказівника в нуль
}

// Додавання елемента в кінець масиву
void Array::push_back(const value_type &v)
{
    if (Count == Size)    // Якщо немає місця в масиві
        resize(Size * 2); // Подвоїти розмір масиву
    elems[Count++] = v;   // Додавання елемента
}

// Оператор доступу до елемента за індексом (не змінний)
Array::reference Array::operator[](size_type index)
{
    if ((First <= index) && (index < First + Count)) // Перевірка на валідний індекс
        return elems[index - First];                 // Повернення елемента
    else
        throw out_of_range("Index out of range!"); // Виняток при недійсному індексі
}

// Оператор доступу до елемента за індексом (константний)
Array::const_reference Array::operator[](size_type index) const
{
    if ((First <= index) && (index < First + Count)) // Перевірка на валідний індекс
        return elems[index - First];                 // Повернення елемента
    else
        throw out_of_range("Index out of range!"); // Виняток при недійсному індексі
}

// Зміна розміру масиву
void Array::resize(size_type newsize)
{
    if (newsize <= Size)
        return;

    value_type *data = new value_type[newsize]; // Виділення нової пам'яті
    for (size_type i = 0; i < Count; ++i)
        data[i] = elems[i]; // Копіювання існуючих елементів
    for (size_type i = Count; i < newsize; ++i)
        data[i] = 0; // Ініціалізація решти нулями
    delete[] elems;  // Звільнення старої пам'яті
    elems = data;    // Перенаправлення вказівника на нову пам'ять
    Size = newsize;  // Оновлення розміру
}

// Обмін даними між двома масивами
void Array::swap(Array &other)
{
    std::swap(elems, other.elems); // Стандартна функція обміну
    std::swap(Size, other.Size);   // Обмін розмірами
    std::swap(Count, other.Count); // Обмін кількостями
    std::swap(First, other.First); // Обмін початковими індексами
}

// Повернення потужності масиву
Array::size_type Array::capacity() const
{
    return Size; // Повернення розміру масиву
}

// Повернення кількості елементів в масиві
Array::size_type Array::size() const
{
    return Count; // Повернення кількості елементів
}

// Перевірка, чи масив порожній
bool Array::empty() const
{
    return Count == 0; // Якщо кількість елементів 0, то масив порожній
}

// Оператор виведення масиву на екран
ostream &operator<<(ostream &out, const Array &tmp)
{
    for (Array::size_type j = 0; j < tmp.Count; j++)
        out << tmp[j] << " "; // Виведення кожного елемента масиву
    out << endl;              // Кінець рядка після виведення
    return out;               // Повернення потоку
}

// Оператор введення значень у масив
istream &operator>>(istream &in, Array &tmp)
{
    for (Array::size_type j = 0; j < tmp.Count; j++)
    {
        in >> tmp[j]; // Введення кожного елемента
    }
    return in; // Повернення потоку
}

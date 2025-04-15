// Object.cpp
#include "Object.h"

// Ініціалізація статичної змінної count
int Object::count = 0;

// Конструктор
Object::Object() noexcept
{
    ++count; // Збільшуємо лічильник при створенні об'єкта
}

// Копіювальний конструктор
Object::Object(const Object &) noexcept
{
    ++count; // Збільшуємо лічильник при копіюванні об'єкта
}

// Метод для отримання значення лічильника
int Object::getCount()
{
    return count; // Повертаємо поточне значення лічильника
}
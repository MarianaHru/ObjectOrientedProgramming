#include "Array.h"
#include <iostream>
#include <ctime>
#include <cmath>
#include <algorithm>

using namespace std;

Array createDynamicArray(int *arr, int size)
{
    Array dynamicArray(size);

    if (size <= 0)
        return dynamicArray;

    // Обчислюємо суму і середнє за абсолютною величиною
    double sum = 0;
    double absSum = 0;
    for (int i = 0; i < size; ++i)
    {
        sum += arr[i];
        absSum += abs(arr[i]);
    }

    double meanAbs = absSum / size;

    // Знаходимо максимум
    int maxVal = arr[0];
    for (int i = 1; i < size; ++i)
    {
        if (arr[i] > maxVal)
            maxVal = arr[i];
    }

    // Віднімаємо maxVal і заповнюємо dynamicArray
    for (int i = 0; i < size; ++i)
    {
        dynamicArray[i] = arr[i] - maxVal;
    }

    // Додаємо до кінця масиву початкову суму та середнє за абсолютною величиною
    dynamicArray.push_back(sum);
    dynamicArray.push_back(meanAbs);

    return dynamicArray;
}

#ifndef UNIT_TESTING
int main()
{
    int n;
    cout << "n = ";
    cin >> n;

    // Генеруємо звичайний масив
    int *arr = new int[n];
    srand(static_cast<unsigned>(time(0)));
    for (int i = 0; i < n; ++i)
    {
        arr[i] = -50 + rand() % 101;
    }

    // Виводимо його
    cout << "Initial array: ";
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Створюємо динамічний масив
    Array dynamicArray = createDynamicArray(arr, n);

    // Виводимо результат
    cout << "Dynamic array: " << dynamicArray;

    delete[] arr;
    return 0;
}
#endif

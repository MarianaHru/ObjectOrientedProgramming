#include "Array.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
using namespace std;

// Алгоритм copy
template <typename InputIterator, typename OutputIterator>
OutputIterator my_copy(InputIterator first, InputIterator last, OutputIterator result)
{
    while (first != last)
    {
        *result++ = *first++;
    }
    return result;
}

// Алгоритм copy_if
template <typename InputIterator, typename OutputIterator, typename Predicate>
OutputIterator my_copy_if(InputIterator first, InputIterator last, OutputIterator result, Predicate pred)
{
    while (first != last)
    {
        if (pred(*first))
            *result++ = *first;
        ++first;
    }
    return result;
}

// Функтор: умова для copy_if
struct IsPositive
{
    bool operator()(double x) const
    {
        return x > 0;
    }
};

Array createDynamicArray(int *arr, int size)
{
    Array dynamicArray(size);

    if (size <= 0)
        return dynamicArray;

    double sum = 0, absSum = 0;
    for (int i = 0; i < size; ++i)
    {
        sum += arr[i];
        absSum += abs(arr[i]);
    }

    double meanAbs = absSum / size;

    for (int i = 0; i < size; ++i)
    {
        dynamicArray[i] = arr[i] + meanAbs;
    }

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

    srand(static_cast<unsigned>(time(0)));
    int *arr = new int[n];
    for (int i = 0; i < n; ++i)
        arr[i] = -50 + rand() % 101;

    cout << "Initial array: ";
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;

    Array dynamicArray = createDynamicArray(arr, n);
    cout << "Dynamic array: " << dynamicArray;

    // Копіюємо всі елементи (copy)
    Array copied(dynamicArray.size());
    my_copy(dynamicArray.begin(), dynamicArray.end(), copied.begin());
    cout << "Copied array (copy): " << copied;

    // Копіюємо тільки позитивні елементи (copy_if)
    Array filtered(dynamicArray.size());
    auto new_end = my_copy_if(dynamicArray.begin(), dynamicArray.end(), filtered.begin(), IsPositive());
    size_t filteredSize = new_end - filtered.begin();
    filtered.resize(filteredSize); // прибираємо зайві нулі
    cout << "Filtered array (copy_if, only > 0): " << filtered;

    delete[] arr;
    return 0;
}
#endif
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

// Функція для створення масиву випадкових цілих чисел
void create_array(vector<int> &a, int n, int minVal = 0, int maxVal = 100)
{
    a.resize(n);
    for (int i = 0; i < n; ++i)
    {
        a[i] = minVal + rand() % (maxVal - minVal + 1);
    }
}

// Функція для виведення масиву у вигляді рядка
void print_array(const vector<int> &a)
{
    for (int value : a)
    {
        cout << value << " ";
    }
    cout << endl;
}

// Функція для підрахунку кількості непарних елементів
int count_odd_elements(const vector<int> &a)
{
    int count = 0;
    for (int value : a)
    {
        if (value % 2 != 0)
        {
            ++count;
        }
    }
    return count;
}
#ifndef UNIT_TESTING
int main()
{
    srand(static_cast<unsigned>(time(0))); // Ініціалізація генератора випадкових чисел

    vector<int> a;
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    create_array(a, n);

    cout << "Original array: ";
    print_array(a);

    int oddCount = count_odd_elements(a);
    cout << "Number of odd elements: " << oddCount << endl;

    return 0;
}
#endif
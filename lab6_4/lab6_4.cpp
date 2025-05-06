#include <iostream>
#include <stdexcept>
using namespace std;

template <class T>
class MyVector
{
    T *v;
    int size;

public:
    // Конструктор ініціалізації
    MyVector(int newsize)
    {
        size = newsize;
        v = new T[size];
        for (int i = 0; i < size; ++i)
            v[i] = T(); // ініціалізація нульовим значенням типу T
    }

    // Конструктор копіювання
    MyVector(const MyVector &other)
    {
        size = other.size;
        v = new T[size];
        for (int i = 0; i < size; ++i)
            v[i] = other.v[i];
    }

    // Деструктор
    ~MyVector()
    {
        delete[] v;
    }

    // Оператор додавання векторів
    friend MyVector<T> operator+(const MyVector<T> &a, const MyVector<T> &b)
    {
        if (a.size != b.size)
            throw runtime_error("Vectors must be of the same size");
        MyVector<T> result(a.size);
        for (int i = 0; i < a.size; ++i)
            result.v[i] = a.v[i] + b.v[i];
        return result;
    }

    // Оператор множення на число
    MyVector<T> operator*(T scalar) const
    {
        MyVector<T> result(size);
        for (int i = 0; i < size; ++i)
            result.v[i] = v[i] * scalar;
        return result;
    }

    // Оператор вводу
    friend istream &operator>>(istream &in, MyVector<T> &vec)
    {
        for (int i = 0; i < vec.size; ++i)
        {
            cout << "element[" << i << "] = ";
            in >> vec.v[i];
        }
        return in;
    }

    // Оператор виводу
    friend ostream &operator<<(ostream &out, const MyVector<T> &vec)
    {
        for (int i = 0; i < vec.size; ++i)
            out << vec.v[i] << " ";
        out << endl;
        return out;
    }
};
#ifndef UNIT_TESTING
// Інстанціювання та демонстрація в main()
int main()
{
    try
    {
        MyVector<int> a(3), b(3);
        cout << "Enter vector A:\n";
        cin >> a;
        cout << "Enter vector B:\n";
        cin >> b;

        MyVector<int> sum = a + b;
        cout << "Sum: " << sum;

        MyVector<int> mult = a * 2;
        cout << "A * 2: " << mult;
    }
    catch (const exception &e)
    {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
#endif
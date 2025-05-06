#pragma once
#include <iostream>
#include <stdexcept>

template <class T>
class MyVector
{
    T *v;
    int size;

public:
    MyVector(int newsize)
    {
        size = newsize;
        v = new T[size];
        for (int i = 0; i < size; ++i)
            v[i] = T();
    }

    MyVector(const MyVector &other)
    {
        size = other.size;
        v = new T[size];
        for (int i = 0; i < size; ++i)
            v[i] = other.v[i];
    }

    ~MyVector()
    {
        delete[] v;
    }

    friend MyVector<T> operator+(const MyVector<T> &a, const MyVector<T> &b)
    {
        if (a.size != b.size)
            throw std::runtime_error("Vectors must be of the same size");
        MyVector<T> result(a.size);
        for (int i = 0; i < a.size; ++i)
            result.v[i] = a.v[i] + b.v[i];
        return result;
    }

    MyVector<T> operator*(T scalar) const
    {
        MyVector<T> result(size);
        for (int i = 0; i < size; ++i)
            result.v[i] = v[i] * scalar;
        return result;
    }

    T &operator[](int index)
    {
        if (index < 0 || index >= size)
            throw std::out_of_range("Index out of range");
        return v[index];
    }

    int getSize() const { return size; }

    friend std::istream &operator>>(std::istream &in, MyVector<T> &vec)
    {
        for (int i = 0; i < vec.size; ++i)
            in >> vec.v[i];
        return in;
    }

    friend std::ostream &operator<<(std::ostream &out, const MyVector<T> &vec)
    {
        for (int i = 0; i < vec.size; ++i)
            out << vec.v[i] << " ";
        out << std::endl;
        return out;
    }
};

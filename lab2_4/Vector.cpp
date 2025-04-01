
#include <iostream>
#include <iomanip>
#include "Vector.h"
#include "sstream"

using namespace std;

Vector::Vector()
{
    date = nullptr;
    size = 0;
}

Vector::Vector(int n)
{
    if (n < 0)
    {
        std::cout << "Error, cant be negative" << std::endl;
        date = nullptr;
        size = 0;
    }
    else
    {
        date = new int[n]();
    }
}
Vector::Vector(int n, int *value)
{
    if (n < 0)
    {
        cout << "Size cannot be negative";
    }
    size = n;
    date = new int[size];
    for (int i = 0; i < size; i++)
    {
        date[i] = value[i];
    }
}

Vector::Vector(const Vector &v)
{
    size = v.size;
    date = new int[size];
    for (int i = 0; i < size; i++)
    {
        date[i] = v.date[i];
    }
}

Vector::~Vector()
{
    delete[] date;
}

bool Vector::SetSize(int s)
{
    if (s < 0)
    {
        cout << "Erorr, size cant be less than 0!";
        return false;
    }
    else
    {
        size = s;
        return true;
    }
}

Vector::operator string() const
{
    stringstream ss;
    ss << "Vector: [";
    for (int i = 0; i < size; i++)
    {
        ss << date[i];
        if (i < size - 1)
            ss << ",";
    }
    ss << "]";
    return ss.str();
}

ostream &operator<<(ostream &sout, const Vector &v)
{
    sout << string(v);
    return sout;
}

istream &operator>>(istream &in, Vector &v)
{
    for (int i = 0; i < v.size; i++)
    {
        in >> v.date[i];
    }
    return in;
}

bool operator==(const Vector &v1, const Vector &v2)
{
    if (v1.size != v2.size)
    {
        return false;
    }
    for (size_t i = 0; i < v1.size; ++i)
    {
        if (v1.date[i] != v2.date[i])
        {
            return false;
        }
    }
    return true;
}

Vector operator*(const Vector &v, int scalar)
{
    Vector result(v.size);
    for (int i = 0; i < v.size; i++)
    {
        result.date[i] = v.date[i] * scalar;
    }
    return result;
}

double norm(const Vector &v)
{
    double sum = 0;
    for (int i = 0; i < v.size; i++)
    {
        sum += v.date[i] * v.date[i];
    }
    return sqrt(sum);
}
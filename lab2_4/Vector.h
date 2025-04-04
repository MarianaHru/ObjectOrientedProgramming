#pragma once
#include <iostream>
#include <iomanip>

using namespace std;

class Vector
{
private:
    int *date;
    int size;

public:
    Vector();
    Vector(int n);
    Vector(int n, int *value);
    Vector(const Vector &);
    ~Vector();

    int *GetDate() const { return date; }
    int GetSize() const { return size; }

    void SetDate(int *d) { date = d; }
    bool SetSize(int s);

    int operator[](int index) const;

    Vector &operator=(const Vector &other);
    friend bool operator!=(const Vector &v1, const Vector &v2);

    operator string() const;
    friend ostream &operator<<(ostream &, const Vector &);
    friend istream &operator>>(istream &, Vector &);

    friend Vector operator*(const Vector &vec, int scalar);
    friend bool operator==(const Vector &lhs, const Vector &rhs);
    friend bool operator!=(const Vector &lhs, const Vector &rhs);
    friend double norm(const Vector &vec);
};
#include "Vector.h"
#include <iostream>
#include <iomanip>

using namespace std;
#ifndef UNIT_TESTING

int main()
{
    int size;
    cout << "Enter the size of vector: ";
    cin >> size;

    Vector v1(size);
    Vector v2(size);

    cout << "Enter elements for vector 1: ";
    cin >> v1;

    cout << "Enter elements for vector 2: ";
    cin >> v2;

    cout << "Vector v1: " << v1 << endl;
    cout << "Vector v2: " << v2 << endl;

    int scalar;
    cout << "Enter scalar: ";
    cin >> scalar;

    Vector mult1 = v1 * scalar;
    cout << "The 1 vector is multiplied by a scalar" << mult1;
    cout << endl;

    Vector mult2 = v2 * scalar;
    cout << "The 2 vector is multiplied by a scalar" << mult2;
    cout << endl;

    if (v1 == v2)
    {
        cout << "Vectors are equal" << endl;
    }
    else
    {
        cout << "Vectors aren't equal" << endl;
    }

    cout << "Norm of vector 1: " << norm(v1) << endl;
    cout << "Norm of vector 2: " << norm(v2) << endl;

    return 0;
}
#endif
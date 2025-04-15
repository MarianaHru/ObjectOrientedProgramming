#include <iostream>
#include "Money.h"
#include "MoneyPublic.h"
#include "MoneyPrivate.h"

using namespace std;
#ifndef UNIT_TESTING
int main()
{

    cout << "=== Base Class: Money ===" << endl;
    Money m1;
    m1.Read();
    m1.Display();
    cout << "String conversion: " << string(m1) << endl;
    cout << endl;

    cout << "=== Derived Class: MoneyPublic ===" << endl;
    MoneyPublic p1(10, 50), p2(5, 75);
    cout << "p1: " << (string)p1 << endl;
    cout << "p2: " << (string)p2 << endl;

    MoneyPublic sum = p1 + p2;
    cout << "Sum: " << (string)sum << endl;

    MoneyPublic diff = p1 - p2;
    cout << "Diff: " << (string)diff << endl;

    ++p1;
    cout << "++p1: " << (string)p1 << endl;

    p2++;
    cout << "p2++: " << (string)p2 << endl;

    cout << endl;

    cout << "=== Derived Class: MoneyPrivate ===" << endl;
    MoneyPrivate pr1, pr2;
    cout << "Enter pr1 (hryvnia kopiyky): ";
    cin >> pr1;
    cout << "Enter pr2 (hryvnia kopiyky): ";
    cin >> pr2;

    MoneyPrivate prSum = pr1 + pr2;
    MoneyPrivate prDiff = pr1 - pr2;

    cout << "pr1: " << (string)pr1 << endl;
    cout << "pr2: " << (string)pr2 << endl;
    cout << "Sum: " << (string)prSum << endl;
    cout << "Diff: " << (string)prDiff << endl;

    ++pr1;
    cout << "++pr1: " << (string)pr1 << endl;

    pr2++;
    cout << "pr2++: " << (string)pr2 << endl;

    return 0;
}
#endif
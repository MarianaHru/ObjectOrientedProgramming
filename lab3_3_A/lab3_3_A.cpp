#include <iostream>
#include "MoneyPublic.h"
#include "MoneyPrivate.h"

int main()
{
    MoneyPublic a(10, 50), b;
    cout << "Enter money (format: hryvna,kopek): ";
    cin >> b;

    cout << "a: " << a << endl;
    cout << "b: " << b << endl;

    MoneyPublic c = a + b;
    cout << "a + b = " << c << endl;

    MoneyPrivate x(5, 25), y(3, 10);
    MoneyPrivate z = x + y;
    cout << "x + y = " << z.toBase() << endl;

    return 0;
}

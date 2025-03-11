
#include "Money.h"

int main()
{
    Money m1, m2;
    m1.Read();
    m2.Read();

    Money sum = m1.Add(m2);
    cout << "Sum: ";
    sum.Display();

    Money div = m1.Divide(m2);
    cout << "Division result: ";
    div.Display();

    double number;
    cout << "Enter number to divide by: ";
    cin >> number;
    Money divByNum = m1.DivideByNumber(number);
    cout << "Division by number result: ";
    divByNum.Display();

    return 0;
}
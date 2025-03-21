

#include <iostream>
#include "Square.h"
#include "Rectangle.h"
#include "Circle.h"

using namespace std;

#ifndef UNIT_TESTING

int main()
{
    int mainChoice;

    int choice;
    Square square;
    Rectangle rectangle;
    Circle circle;
    double dx, dy, newRadius, newLength, newHeight, angle;

    do
    {
        cout << "Menu" << endl;
        cout << "1. Create Square" << endl;
        cout << "2. Create Rectangle" << endl;
        cout << "3. Create Circle" << endl;
        cout << "4. Exit" << endl;
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            square.Read();
            square.Display();
            cout << "Enter moving x: ";
            cin >> dx;
            cout << "Enter moving y: ";
            cin >> dy;
            cout << "Enter change length: ";
            cin >> newLength;
            square.Move(dx, dy);
            square.Resize(newLength);
            square.Display();
            break;
        case 2:
            rectangle.Read();
            rectangle.Display();
            cout << "Enter moving x: ";
            cin >> dx;
            cout << "Enter moving y: ";
            cin >> dy;
            cout << "Enter change length: ";
            cin >> newLength;
            cout << "Enter change height: ";
            cin >> newHeight;
            rectangle.Move(dx, dy);
            rectangle.Resize(newLength, newHeight);
            rectangle.Display();
            break;
        case 3:
            circle.Read();
            circle.Display();
            cout << "Enter moving x: ";
            cin >> dx;
            cout << "Enter moving y: ";
            cin >> dy;
            cout << "Enter change to radius: ";
            cin >> newRadius;
            circle.Move(dx, dy);
            circle.Resize(newRadius);
            circle.Display();
            break;
        }
    } while (choice != 4);

    return 0;
}

#endif

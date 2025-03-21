#include "Rectangle.h"
#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>

using namespace std;

bool Rectangle::SetHeight(double h)
{
    if (h <= 0)
    {
        cout << "Invalid dimensions!  Height must be greater than 0." << endl;
        return false;
    }
    height = h;
    return true;
}

bool Rectangle::SetLength(double l)
{
    if (l <= 0)
    {
        cout << "Invalid dimensions! Length must be greater than 0." << endl;
        return false;
    }
    length = l;
    return true;
}

bool Rectangle::SetRotation(double angle)
{
    if (angle <= 0)
    {
        cout << "Invalid rotation! Rotation must be greater than 0." << endl;
        return false;
    }
    AngleC = angle;
    return true;
}

bool Rectangle::Init(double l, double h, double xCoord, double yCoord, double angle)
{
    SetX(xCoord);
    SetY(yCoord);
    return SetLength(l), SetHeight(h), SetRotation(angle);
}

void Rectangle::Read()
{
    double xCoord, yCoord;
    double l, h;
    double angle = 0;
    cout << "Enter x-coordinate: ";
    cin >> xCoord;
    cout << "Enter y-coordinate: ";
    cin >> yCoord;
    cout << "Enter rotation: ";
    cin >> angle;
    do
    {
        cout << "Enter length: ";
        cin >> l;
        cout << "Enter height: ";
        cin >> h;
    } while (!Init(l, h, xCoord, yCoord, angle));
}

void Rectangle::Display() const
{
    cout << toString() << endl;
}

string Rectangle::toString() const
{
    ostringstream sout;
    sout << "Rectangle: length= " << length
         << ", height= " << height
         << ", position= (" << x << ", " << y << ")"
         << ", rotation= " << AngleC << " degrees";
    return sout.str();
}

void Rectangle::Move(double dx, double dy)
{
    SetX(GetX() + dx);
    SetY(GetY() + dy);
}

void Rectangle::Resize(double newLength, double newHeight)
{
    SetLength(GetLength() + newLength);
    SetHeight(GetHeight() + newHeight);
}
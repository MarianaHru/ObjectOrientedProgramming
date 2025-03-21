#include "Square.h"
#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>

using namespace std;

bool Square::SetLength(double l)
{
    if (l <= 0)
    {
        cout << "Invalid length! Length must be greater than 0." << endl;
        return false;
    }
    length = l;
    return true;
}

bool Square::SetRotation(double angle)
{
    if (angle <= 0)
    {
        cout << "Invalid rotation! Rotation must be greater than 0." << endl;
        return false;
    }
    AngleC = angle;
    return true;
}

bool Square::Init(double l, double xCoord, double yCoord, double angle)
{
    SetX(xCoord);
    SetY(yCoord);
    return SetLength(l), SetRotation(angle);
}

void Square::Read()
{
    double xCoord, yCoord;
    double l;
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
    } while (!Init(l, xCoord, yCoord, angle));
}

void Square::Display() const
{
    cout << toString() << endl;
}

string Square::toString() const
{
    ostringstream sout;
    sout << "Square: length=" << length
         << ", position=(" << x << ", " << y << ")"
         << ", rotation= " << AngleC << " degrees";
    return sout.str();
}

void Square::Move(double dx, double dy)
{
    SetX(GetX() + dx);
    SetY(GetY() + dy);
}

void Square::Resize(double newLength)
{
    SetLength(GetLength() + newLength);
}

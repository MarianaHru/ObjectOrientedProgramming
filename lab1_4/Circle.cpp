;
#include "Circle.h"
#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>

    using namespace std;

bool Circle::SetRadius(double r)
{
    if (r <= 0)
    {
        cout << "Invalid radius value! Radius must be greater than 0." << endl;
        return false;
    }
    radius = r;
    return true;
}

bool Circle::Init(double r, double xCoord, double yCoord)
{
    SetX(xCoord);
    SetY(yCoord);
    return SetRadius(r);
}

void Circle::Read()
{
    double xCoord, yCoord;
    double r;
    cout << "Enter x-coordinate: ";
    cin >> xCoord;
    cout << "Enter y-coordinate: ";
    cin >> yCoord;
    do
    {
        cout << "Enter radius: ";
        cin >> r;
    } while (!Init(r, xCoord, yCoord));
}

void Circle::Display() const
{
    cout << toString() << endl;
}

string Circle::toString() const
{
    ostringstream sout;
    sout << "Circle: radius=" << radius << ", position=(" << x << ", " << y << ")";
    return sout.str();
}

void Circle::Move(double dx, double dy)
{
    SetX(GetX() + dx);
    SetY(GetY() + dy);
}

void Circle::Resize(double newRadius)
{
    SetRadius(GetRadius() + newRadius);
}
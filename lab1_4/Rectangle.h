#pragma once
#include <string>
#include <sstream>

using namespace std;

class Rectangle
{
private:
    double x, y;
    double length, height;
    double AngleC = 0;

public:
    double GetX() const { return x; }
    double GetY() const { return y; }
    double GetLength() const { return length; }
    double GetHeight() const { return height; }
    double getRotation() const { return AngleC; }

    void SetX(double xCoord) { x = xCoord; }
    void SetY(double yCoord) { y = yCoord; }
    bool SetLength(double l);
    bool SetHeight(double h);
    bool SetRotation(double angle);

    bool Init(double l, double h, double xCoord, double yCoord, double angle);
    void Read();
    void Display() const;
    string toString() const;

    void Move(double dx, double dy);
    void Resize(double newLength, double newHeight);
};

#pragma once
#include <string>
#include <sstream>

using namespace std;

class Circle
{
private:
    double x, y;
    double radius;

public:
    double GetX() const { return x; }
    double GetY() const { return y; }
    double GetRadius() const { return radius; }

    void SetX(double xCoord) { x = xCoord; }
    void SetY(double yCoord) { y = yCoord; }
    bool SetRadius(double r);

    bool Init(double r, double xCoord, double yCoord);
    void Read();
    void Display() const;
    string toString() const;

    void Move(double dx, double dy);
    void Resize(double newRadius);
};
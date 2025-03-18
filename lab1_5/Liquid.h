
#pragma once
#include <string>
#include <iostream>
using namespace std;

class Liquid
{
private:
    string name;
    double density;

public:
    string getName() const { return name; }
    double getDensity() const { return density; }
    void setName(string name) { this->name = name; }
    void setDensity(double density) { this->density = density; }
    void Init(string name, double density);
    void Display() const;
    void Read();
};
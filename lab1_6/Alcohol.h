#pragma once
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Alcohol
{
public:
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
        string toString() const;
    };

private:
    Liquid liquid;
    double strength;

public:
    Liquid getLiquid() const { return liquid; }
    double getStrength() const { return strength; }
    void setLiquid(Liquid liquid) { this->liquid = liquid; }
    void setStrength(double strength) { this->strength = strength; }

    void Init(Liquid liquid, double strength);
    void Display() const;
    void Read();
    string toString() const;
};
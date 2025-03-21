
// Alcohol.h
#pragma once
#include "Liquid.h"

class Alcohol
{
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
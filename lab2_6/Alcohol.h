// Заголовочний файл Alcohol.h
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
        static int counter;

    public:
        Liquid();
        Liquid(string name, double density);
        Liquid(const Liquid &l);
        ~Liquid();

        Liquid &operator=(const Liquid &l);

        void Init(string name, double density, double strength);
        void Display() const;
        void Read();

        operator string() const;

        static int getCounter();

        friend ostream &operator<<(ostream &out, const Liquid &l);
        friend istream &operator>>(istream &in, Liquid &l);
    };

private:
    Liquid liquid;
    double strength;
    static int counter;

public:
    Alcohol();
    Alcohol(string name, double density, double strength);
    Alcohol(const Alcohol &a);
    ~Alcohol();

    Alcohol &operator=(const Alcohol &a);

    void Init(string name, double density, double strength);
    void Display() const;
    void Read();

    operator string() const;

    Alcohol &operator++();
    Alcohol &operator--();
    Alcohol operator++(int);
    Alcohol operator--(int);
    static int getCounter();

    friend ostream &operator<<(ostream &out, const Alcohol &a);
    friend istream &operator>>(istream &in, Alcohol &a);
};
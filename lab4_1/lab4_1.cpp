#include <iostream>
#include <cmath>
#include <typeinfo>
#include <stdexcept>

using namespace std;

class Curve
{
protected:
    double a, b;

public:
    Curve(double a, double b) : a(a), b(b) {}
    virtual double calculateY(double x) const = 0;
    virtual ~Curve() {}
};

class Line : public Curve
{
public:
    Line(double a, double b) : Curve(a, b) {}
    double calculateY(double x) const override
    {
        return a * x + b;
    }
};

class Ellipse : public Curve
{
public:
    Ellipse(double a, double b) : Curve(a, b) {}
    double calculateY(double x) const override
    {
        if (abs(x) > abs(a))
            throw domain_error("x > a, неможливо обчислити y");
        return b * sqrt(1 - (x * x) / (a * a));
    }
};

class Hyperbola : public Curve
{
public:
    Hyperbola(double a, double b) : Curve(a, b) {}
    double calculateY(double x) const override
    {
        if ((x * x) / (a * a) < 1)
            throw domain_error("x^2/a^2 < 1, y буде уявним");
        return b * sqrt((x * x) / (a * a) - 1);
    }
};
#ifndef UNIT_TESTING
int main()
{
    const int SIZE = 3;
    Curve *curves[SIZE];

    curves[0] = new Line(2.0, 1.0);
    curves[1] = new Ellipse(5.0, 3.0);
    curves[2] = new Hyperbola(2.0, 4.0);

    double x = 1.5;

    for (int i = 0; i < SIZE; ++i)
    {
        cout << "Об'єкт №" << (i + 1) << endl;
        cout << "Реальний тип: " << typeid(*curves[i]).name() << endl;
        try
        {
            double y = curves[i]->calculateY(x);
            cout << "При x = " << x << ", y = " << y << endl;
        }
        catch (const exception &e)
        {
            cout << "Помилка: " << e.what() << endl;
        }
        cout << "--------------------------\n";
    }

    for (int i = 0; i < SIZE; ++i)
    {
        delete curves[i];
    }

    return 0;
}
#endif

// #include <iostream>
// #include <cmath>
// #include <typeinfo>

// using namespace std;

// class Curve
// {
// protected:
//     double a, b;

// public:
//     Curve(double a, double b) : a(a), b(b) {}
//     virtual double calculateY(double x) const = 0; // абстрактна функція
//     virtual ~Curve() {}                            // віртуальний деструктор
// };

// class Line : public Curve
// {
// public:
//     Line(double a, double b) : Curve(a, b) {}
//     double calculateY(double x) const override
//     {
//         return a * x + b;
//     }
// };

// class Ellipse : public Curve
// {
// public:
//     Ellipse(double a, double b) : Curve(a, b) {}
//     double calculateY(double x) const override
//     {
//         if (abs(x) > abs(a))
//             throw std::domain_error("x > a, неможливо обчислити y");
//         return b * sqrt(1 - (x * x) / (a * a));
//     }
// };

// class Hyperbola : public Curve
// {
// public:
//     Hyperbola(double a, double b) : Curve(a, b) {}
//     double calculateY(double x) const override
//     {
//         if ((x * x) / (a * a) < 1)
//             throw std::domain_error("x^2/a^2 < 1, y буде уявним");
//         return b * sqrt((x * x) / (a * a) - 1);
//     }
// };
// #ifndef UNIT_TESTING
// int main()
// {
//     const int SIZE = 3;
//     Curve *curves[SIZE];

//     // створення об’єктів і присвоєння вказівників
//     curves[0] = new Line(2.0, 1.0);      // y = 2x + 1
//     curves[1] = new Ellipse(5.0, 3.0);   // x^2/a^2 + y^2/b^2 = 1
//     curves[2] = new Hyperbola(2.0, 4.0); // x^2/a^2 - y^2/b^2 = 1

//     double x = 1.5;

//     for (int i = 0; i < SIZE; ++i)
//     {
//         cout << "Об'єкт №" << (i + 1) << endl;
//         cout << "Реальний тип: " << typeid(*curves[i]).name() << endl;
//         try
//         {
//             double y = curves[i]->calculateY(x);
//             cout << "При x = " << x << ", y = " << y << endl;
//         }
//         catch (const exception &e)
//         {
//             cout << "Помилка: " << e.what() << endl;
//         }
//         cout << "--------------------------\n";
//     }

//     // очищення пам’яті
//     for (int i = 0; i < SIZE; ++i)
//     {
//         delete curves[i];
//     }

//     return 0;
// }
// #endif

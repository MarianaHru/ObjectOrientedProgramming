#ifndef PAIR_H
#define PAIR_H

#include <iostream>
#include <string>

class Pair
{
protected:
    int first;
    int second;

public:
    Pair(int x = 0, int y = 0);
    Pair(const Pair &other);

    void Init(int x, int y);

    int getFirst() const;
    int getSecond() const;
    void setFirst(int f);
    void setSecond(int s);

    void Read();

    void Display() const;

    std::string toString() const;

    bool operator==(const Pair &other) const;
    bool operator!=(const Pair &other) const;
    bool operator>(const Pair &other) const;
    bool operator<(const Pair &other) const;
    bool operator>=(const Pair &other) const;
    bool operator<=(const Pair &other) const;

    friend std::ostream &operator<<(std::ostream &out, const Pair &p);
    friend std::istream &operator>>(std::istream &in, Pair &p);
};

#endif
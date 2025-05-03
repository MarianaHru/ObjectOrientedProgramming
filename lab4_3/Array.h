#ifndef ARRAY_H
#define ARRAY_H

#include <stdexcept>

class Array
{
protected:
    static const int MAX_SIZE = 100;
    unsigned char data[MAX_SIZE];
    int size;

public:
    Array(int n = 0, unsigned char val = 0);
    virtual ~Array() = default;

    int getSize() const;
    bool rangeCheck(int index) const;

    unsigned char &operator[](int index);
    const unsigned char &operator[](int index) const;

    virtual Array *add(const Array &other) const;
    virtual Array *subtract(const Array &other) const;
    virtual Array *multiply(const Array &other) const;
    virtual Array *divide(const Array &other) const;
    virtual void print() const;
    virtual int compare(const Array &other) const;
};

#endif

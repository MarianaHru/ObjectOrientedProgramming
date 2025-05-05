#pragma once
#include <iostream>
#include <stdexcept>

class Array
{
public:
    typedef double value_type;
    typedef value_type *iterator;
    typedef const value_type *const_iterator;
    typedef value_type &reference;
    typedef const value_type &const_reference;
    typedef size_t size_type;

private:
    value_type *elems;
    size_type Size;
    size_type Count;
    size_type First;

public:
    Array(const size_type &n);
    Array(const iterator first, const iterator last);
    Array(const size_type first, const size_type last);
    Array(const Array &t);
    ~Array();

    Array &operator=(const Array &t);

    reference operator[](size_type index);
    const_reference operator[](size_type index) const;

    void push_back(const value_type &v);
    void resize(size_type newsize);
    void swap(Array &other);

    size_type size() const;
    size_type capacity() const;
    bool empty() const;

    friend std::ostream &operator<<(std::ostream &out, const Array &tmp);
    friend std::istream &operator>>(std::istream &in, Array &tmp);
};

#pragma once
#include <iostream>
using namespace std;

class Array
{
public:
    typedef unsigned int UINT;
    typedef double value_type;
    typedef double *iterator;
    typedef const double *const_iterator;
    typedef double &reference;
    typedef const double &const_reference;
    typedef std::size_t size_type;

private:
    static const size_type minsize = 10;
    size_type Size;
    size_type Count;
    size_type First;
    value_type *elems;

public:
    Array(const size_type &n = minsize) noexcept(false);
    Array(const Array &) noexcept(false);
    Array(const iterator first, const iterator last) noexcept(false);
    Array(const size_type first, const size_type last) noexcept(false);
    ~Array();
    Array &operator=(const Array &);

    iterator begin() { return elems; }
    const_iterator begin() const { return elems; }
    iterator end() { return elems + Count; }
    const_iterator end() const { return elems + Count; }

    size_type size() const;
    bool empty() const;
    size_type capacity() const;
    void resize(size_type newsize);

    reference operator[](size_type);
    const_reference operator[](size_type) const;
    reference front() { return elems[0]; }
    const_reference front() const { return elems[0]; }
    reference back() { return elems[size() - 1]; }
    const_reference back() const { return elems[size() - 1]; }

    void push_back(const value_type &v);
    void clear() { Count = 0; }
    void swap(Array &other);

    friend ostream &operator<<(ostream &out, const Array &a);
    friend istream &operator>>(istream &in, Array &a);

    template <typename Func>
    void for_each(iterator first, iterator last, Func func)
    {
        for (iterator it = first; it != last; ++it)
        {
            func(*it);
        }
    }

    template <typename Generator>
    void generate(iterator first, iterator last, Generator gen)
    {
        for (iterator it = first; it != last; ++it)
        {
            *it = gen();
        }
    }
};

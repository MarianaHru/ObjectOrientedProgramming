#include "Array.h"
#include <stdexcept>
#include <algorithm>

Array::Array(const size_type &n)
{
    if (n < minsize)
        throw std::invalid_argument("Size must be >= minsize");
    Size = n;
    Count = 0;
    First = 0;
    elems = new value_type[Size];
}

Array::Array(const iterator first, const iterator last)
{
    if (first > last)
        throw std::invalid_argument("Invalid range: first > last");
    Size = last - first;
    Count = Size;
    First = 0;
    elems = new value_type[Size];
    std::copy(first, last, elems);
}

Array::Array(const size_type first, const size_type last)
{
    if (first > last)
        throw std::invalid_argument("Invalid range: first > last");
    Size = last - first;
    Count = Size;
    First = first;
    elems = new value_type[Size];
    for (size_type i = 0; i < Size; ++i)
        elems[i] = static_cast<value_type>(First + i);
}

Array::Array(const Array &other)
{
    Size = other.Size;
    Count = other.Count;
    First = other.First;
    elems = new value_type[Size];
    std::copy(other.elems, other.elems + Count, elems);
}

Array::~Array()
{
    delete[] elems;
}

Array &Array::operator=(const Array &other)
{
    if (this != &other)
    {
        delete[] elems;
        Size = other.Size;
        Count = other.Count;
        First = other.First;
        elems = new value_type[Size];
        std::copy(other.elems, other.elems + Count, elems);
    }
    return *this;
}

Array::reference Array::operator[](size_type index)
{
    if (index >= Count)
        throw std::out_of_range("Index out of range");
    return elems[index];
}

Array::const_reference Array::operator[](size_type index) const
{
    if (index >= Count)
        throw std::out_of_range("Index out of range");
    return elems[index];
}

Array::size_type Array::size() const
{
    return Count;
}

bool Array::empty() const
{
    return Count == 0;
}

Array::size_type Array::capacity() const
{
    return Size;
}

void Array::resize(size_type newsize)
{
    if (newsize < Count)
        throw std::invalid_argument("New size must be >= current element count");
    value_type *newElems = new value_type[newsize];
    std::copy(elems, elems + Count, newElems);
    delete[] elems;
    elems = newElems;
    Size = newsize;
}

void Array::push_back(const value_type &v)
{
    if (Count >= Size)
        resize(Size * 2);
    elems[Count++] = v;
}

void Array::swap(Array &other)
{
    std::swap(Size, other.Size);
    std::swap(Count, other.Count);
    std::swap(First, other.First);
    std::swap(elems, other.elems);
}

std::ostream &operator<<(std::ostream &out, const Array &a)
{
    for (Array::size_type i = 0; i < a.Count; ++i)
    {
        out << a.elems[i] << " ";
    }
    return out;
}

std::istream &operator>>(std::istream &in, Array &a)
{
    for (Array::size_type i = 0; i < a.Size; ++i)
    {
        in >> a.elems[i];
    }
    a.Count = a.Size;
    return in;
}

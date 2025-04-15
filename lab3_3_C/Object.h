// Object.h
#pragma once
#include <string>

class Object
{
public:
    Object() noexcept;
    Object(const Object &) noexcept;
    virtual ~Object() noexcept = default;
    static int getCount();
    virtual std::string toString() const = 0;
    virtual void display() const = 0;

private:
    static int count;
};

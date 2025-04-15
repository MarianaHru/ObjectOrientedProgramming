#pragma once

class Object
{
private:
    static unsigned int count;

public:
    Object();
    virtual ~Object();

    static unsigned int getCount();
};

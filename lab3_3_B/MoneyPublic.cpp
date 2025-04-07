#include "MoneyPublic.h"
#include <stdexcept>

MoneyPublic::MoneyPublic() : Money() {}
MoneyPublic::MoneyPublic(long h, unsigned char k) : Money(h, k) {}
MoneyPublic::MoneyPublic(const Money &m) : Money(m) {}

MoneyPublic MoneyPublic::operator+(const MoneyPublic &other) const
{
    long total = (hryvnia * 100 + kopecks) + (other.hryvnia * 100 + other.kopecks);
    return MoneyPublic(total / 100, total % 100);
}

double MoneyPublic::operator/(const MoneyPublic &other) const
{
    if (other.hryvnia == 0 && other.kopecks == 0)
    {
        throw std::invalid_argument("Division by zero");
    }
    double a = hryvnia * 100.0 + kopecks;
    double b = other.hryvnia * 100.0 + other.kopecks;
    return a / b;
}

MoneyPublic MoneyPublic::operator/(double divisor) const
{
    if (divisor == 0)
        throw std::invalid_argument("Division by zero");
    long total = static_cast<long>((hryvnia * 100.0 + kopecks) / divisor);
    return MoneyPublic(total / 100, total % 100);
}

MoneyPublic &MoneyPublic::operator++()
{
    long total = hryvnia * 100 + kopecks + 1;
    hryvnia = total / 100;
    kopecks = total % 100;
    return *this;
}

MoneyPublic MoneyPublic::operator++(int)
{
    MoneyPublic temp = *this;
    ++(*this);
    return temp;
}

MoneyPublic &MoneyPublic::operator--()
{
    if (hryvnia == 0 && kopecks == 0)
    {
        throw std::underflow_error("Cannot decrement below zero");
    }
    long total = hryvnia * 100 + kopecks - 1;
    hryvnia = total / 100;
    kopecks = total % 100;
    return *this;
}

MoneyPublic MoneyPublic::operator--(int)
{
    MoneyPublic temp = *this;
    --(*this);
    return temp;
}

bool MoneyPublic::operator==(const MoneyPublic &other) const
{
    return hryvnia == other.hryvnia && kopecks == other.kopecks;
}

bool MoneyPublic::operator!=(const MoneyPublic &other) const
{
    return !(*this == other);
}

#include "MoneyPublic.h"

MoneyPublic::MoneyPublic() : Money() {}

MoneyPublic::MoneyPublic(long hryvna, unsigned char kopek)
    : Money(hryvna, kopek) {}

MoneyPublic::MoneyPublic(const Money &other)
    : Money(other) {}

MoneyPublic MoneyPublic::operator+(const MoneyPublic &other) const
{
    long totalKopeks = (hryvna * 100 + kopek) + (other.hryvna * 100 + other.kopek);
    return MoneyPublic(totalKopeks / 100, totalKopeks % 100);
}

MoneyPublic MoneyPublic::operator/(double divisor) const
{
    if (divisor == 0)
        throw invalid_argument("Division by zero!");

    double totalKopeks = (hryvna * 100.0 + kopek) / divisor;
    return MoneyPublic(static_cast<long>(totalKopeks) / 100, static_cast<unsigned char>(static_cast<long>(totalKopeks) % 100));
}

double MoneyPublic::operator/(const MoneyPublic &other) const
{
    if (other.hryvna == 0 && other.kopek == 0)
        throw invalid_argument("Division by zero!");

    double total1 = hryvna * 100.0 + kopek;
    double total2 = other.hryvna * 100.0 + other.kopek;
    return total1 / total2;
}

MoneyPublic &MoneyPublic::operator++()
{
    long totalKopeks = hryvna * 100 + kopek + 1;
    hryvna = totalKopeks / 100;
    kopek = totalKopeks % 100;
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
    if (hryvna == 0 && kopek == 0)
    {
        cout << "Cannot decrement below zero!" << endl;
        return *this;
    }

    long totalKopeks = hryvna * 100 + kopek - 1;
    hryvna = totalKopeks / 100;
    kopek = totalKopeks % 100;
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
    return (hryvna == other.hryvna) && (kopek == other.kopek);
}

bool MoneyPublic::operator!=(const MoneyPublic &other) const
{
    return !(*this == other);
}

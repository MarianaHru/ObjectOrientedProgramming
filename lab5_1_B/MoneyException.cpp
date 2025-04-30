#include "MoneyException.h"

// MoneyTooSmallException реалізація
MoneyTooSmallException::MoneyTooSmallException(const std::string &msg) noexcept
    : message(msg) {}

const char *MoneyTooSmallException::what() const noexcept
{
    return message.c_str();
}

// MoneySimpleException реалізація
MoneySimpleException::MoneySimpleException(const std::string &msg)
    : message(msg) {}

const std::string &MoneySimpleException::getMessage() const
{
    return message;
}

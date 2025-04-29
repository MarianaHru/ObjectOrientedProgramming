#include "MoneyException.h"

MoneyException::MoneyException(const std::string &msg) throw()
    : std::runtime_error(msg) {}

MoneyTooSmallException::MoneyTooSmallException(const std::string &msg) throw()
    : MoneyException(msg) {}

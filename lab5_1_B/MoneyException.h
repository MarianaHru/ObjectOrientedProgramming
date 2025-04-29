#pragma once
#include <stdexcept>
#include <string>

// Власний виняток, наслідується від стандартного std::runtime_error
class MoneyException : public std::runtime_error
{
public:
    MoneyException(const std::string &msg) throw();
};

// Виняток-нащадок для випадку занадто малого значення грошей
class MoneyTooSmallException : public MoneyException
{
public:
    MoneyTooSmallException(const std::string &msg) throw();
};

#pragma once
#include <string>
#include <exception>

/// Власний виняток, який наслідує std::exception
class MoneyTooSmallException : public std::exception
{
private:
    std::string message;

public:
    explicit MoneyTooSmallException(const std::string &msg) noexcept;
    const char *what() const noexcept override;
};

/// Власний виняток без наслідування від std::exception
class MoneySimpleException
{
private:
    std::string message;

public:
    explicit MoneySimpleException(const std::string &msg);
    const std::string &getMessage() const;
};

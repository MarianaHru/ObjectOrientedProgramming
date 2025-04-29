#include "lab5_1_A_unit_test.h"

// Перевірка значень за замовчуванням
TEST_F(FractionTest, DefaultConstructor)
{
    EXPECT_EQ(f1.getFirst(), 0);
    EXPECT_EQ(f1.getSecond(), 1);
}

// Перевірка конструктора з параметрами
TEST_F(FractionTest, ParameterizedConstructor)
{
    EXPECT_EQ(f2.getFirst(), 3);
    EXPECT_EQ(f2.getSecond(), 4);
}

// Перевірка копіювання
TEST_F(FractionTest, CopyConstructor)
{
    EXPECT_EQ(f3.getFirst(), 3);
    EXPECT_EQ(f3.getSecond(), 4);
}

// Перевірка Init з правильними даними
TEST_F(FractionTest, InitValid)
{
    Fraction f;
    EXPECT_NO_THROW(f.Init(5, 2));
    EXPECT_EQ(f.getFirst(), 5);
    EXPECT_EQ(f.getSecond(), 2);
}

// Перевірка Init з неправильними даними: знаменник 0
TEST_F(FractionTest, InitInvalid)
{
    Fraction f;
    EXPECT_THROW(f.Init(5, 0), FractionException);
}

// Перевірка Init з негативним чисельником і нульовим знаменником
TEST_F(FractionTest, InitInvalidOwnException)
{
    Fraction f;
    try
    {
        f.Init(-5, 0);
        FAIL() << "Очікувався виняток FractionException або OwnException*";
    }
    catch (FractionException &e)
    {
        EXPECT_STREQ(e.what(), "Неправильні дані: чисельник від'ємний, знаменник нуль (передача за посиланням).");
    }
    catch (OwnException *e)
    {
        FAIL() << "Отримано OwnException, а очікувався FractionException за негативним чисельником!";
        delete e;
    }
}

// Перевірка обробки неправильного введення через istream
TEST_F(FractionTest, InputStreamInvalid)
{
    Fraction f;
    std::istringstream iss("invalid_input");
    EXPECT_THROW(iss >> f, std::invalid_argument);
}

// Перевірка перетворення до рядка
TEST_F(FractionTest, ToString)
{
    std::string str = static_cast<std::string>(f2);
    EXPECT_EQ(str, "3/4");
}

// Перевірка ipart() при коректному знаменнику
TEST_F(FractionTest, IPartValid)
{
    EXPECT_NO_THROW({
        int part = f2.ipart();
        EXPECT_EQ(part, 0);
    });
}

// // Перевірка ipart() при нульовому знаменнику
// TEST_F(FractionTest, IPartThrowsBadException)
// {
//     Fraction f(5, 0);
//     EXPECT_THROW(f.ipart(), std::bad_exception);
// }

TEST_F(FractionTest, IncrementDecrementOperators)
{
    Fraction f(2, 5);
    EXPECT_EQ((++f).getFirst(), 3);
    EXPECT_EQ((f++).getFirst(), 3);
    EXPECT_EQ(f.getFirst(), 4);

    EXPECT_EQ((--f).getFirst(), 3);
    EXPECT_EQ((f--).getFirst(), 3);
    EXPECT_EQ(f.getFirst(), 2);
}

// Перевірка setSecond з викиданням винятку
TEST_F(FractionTest, SetSecondThrowsInvalidArgument)
{
    Fraction f;
    EXPECT_THROW(f.setSecond(0), std::invalid_argument);
}

#include <iostream>
#include "Fraction.h"

#ifndef UNIT_TESTING
int main()
{
    try
    {
        Fraction f1;
        Fraction f2(3, 4);
        Fraction f3 = f2;
        Fraction f4 = makeFraction(5, 6);

        std::cout << "f1: " << f1 << std::endl;
        std::cout << "f2: " << f2 << std::endl;
        std::cout << "f3: " << f3 << std::endl;
        std::cout << "f4: " << f4 << std::endl;

        Fraction f5;
        std::cout << "Введіть дріб у форматі a/b: ";
        std::cin >> f5;
        std::cout << "Ви ввели: " << f5 << std::endl;

        std::cout << "Ціла частина дробу f5: " << f5.ipart() << std::endl;

        std::cout << "Префіксний інкремент f2: " << ++f2 << std::endl;
        std::cout << "Після префіксного інкременту f2: " << f2 << std::endl;

        std::cout << "Постфіксний інкремент f2: " << f2++ << std::endl;
        std::cout << "Після постфіксного інкременту f2: " << f2 << std::endl;

        std::cout << "Префіксний декремент f2: " << --f2 << std::endl;
        std::cout << "Після префіксного декременту f2: " << f2 << std::endl;

        std::cout << "Постфіксний декремент f2: " << f2-- << std::endl;
        std::cout << "Після постфіксного декременту f2: " << f2 << std::endl;

        std::string strF2 = static_cast<std::string>(f2);
        std::cout << "f2 у рядковому вигляді: " << strF2 << std::endl;
    }
    catch (FractionException &e)
    {
        std::cerr << "FractionException: " << e.what() << std::endl;
    }
    catch (OwnException *e)
    {
        std::cerr << "OwnException: " << e->what() << std::endl;
        delete e;
    }
    catch (std::invalid_argument &e)
    {
        std::cerr << "invalid_argument: " << e.what() << std::endl;
    }
    catch (std::bad_exception &e)
    {
        std::cerr << "bad_exception: Сталася помилка з доступом до знаменника!" << std::endl;
    }
    catch (...)
    {
        std::cerr << "Невідома помилка!" << std::endl;
    }

    return 0;
}
#endif

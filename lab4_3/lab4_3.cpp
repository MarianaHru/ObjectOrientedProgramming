// main.cpp
#include <iostream>
#include "Decimal.h"
#include "BitString.h"
#ifndef UNIT_TESTING
int main()
{
    try
    {

        Decimal dec1(5, 3);
        Decimal dec2(5, 4);

        std::cout << "Decimal 1: ";
        dec1.print();
        std::cout << "Decimal 2: ";
        dec2.print();

        Array *decSum = dec1.add(dec2);
        std::cout << "Decimal sum: ";
        decSum->print();
        delete decSum;

        BitString bit1(8);
        BitString bit2(8);

        for (int i = 0; i < 8; ++i)
        {
            bit1[i] = (i % 2);
            bit2[i] = ((i + 1) % 2);
        }

        std::cout << "\nBitString 1: ";
        bit1.print();
        std::cout << "BitString 2: ";
        bit2.print();

        Array *bitSum = bit1.add(bit2);
        std::cout << "Bitwise OR result: ";
        bitSum->print();
        delete bitSum;
    }
    catch (const std::exception &ex)
    {
        std::cerr << "Error: " << ex.what() << std::endl;
    }

    return 0;
}
#endif
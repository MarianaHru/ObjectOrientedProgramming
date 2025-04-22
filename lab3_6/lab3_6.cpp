#include <iostream>
#include "B.h"
#include "D1.h"
#include "D2.h"
#include "D3.h"
#include "D4.h"
using namespace std;

#ifndef UNIT_TESTING
int main()
{
     cout << "=== Об'єкт B ===" << endl;
     B bObj(10);
     cout << bObj << endl;

     cout << "\n=== Об'єкт D1 ===" << endl;
     D1 d1Obj(11, 21);
     cout << d1Obj << endl;
     cout << "D1 -> B: " << d1Obj.get_b()
          << ", D1: " << d1Obj.get_d1() << endl;

     cout << "\n=== Об'єкт D2 ===" << endl;
     D2 d2Obj(12, 22);
     cout << d2Obj << endl;
     cout << "D2 -> B: " << d2Obj.get_b()
          << ", D2: " << d2Obj.get_d2() << endl;

     cout << "\n=== Об'єкт D3 ===" << endl;
     D3 d3Obj(13, 23, 33);
     cout << d3Obj << endl;
     cout << "D3 -> B: " << d3Obj.get_b()
          << ", D1: " << d3Obj.get_d1()
          << ", D3: " << d3Obj.get_d3() << endl;

     cout << "\n=== Об'єкт D4 ===" << endl;
     D4 d4Obj(14, 24, 34, 44, 54);
     cout << d4Obj << endl;
     cout << "D4 -> B: " << d4Obj.get_b()
          << ", D2: " << d4Obj.get_d2()
          << ", D1: " << d4Obj.get_d1()
          << ", D4: " << d4Obj.get_d4() << endl;

     cout << "\n=== Розміри об'єктів у байтах ===" << endl;
     cout << "sizeof(B): " << sizeof(B) << " байт" << endl;
     cout << "sizeof(D1): " << sizeof(D1) << " байт" << endl;
     cout << "sizeof(D2): " << sizeof(D2) << " байт" << endl;
     cout << "sizeof(D3): " << sizeof(D3) << " байт" << endl;
     cout << "sizeof(D4): " << sizeof(D4) << " байт" << endl;

     return 0;
}
#endif

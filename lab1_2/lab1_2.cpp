#include "List.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    List l;
    l.Read();
    l.Display();
    cout << "List after adding values: " << endl;

    l.sort();
    cout << "Sorted list: " << endl;
    l.Display();

    int rem;
    cout << "Enter value to remove from the list: ";
    cin >> rem;
    l.remove(rem);

    cout << "List after removal: ";
    l.Display();

    return 0;
}
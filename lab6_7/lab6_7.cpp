#include <iostream>
using namespace std;

// Інтерфейс-функтор (унарний предикат)
template <class T>
class Predicate
{
public:
    virtual bool operator()(T x) = 0;
};

// Функтор: значення додатне
template <class T>
class Positive : public Predicate<T>
{
public:
    virtual bool operator()(T x)
    {
        return x > 0;
    }
};

// Функтор: значення нуль
template <class T>
class Zero : public Predicate<T>
{
public:
    virtual bool operator()(T x)
    {
        return x == 0;
    }
};

// Копіювання всіх елементів з одного діапазону в інший
template <class T>
int my_copy(T *begin, T *end, T *to)
{
    int count = 0;
    for (T *from = begin; from < end; ++from)
    {
        *to = *from;
        ++to;
        ++count;
    }
    return count;
}

// Копіювання лише тих елементів, що задовольняють умову (предикат)
template <class T>
int my_copy_if(T *begin, T *end, T *to, Predicate<T> &pred)
{
    int count = 0;
    for (T *from = begin; from < end; ++from)
    {
        if (pred(*from))
        {
            *to = *from;
            ++to;
            ++count;
        }
    }
    return count;
}

int main()
{
    int a[6] = {-1, 0, 2, -3, 4, 0};
    int b[6], c[6], d[6];

    // Копіюємо всі елементи
    int n1 = my_copy(&a[0], &a[6], &b[0]);
    cout << "copy: ";
    for (int i = 0; i < n1; ++i)
    {
        cout << b[i] << ' ';
    }
    cout << endl;

    // Копіюємо лише ті, що == 0
    Zero<int> zero;
    int n2 = my_copy_if(&a[0], &a[6], &c[0], zero);
    cout << "copy_if (zero): ";
    for (int i = 0; i < n2; ++i)
    {
        cout << c[i] << ' ';
    }
    cout << endl;

    // Копіюємо лише додатні
    Positive<int> pos;
    int n3 = my_copy_if(&a[0], &a[6], &d[0], pos);
    cout << "copy_if (positive): ";
    for (int i = 0; i < n3; ++i)
    {
        cout << d[i] << ' ';
    }
    cout << endl;

    return 0;
}

#include "header.h"

int main()
{
    double **p = nullptr; // дано
    double a = 2.0; // число в квадрате
    double *pa = &a; // создали указатель на квадрат
    delete p; // убрали ноль из р
    p = &pa;  // присвоили новое значение
    std::cout << **p << "\n"; // вывод числа в квадрате

    delete p;
    delete pa; // удалили все динамические объекты

    return 0;
}
#include "header.h"

void swap(int *ptr1, int *ptr2)
{
    int x;
    x = *ptr1;
    *ptr1=*ptr2;
    *ptr2=x;
}

int main()
{
    std::cout << "Enter the a: ";
    int a;
    std::cin >> a;
    std::cout << "Enter the b: ";
    int b;
    std::cin >> b;
    // значения до
    std::cout << a << " " << b << "\n";
    int *ptr1 = &a;
    int *ptr2 = &b;

    swap(ptr1, ptr2);
    // значения после
    std::cout << a << " " << b << "\n";

    return 0;
}
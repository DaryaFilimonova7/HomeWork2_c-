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
    std::cout << "Enter the length: ";
    int n;
    std::cin >> n;
    int *a = new int[n];
    //запрос элементов массива
    std::cout << "Enter the elements: \n";
    for (int i = 0; i<n;i++)
    {
        std::cin >> a[i];
    }
    // указатели на первый и последний эл-ты массива
    int *ptrFirst = &a[0];
    int *ptrLast = &a[n-1];

    swap(ptrFirst,ptrLast);

    for (int i = 0; i<n;i++)
    {
        std::cout << a[i] << " ";
    }
    std::cout << "\n";


    return 0;
}
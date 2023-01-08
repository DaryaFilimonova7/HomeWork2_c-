#include "header.h"

template <typename T>
void bubble_sort(T arr[], int idx_start, int idx_end)
{
    for (int n= idx_start;n < idx_end;n++)
    {
        for (int i = idx_start; i < idx_end; i++)
        {
            if (arr[i]>arr[i+1])
            {
                std::swap(arr[i],arr[i+1]);
            }
        }
    }
}

template <typename T>
void merger(T num1[],T num2[],int m,int n)
{
    // заменяем эл-ты 1го массива с m-ного эл-та на эл-ты второго
    int j = 0;
    for (int i = m; i<n+m; i++)
    {
        num1[i] = num2[j];
        j++;
    }
    bubble_sort(num1,0,n+m-1);
}


int main()
{
    int m,n;
    std::cout << "Enter the length of the 1st array: ";
    std::cin >> m;
    std::cout << "Enter the length of the 2nd array: ";
    std::cin >> n;

    int *num1 = new int[m+n];
    std::cout << "Enter the elements of the 1st array: \n";
    for (int i = 0; i<m;i++)
    {
        std::cin >> num1[i];
    }
    // оставшуюся часть массива заполняем нулями
    for (int i = m; i<m+n;i++)
    {
        num1[i] = 0;
    }

    int *num2 = new int[n];
    std::cout << "Enter the elements of the 2nd array: \n";
    for (int i = 0; i<n;i++)
    {
        std::cin >> num2[i];
    }

    merger(num1,num2,m,n);

    for (int i = 0; i<n+m;i++)
    {
        std::cout << num1[i] << " ";
    }
    std::cout << "\n";

    return 0;
}
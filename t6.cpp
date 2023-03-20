#include "header.h"

template <typename T>
void changing_parts(int *ptr, T arr[], int idx_start, int idx_end) {
    int y = (idx_end+1)/2;
    for (int i = idx_start; i <= idx_end/2; i++) {
        double x = arr[i];
        arr[i] = arr[y];
        arr[y++] = x;
        *ptr +=1;

    }
}


int main()
{
    int n = 14;
    double *arr = new double[n];
    int counter;
    int *ptr = &counter;
    //запрос элементов массива
    std::cout << "Enter 14 elements: \n";
    for (int i = 0; i<n;i++)
    {
        std::cin >> arr[i];
    }

    changing_parts(ptr, arr, 0, n-1);

    std::cout << "The number of changes is : " << counter << "\n";
    for (int i = 0; i<n;i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    return 0;
}

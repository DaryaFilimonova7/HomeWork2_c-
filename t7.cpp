#include "header.h"

template <typename T>
void localmin(T arr[], int idx_start, int idx_end, int *ptrMin)
{
    for (int i = idx_start + 1; i <= idx_end -1; i++) {
        // сравниваем с элем-том справа и слева
        if (arr[i-1] < arr[i] && arr[i+1] < arr[i]) {
            *ptrMin = *ptrMin +1;
        }
    }
}

int main()
{
    std::cout << "Enter the length: ";
    int n;
    std::cin >> n;
    int *arr = new int[n];
    int locmin = 0;
    int *ptrMin = &locmin;
    //запрос элементов массива
    std::cout << "Enter the elements: \n";
    for (int i = 0; i<n;i++)
    {
        std::cin >> arr[i];
    }
    localmin(arr, 0, n-1,ptrMin);
    std::cout << "The number of local minimums: " << locmin << "\n";

    return 0;
}
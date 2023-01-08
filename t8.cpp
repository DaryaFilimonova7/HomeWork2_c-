#include "header.h"

template <typename T>
void between_zero(T arr[], int idx_start, int idx_end, int *ptr)
{
    int idx_zero1 = -1;
    int idx_zero2 = -1;
    int sum;
    for (int i = idx_start; i <= idx_end; i++)
    {
        // находим эл-ты, равные 0, и помечаем их
        if (arr[i] == 0) {
            if (idx_zero1 == -1)
            {
                idx_zero1 = i;
            }
            else
            {
                idx_zero2 = i;
            }
        }
    }
    // суммируем эл-ты между нулями
    for (int j = idx_zero1 + 1; j < idx_zero2; j++)
    {
        sum = sum + arr[j];
    }
    *ptr = sum;
}


int main()
{
    int arr[3][7] = {
            { 3, 0, 1, 6, 0, 2, 4 },
            { 8, 3, 0, 4, 12, 2, 0 },
            { 6, 7, 0, 5, 5, 0, 11}
    };
    int sum1,sum2,sum3;
    // иницициализируем ptr адресом нужной суммы
    int *ptr = &sum1;
    // отправляем в функцию каждую строку
    between_zero(arr[0], 0, 6, ptr);
    std::cout << "The 1st sum is: " << sum1 << "\n";
    ptr = &sum2;
    between_zero(arr[1], 0, 6, ptr);
    std::cout << "The 2nd sum is: " << sum2 << "\n";
    ptr = &sum3;
    between_zero(arr[2], 0, 6, ptr);
    std::cout << "The 3rd sum is: " << sum3 << "\n";

    return 0;
}

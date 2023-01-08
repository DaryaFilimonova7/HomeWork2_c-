#include "header.h"

template <typename T>
void insertion_sort(T arr[], int idx_start, int idx_end, int *ptr) {
    for (int i = idx_start+1; i <= idx_end; i++) {
        int element = arr[i];           // выбираем эл-т
        int idx_right = i - 1;
        // сравниваем с элем-том справа, пока не пришли к началу
        while (arr[idx_right] < element && idx_right >= idx_start) {
            arr[idx_right + 1] = arr[idx_right];            // меняем выбранный элемент
            idx_right = idx_right - 1;// перемещаемся вправо
            *ptr = *ptr +1;
        }
        arr[idx_right + 1] = element;    //меняем правый эл-т
        *ptr = *ptr +1;

    }
}

int main()
{
    int n = 12;
    int *arr = new int[n];
    int counter;
    int *ptr = &counter;
    //запрос элементов массива
    std::cout << "Enter 12 elements: \n";
    for (int i = 0; i<n;i++)
    {
        std::cin >> arr[i];
    }
    insertion_sort(arr,0,n-1, ptr);
    std::cout << "The number of changes is : " << counter << "\n";
    for (int i = 0; i<n;i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    return 0;
}

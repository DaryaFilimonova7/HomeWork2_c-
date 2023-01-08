#include "header.h"

template <typename T>
void change(T arr[], int idx_start, int idx_end)
{
    int element = arr[idx_end];
    for (int i = idx_end-1; i >= idx_start; i--)
    {
        // смещаем эл-ты вправо
        arr[i+1] = arr[i];
    }
    // ставим последний эл-т на первое место
    arr[idx_start] = element;
}


int main()
{
    int n =3;
    int m =7;
    int arr[3][7] = {
            { 3, 0, 1, 6, 0, 2, 4 },
            { 8, 3, 0, 4, 12, 2, 0 },
            { 6, 7, 0, 5, 5, 0, 11}
    };
    // отправляем в функцию каждую строку
    for (int i = 0; i < n; i++) {
        change(arr[i], 0, 6);
    }
    // вывод результата
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            std::cout << " " << arr[i][j];
        std::cout << "\n";
    }

    return 0;
}

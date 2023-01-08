#include <iostream>
using namespace std;
int main()
{
    const int m = 3, n = 3; // обьявление размерности матрицы
    int A[m][n]; //обьявление матрицы
    int i, j, min_num = 0, max_num = 0, min = 0, max = 0, sum = 0; //обьявление переменных
    cout << "Enter dimension matrix " << m << " x " << n << "\n"; //запрос на ввод матрицы
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            cin >> A[i][j]; //чтение элемента матрицы из потока ввода
            if (i == 0) //если строка первая
            {
                sum += A[i][j]; //считаем сумму
                min += A[i][j]; //по умолчанию считаем что сумма первой строки минимальная
                max += A[i][j]; // она же максимальная
            }
            else sum += A[i][j]; //для всех остальных строк просто считаем сумму
        }
        if (sum > max) //если сумма строки больше максимальной
        {
            max = sum;  //максимальному значению присваиваем сумму этой строчки.
            max_num = i; //номер текущей строки присваиваем номеру максимальной строки по умолчанию
        }
        if (sum < min)
        {
            min = sum; //минимальному значению присваиваем сумму этой строчки.
            min_num = i; //номер текущей строки присваиваем номеру минимальной строки по умолчанию
        }
        sum = 0; //перед переходом на новую строку обнуляем сумму
    }
    i = min_num;
    cout << "\nstring with minimum sum of elements - ";
    for (j = 0; j < n; j++) cout << A[i][j] << " "; //вывод минимальной строки
    cout << ", the sum of its elements = " << min; //и ее суммы
    i = max_num;
    cout << "\nstring with maximum sum of elements - "; //аналогично для максимальной строки
    for (j = 0; j < n; j++) cout << A[i][j] << " ";
    cout << ", the sum of its elements = " << max;
    return 0;
}

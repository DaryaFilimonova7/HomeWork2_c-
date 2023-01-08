#include <iostream>
using namespace std;
int main()
{
    const int m = 3, n = 3; 
    int A[m][n]; 
    int i, j, min_num = 0, max_num = 0, min = 0, max = 0, sum = 0; 
    cout << "Enter dimension matrix " << m << " x " << n << "\n"; 
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            cin >> A[i][j]; 
            if (i == 0) 
            {
                sum += A[i][j]; 
                min += A[i][j];
                max += A[i][j]; 
            }
            else sum += A[i][j]; 
        }
        if (sum > max) 
        {
            max = sum;  
            max_num = i; 
        }
        if (sum < min)
        {
            min = sum; 
            min_num = i; 
        }
        sum = 0; 
    }
    i = min_num;
    cout << "\nstring with minimum sum of elements - ";
    for (j = 0; j < n; j++) cout << A[i][j] << " "; 
    cout << ", the sum of its elements = " << min;
    i = max_num;
    cout << "\nstring with maximum sum of elements - "; 
    for (j = 0; j < n; j++) cout << A[i][j] << " ";
    cout << ", the sum of its elements = " << max;
    return 0;
}

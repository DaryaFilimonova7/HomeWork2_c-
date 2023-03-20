#include "header.h"

int main()
{
    int n = 15;
    int *arr = new int[n];
    
    //запрос элементов массива
    std::cout << "Enter 14 elements: \n";
    for (int i = 0; i<n;i++)
    {
        std::cin >> arr[i];
    }
  
  for (int i = 0; i<n;i++)
    {
        if (arr[i] < 0) {
          
        }
    }
  
  
  sort_signed();
  sort_unsigned();

    return 0;
}

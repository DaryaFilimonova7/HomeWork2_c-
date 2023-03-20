#include "header.h"

void sort_signed(int* arrA, int n) {
    int otr = 0;
    for(int i = 0; i < n - 1; ++i)
    {
        for(int j = 0; j < n - 1; ++j)
        {
            if (arrA[j + 1] > arrA[j])
            {
                otr = arrA[j + 1];
                arrA[j + 1] = arrA[j];
                arrA[j] = otr;
            }
        }
    }
}
void sort_unsigned(int* arrA, int n) {
    int pol=0;
    for(int i = 0; i < n - 1; ++i)
    {
        for(int j = 0; j < n - 1; ++j)
        {
            if (arrA[j + 1] < arrA[j])
            {
                pol = arrA[j + 1];
                arrA[j + 1] = arrA[j];
                arrA[j] = pol;
            }
        }
    }
}



int main()
{
    int n = 15;
    int *arr = new int[n];
    
    //запрос элементов массива
    std::cout << "Enter 15 elements: \n";
    for (int i = 0; i<n;i++)
    {
        std::cin >> arr[i];
    }
    
    int *arr_s = new int[n];
    int *arr_uns = new int[n];
    int s = 0;
    int uns = 0;
    size_s, size_uns;
  
  for (int i = 0; i<n;i++)
    {
        if (arr[i] < 0) {
            arr_s[s] = arr[i];
            s++;
            size_s++;
        }
      else {
          arr_uns[uns] = arr[i];
          uns++;
          size_uns++;
      }
    }
  
  
  sort_signed(arr_s, size_s);
  sort_unsigned(arr_ins,size_uns);
    
    for (int i = 0; i<size_uns;i++)
    {
        std::cout << arr_uns[i] << " ";
    }
    std::cout << "\n";
    for (int i = 0; i<size_uns;i++)
    {
        std::cout << arr_s[i] << " ";
    }
    std::cout << "\n";

    delete[] arr;
    delete[] arr_s;
    delete[] arr_uns;

    return 0;
}

#include <iostream>
void swap(int *ptr1, int *ptr2)
{
    int x;
    x = *ptr1;
    *ptr1=*ptr2;
    *ptr2=x;
}
template <typename T>
void insertion_sort(T arr[], int idx_start, int idx_end, int *ptr) {
    for (int i = 1; i <= idx_end; i++) {
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


int main() {

    //1
    {
        std::cout << "Enter the a: ";
        int a;
        std::cin >> a;
        std::cout << "Enter the b: ";
        int b;
        std::cin >> b;
        // значения до
        std::cout << a << " " << b << "\n";
        int *ptr1 = &a;
        int *ptr2 = &b;

        swap(ptr1,ptr2);
        // значения после
        std::cout << a << " " << b << "\n";
    }
    //2
    {
        std::cout << "Enter the length: ";
        int n;
        std::cin >> n;
        int *a = new int[n];
        //запрос элементов массива
        std::cout << "Enter the elements: \n";
        for (int i = 0; i<n;i++)
        {
            std::cin >> a[i];
        }
        // указатели на первый и последний эл-ты массива
        int *ptrFirst = &a[0];
        int *ptrLast = &a[n-1];

        swap(ptrFirst,ptrLast);

        for (int i = 0; i<n;i++)
        {
            std::cout << a[i] << " ";
        }
        std::cout << "\n";
    }
    //3
    {
       double **p = 0; // дано
       double a = 2.0; // число в квадрате
       double *pa = &a; // создали указатель на квадрат
       delete p; // убрали ноль из р
       p = &pa;  // присвоили новое значение
       std::cout << **p << "\n"; // вывод числа в квадрате

       delete p;
       delete pa; // удалили все динамические объекты

    }

    //4
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
    }
    //5
    {
        
    }
    //7
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
    }


    return 0;
}

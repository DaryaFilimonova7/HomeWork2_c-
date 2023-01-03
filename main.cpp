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

template <typename T>
void bubble_sort(T arr[], int idx_start, int idx_end)
{
    for (int n= idx_start;n < idx_end;n++)
    {
        for (int i = idx_start; i < idx_end; i++)
        {
            if (arr[i]>arr[i+1])
            {
                std::swap(arr[i],arr[i+1]);
            }
        }
    }
}

template <typename T>
void merger(T num1[],T num2[],int m,int n)
{
    // заменяем эл-ты 1го массива с m-ного эл-та на эл-ты второго
    int j = 0;
    for (int i = m; i<n+m; i++)
        {
            num1[i] = num2[j];
            j++;
        }
    bubble_sort(num1,0,n+m-1);
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
    //8
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
    }
   
    //11
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
    }
    
    //13
    {
        int m,n;
        std::cout << "Enter the length of the 1st array:  ";
        std::cin >> m;
        std::cout << "Enter the length of the 2nd array:  ";
        std::cin >> n;

        int *num1 = new int[m+n];
        std::cout << "Enter the elements of the 1st array: \n";
        for (int i = 0; i<m;i++)
        {
            std::cin >> num1[i];
        }
        // оставшуюся часть 1го массива заполняем нулями
        for (int i = m; i<m+n;i++)
        {
            num1[i] = 0;
        }

        int *num2 = new int[n];
        std::cout << "Enter the elements of the 2nd array: \n";
        for (int i = 0; i<n;i++)
        {
            std::cin >> num2[i];
        }

        merger(num1,num2,m,n);

        for (int i = 0; i<n+m;i++)
        {
            std::cout << num1[i] << " ";
        }
        std::cout << "\n";
    }


    return 0;
}

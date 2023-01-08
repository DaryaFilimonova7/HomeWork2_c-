#include <iostream>
using namespace std;

int main()
{
    size_t n, m;
    cout << "Size matrix 1: "; cin >> n;
    cout << "Size matrix 2: "; cin >> m;

    double* a = new double[n], max_a = 0;
    double* b = new double[m], max_b = 0;

    for (size_t i = 0; i < n; i++)
    {
        a[i] = rand() % 11 + 1;
        cout << a[i] << " ";
        if (i == 0 || a[i] > max_a) max_a = a[i];
    }
    cout << " " << "max_a = " << max_a << "\n";

    for (size_t i = 0; i < m; i++) {
        b[i] = rand() % 21 + 1;
        cout << b[i] << " ";
        if (i == 0 || b[i] > max_b) max_b = b[i];
    }
    cout << " " << "max_b = " << max_b;

    cout << "\nNew matrix: \n";
    for (size_t i = 0; i < n; i++) {
        if (a[i] == max_a) a[i] = max_b;
        cout << a[i] << " ";
    }
    cout << "\n";
    for (size_t i = 0; i < m; i++) {
        if (b[i] == max_b) b[i] = max_a;
        cout << b[i] << " ";
    }
    cout << "\n";

    delete[]b;
    delete[]a;
    return 0;
}
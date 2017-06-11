#include <iostream>
using namespace std;

int ga[10] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};

void f(int *arr, int sz)
{
    int la[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    for (int i = 0; i < sz; ++i)
    {
        la[i] = ga[i];
    }
    for (int i = 0; i < 10; ++i)
    {
        cout << la[i] << "\t";
    }
    cout << endl;
    int *p = new int[sz];
    for (int i = 0; i < sz; ++i)
    {
        p[i] = arr[i];
    }
    for (int i = 0; i < sz; ++i)
    {
        cout << p[i] << "\t";
    }
    cout << endl;
    delete[] p;
}

int main()
{
    f(ga, 10);
    int aa[10] = {1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800};
    f(aa, 10);
    return 0;
}
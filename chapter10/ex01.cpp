/*
Write a program that produces the sum of all the numbers in a file of whitespace-separated integers.
*/

#include "../std_lib_facilities.h"
#include <iostream>
#include <fstream>
using namespace std;

void do_sum()
{
    ifstream ifs{"./chapter10/myint.txt"};
    if (!ifs)
        error("File Error");
    int sum = 0;
    while (ifs)
    {
        int i;
        ifs >> i;
        sum += i;
    }
    cout << sum << endl;
}
int main()
{
    try
    {
        do_sum();
    }
    catch (exception &ex)
    {
        cerr << ex.what() << endl;
        keep_window_open("1");
    }
    return 0;
}
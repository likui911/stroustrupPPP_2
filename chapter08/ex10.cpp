/*
Write a function maxv() that returns the largest element of a vector argument.
*/
#include "../std_lib_facilities.h"
#include <limits>

int maxv(const vector<int> &vec)
{
    int largest = INT_MIN;
    for (int i : vec)
    {
        if (i > largest)
            largest = i;
    }
    return largest;
}

int main()
{
    vector<int> vec_i{1, 2, 3, 4, 9, 8, 4, 6, 5};
    cout << maxv(vec_i) << endl;
    return 0;
}
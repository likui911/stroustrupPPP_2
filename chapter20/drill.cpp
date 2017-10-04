#include <vector>
#include <list>
#include <iostream>

template <typename Iter1, typename Iter2>
Iter2 copy(Iter1 f1, Iter1 e1, Iter2 f2)
{
    for (f1; f1 != e1; ++f1, ++f2)
    {
        *f1 = *f2;
    }
    return f2;
}

int main()
{
    int arr[]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    std::list<int> lst{2, 3, 4, 5, 6, 7, 8, 9, 0, 1};

    /*
    template programming: ambiguous call to overloaded function
    https://stackoverflow.com/questions/30421911/template-programming-ambiguous-call-to-overloaded-function
    */
    int arr1[10];
    copy(arr, arr + 10, arr1);
    //copy the array into the std::vector
    (copy)(arr, arr + 10, vec.begin());
    //copy the std::list into the array
    (copy)(lst.begin(), lst.end(), arr);

    return 0;
}
/*
Get the Jack-and-Jill example from §20.1.2 to work. 
Use input from a couple of small files to test it.
*/
#include <vector>
#include <iostream>

template <typename  Iterator>
Iterator higher(Iterator first, Iterator last)
{
    Iterator h = first;
    while (first != last)
    {
        if (*first > *h)
        {
            *h = *first;
        }
        ++first;
    }
    return h;
}

int main()
{
    std::vector<double> vec{-0.6, 1.6, 6.5, -698.6, 33};
    double arr[]{-0.6, 1.6, 6.5, -698.6, 33};
    std::cout << *higher(vec.begin(), vec.end()) << std::endl;
    std::cout << *higher(arr, arr + sizeof(arr)) << std::endl;
    return 0;
}
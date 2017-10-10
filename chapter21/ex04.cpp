/*
 Implement count_if() yourself. Test it.
*/
#include <iterator>
#include <iostream>
#include <vector>
using namespace std;

template <class InputIterator, class UnaryPredicate>
typename iterator_traits<InputIterator>::difference_type
count_if(InputIterator first, InputIterator last, UnaryPredicate pred)
{
    typename iterator_traits<InputIterator>::difference_type ret = 0;
    while (first != last)
    {
        if (pred(*first))
            ++ret;
        ++first;
    }
    return ret;
}

bool IsOdd(int i) { return ((i % 2) == 1); }

int main()
{
    std::vector<int> myvector;
    for (int i = 1; i < 10; i++)
        myvector.push_back(i); // myvector: 1 2 3 4 5 6 7 8 9

    int mycount = count_if(myvector.begin(), myvector.end(), IsOdd);
    std::cout << "myvector contains " << mycount << " odd values.\n";

    return 0;
}
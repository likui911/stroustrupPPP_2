/*
Write a binary search function for a vector<int> (without using the standard one).
You can choose any interface you like.
Test it. How confident are you that your binary search function is correct? 
Now write a binary search function for a list<string>. 
Test it. How much do the two binary search functions resemble each other? 
How much do you think they would have resembled each other if you had not known about the STL?
*/
#include <vector>
#include <list>
#include <string>
#include <iterator>
#include <iostream>

using namespace std;

template <class ForwardIterator, class T>
bool binary_search(ForwardIterator first, ForwardIterator last, const T &val)
{
    typename iterator_traits<ForwardIterator>::difference_type count = distance(first, last);
    ForwardIterator mid = first + count / 2;

    if (first == last)
        return false;

    if (val < *mid)
        return binary_search(first, mid, val);
    else if (val > *mid)
        return binary_search(mid + 1, last, val);

    return true;
}

int main()
{
    vector<int> vi{1, 3, 5, 7, 9, 11, 15, 19};
    if (binary_search(vi.begin(), vi.end(), 8))
    {
        cout << "found" << endl;
    }
    else
    {
        cout << "not found" << endl;
    }
    return 0;
}
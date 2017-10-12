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

template <class Iterator, class T>
bool binary_search(Iterator first, Iterator last, const T &val)
{
    typename iterator_traits<Iterator>::difference_type count = distance(first, last);
    Iterator mid = first;
    std::advance(mid, count / 2);

    if (first == last)
        return false;

    if (val < *mid)
        return binary_search(first, mid, val);
    else if (val > *mid)
    {
        std::advance(mid, 1);
        return binary_search(mid, last, val);
    }

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
    list<string> ls;
    string s1{"ahello"};
    string s2{"bgood"};
    string s3{"cmorning"};
    string s4{"djack"};
    ls.push_back(s1);
    ls.push_back(s2);
    ls.push_back(s3);
    ls.push_back(s4);
    if (binary_search(ls.begin(), ls.end(), string("bgood")))
    {
        cout << "found" << endl;
    }
    else
    {
        cout << "not found" << endl;
    }
    return 0;
}
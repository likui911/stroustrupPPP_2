/*
 Find the lexicographical last string in an unsorted vector<string>.
*/
#include <fstream>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

template <typename Iter>
Iter find_the_last(Iter iter1, Iter iter2)
{
    if (iter1 == iter2)
    {
        return iter1;
    }
    Iter last = iter1;

    for (; iter1 != iter2; ++iter1)
    {
        if (*last > *iter1)
        {
            *last = *iter1;
        }
    }
    return last;
}

int main()
{
    ifstream fis("./chapter20/docu.txt");
    string s;
    vector<string> vec_s;
    while (fis >> s)
    {
        vec_s.push_back(s);
    }

    cout << *find_the_last(vec_s.begin(), vec_s.end()) << endl;
    return 0;
}
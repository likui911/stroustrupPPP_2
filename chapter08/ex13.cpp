/*
Write a function that takes a vector<string> argument and returns a vector<int> 
containing the number of characters in each string. Also find the longest and 
the shortest string and the lexicographically first and last string. How many
separate functions would you use for these tasks? Why?
*/
#include "../std_lib_facilities.h"

vector<int> func(const vector<string> &vec)
{
    vector<int> vec_i;
    for (string s : vec)
    {
        vec_i.push_back(s.size());
    }
    return vec_i;
}

int main()
{
    vector<string> vec{"abc", "dddddef"};
    vector<int> vec_i = func(vec);
    for (int i : vec_i)
    {
        cout << i << endl;
    }
    return 1;
}
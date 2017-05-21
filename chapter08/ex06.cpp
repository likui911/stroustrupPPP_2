/*
 Write versions of the functions from exercise 5, but with a vector<string>.
*/

#include <vector>
#include <iostream>
#include <string>
using namespace std;

vector<string> reverse_1(const vector<string> &vec)
{
    vector<string> result;
    for (string i : vec)
    {
        result.insert(result.begin(), i);
    }
    return result;
}

void reverse_2(vector<string> &vec)
{
    for (int i = 0; i < vec.size() / 2; ++i)
    {
        string temp = vec[i];
        vec[i] = vec[vec.size() - i - 1];
        vec[vec.size() - i - 1] = temp;
    }
}

int main()
{
    vector<string> vec{"a","b","c","d"};
    vector<string> rvs_v=reverse_1(vec);
    cout<<"-----reverse_1---------"<<endl;
    for (string i : rvs_v)
    {
        cout << i << endl;
    }
    cout<<"-----reverse_2---------"<<endl;
    reverse_2(vec);
    for (string i : vec)
    {
        cout << i << endl;
    }
    return 0;
}
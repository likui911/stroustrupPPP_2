/*
Write two functions that reverse the order of elements in a vector<int>. 
For example, 1, 3, 5, 7, 9 becomes 9, 7, 5, 3, 1.
The first reverse function should produce a new vector with the reversed sequence, 
leaving its original vector unchanged. The other reverse function should reverse the 
elements of its vector without using any other vectors (hint:swap)
*/
#include <vector>
#include <iostream>
using namespace std;

vector<int> reverse_1(const vector<int> &vec)
{
    vector<int> result;
    for (int i : vec)
    {
        result.insert(result.begin(), i);
    }
    return result;
}

void reverse_2(vector<int> &vec)
{
    for (int i = 0; i < vec.size() / 2; ++i)
    {
        int temp = vec[i];
        vec[i] = vec[vec.size() - i - 1];
        vec[vec.size() - i - 1] = temp;
    }
}

int main()
{
    vector<int> vec{1, 2, 3, 4};
    vector<int> rvs_v=reverse_1(vec);
    cout<<"-----reverse_1---------"<<endl;
    for (int i : rvs_v)
    {
        cout << i << endl;
    }
    cout<<"-----reverse_2---------"<<endl;
    reverse_2(vec);
    for (int i : vec)
    {
        cout << i << endl;
    }
    return 0;
}
/*
Write a template function f() that adds the elements of one vector<T> to the elements of another; for example, f(v1,v2)
should do v1[i]+=v2[i] for each element of v1
*/
#include <vector>
#include <iostream>

using namespace std;

template<typename T>
void f(vector<T> &v1,const vector<T> &v2)
{
    auto iter1=v1.begin();
    auto iter2=v2.cbegin();
    for(;iter1!=v1.end();++iter1,++iter2)
    {
        *iter1+=*iter2;
    }
}

int main()
{
    vector<int> v1={1,2,3,4,5,6};
    vector<int> v2={6,5,4,3,2,1};
    f(v1,v2);
    for(auto i:v1)
    {
        cout<<i<<endl;
    }
    return 0;
}

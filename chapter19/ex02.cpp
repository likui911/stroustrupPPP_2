/*
Write a template function that takes a vector<T> vt and a vector<U> vu as arguments and returns the sum of all
vt[i]*vu[i]s.
*/
#include <vector>
#include <iostream>

using namespace std;

template<typename T,typename U>
T f(vector<T> &v1, vector<U> &v2)
{
    T t{};
    auto iter1=v1.begin();
    auto iter2=v2.cbegin();
    for(;iter1!=v1.end();++iter1,++iter2)
    {
        t+=(*iter1)*(*iter2);
    }
    return t;
}

int main()
{
    vector<double> v1={1,2,3,4,5,6};
    vector<int> v2={6,5,4,3,2,1};
    double sum=f(v1,v2);
    cout<<sum<<endl;
    return 0;
}

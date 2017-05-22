/*
 Can we declare a non-reference function argument const (e.g., void f(const int);)?
What might that mean? Why might we want to do that? Why don’t people do that often? 
Try it; write a couple of small programs to see what works.
*/

#include "../std_lib_facilities.h"

void f(const int i)
{
    cout<<i<<endl;
}

int main()
{
    f(12343);
    int a=123;
    f(a);
    const int b=123;
    f(b);
    return 1;
}
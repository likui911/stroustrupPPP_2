/*
Write a function, int strcmp(const char* s1, const char* s2), that compares C-style strings. Let it return a negative
number if s1 is lexicographically before s2, zero if s1 equals s2, and a positive number if s1 is lexicographically after s2.
Do not use any standard library functions. Do not use subscripting; use the dereference operator * instead
*/
#include <iostream>
using namespace std;

int strcmp(const char *s1, const char *s2)
{
    for (; *s1 == *s2; ++s1, ++s2)
        if (*s1 == '\0')
            return 0;//如果s1和s2相等返回0
    //判断第一个不相等的char大小
    return *((unsigned char *)s1) < *((unsigned char *)s2) ? -1 : 1;
}

int main()
{
    char a[]="Hello";
    char b[]="Helloo";
    cout<<strcmp(a,b)<<endl;
    return 0;
}
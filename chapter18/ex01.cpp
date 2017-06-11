/*
Write a function, char* strdup(const char*), that copies a C-style string into memory it allocates on the free store. Do
not use any standard library functions. Do not use subscripting; use the dereference operator * instead.
*/

#include <iostream>
using namespace std;

int strlen(const char *s)
{
    int len = 0;
    while (*s != '\0')
    {
        ++len;
        ++s;
    }
    return len;
}

char *strdup(const char *s)
{
    int len = strlen(s);
    char *str = new char[len + 1];
    for (int i = 0; i < len; ++i)
    {
        *str = *s;
        ++str;
        ++s;
    }
    *str = '\0';
    return str - len;
}

int main()
{
    const char *str = strdup("Hello World");
    cout << str << endl;
    return 0;
}
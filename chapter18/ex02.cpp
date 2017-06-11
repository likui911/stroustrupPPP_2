/*
Write a function, char* findx(const char* s, const char* x), that finds the first occurrence of the C-style string x in
s. Do not use any standard library functions. Do not use subscripting; use the dereference operator * instead.
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

char *findx(const char *s, const char *x)
{
    for (; *s != '\0'; ++s)
    {
        if (*s == *x)
        {
            const char *ss = s;
            const char *xx = x;
            int char_found = 0;
            for (; *ss != '\0' && *xx != '\0'; ++ss, ++xx)
            {
                if (*ss != *xx)
                    break;
                else
                    ++char_found;
            }
            if (char_found == strlen(x))
            {
                return const_cast<char *>(s);
            }
        }
    }
    return nullptr;
}

int main()
{
    char c_str[] = "Hello wor world!";
    char x[] = "world";

    char *p = findx(c_str, x);
    if (p)
    {
        for (int i = 0; i < strlen(x); ++i)
        {
            cout << *(p + i);
        }
    }
    else
    {
        cout << "nullptr" << endl;
    }

    return 0;
}
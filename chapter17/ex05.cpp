/*
Write a function, char* findx(const char* s, const char* x), that finds the first occurrence of the 
C-style string x in s
*/
#include <string.h>
#include <iostream>
using namespace std;

const char *findx(const char *s, const char *x)
{
    int len_s = strlen(s);
    int len_x = strlen(x);

    for (int i = 0; i <= len_s; ++i)
    {
        if (x[0] == s[i])
        {
            int char_found = 0;
            for (int j = 0; j < len_x; ++j)
            {
                if (x[j] != s[i + j])
                    break;
                else
                    ++char_found;
            }
            if (char_found == len_x)
                return &s[i];
        }
    }
    return nullptr;
}

int main()
{
    char c_str[] = "Hello world!";
    char x[] = "world";

    const char *p = findx(c_str, x);
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
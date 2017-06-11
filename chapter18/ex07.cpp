/*
Write versions of the cat_dot()s from the previous exercises to take C-style strings as arguments and return a freestore-allocated C-style string as the result. Do not use standard library functions or types in the implementation. Test
these functions with several strings. Be sure to free (using delete) all the memory you allocated from free store (using
new). Compare the effort involved in this exercise with the effort involved for exercises 5 and 6.
*/
#include <string.h>
#include <iostream>

using namespace std;

char *cat_dot(const char *s1, const char *s2)
{
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    char *str = new char[len1 + len2];
    for (; *s1 != '\0';)
    {
        *str = *s1;
        ++str;
        ++s1;
    }
    *(str++) = '.';

    for (; *s2 != '\0';)
    {
        *str = *s2;
        ++str;
        ++s2;
    }
    *str = '\0';
    char *p = str - len1 - len2 - 1;
    return p;
}

int main()
{
    char *str = cat_dot("Hello", "world");
    cout << str << endl;
    delete[] str;
    return 0;
}
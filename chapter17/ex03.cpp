/*
Write a function, void to_lower(char* s), that replaces all uppercase characters in the C-style string s with their
lowercase equivalents. For example, Hello, World! becomes hello, world!. Do not use any standard library
functions. A C-style string is a zero-terminated array of characters, so if you find a char with the value 0 you are at the
end.
*/
#include <cctype>

using namespace std;

void to_lower(char *s)
{
    if (isupper(*s))
        *s=tolower(*s);
}

int main()
{
    char *str = new char[11]{'F', 'o', 'r', 'e', 'x', 'a', 'm', 'p', 'l', 'e', '\0'};
    for (int i = 0;; ++i)
    {
        if (str[i] == '\0')
            break;
        to_lower(&str[i]);
    }
    return 0;
}
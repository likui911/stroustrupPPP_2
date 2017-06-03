/*
Write a program that reads strings and for each string outputs the character classification of 
each character, as defined by the character classification functions presented in §11.6. Note 
that a character can have several classifications (e.g.,x is both a letter and an alphanumeric)
*/
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

void analyse_char(const string &str)
{
    for (char c : str)
    {
        cout << c << " | ";
        if (iscntrl(c))
            cout << "cntrl ";
        if (isblank(c))
            cout << "blank ";
        if (isspace(c))
            cout << "space ";
        if (isupper(c))
            cout << "upper ";
        if (islower(c))
            cout << "lower ";
        if (isalpha(c))
            cout << "isalpha ";
        if (isdigit(c))
            cout << "digit ";
        if (isxdigit(c))
            cout << "xblank ";
        if (isalnum(c))
            cout << "alnum ";
        if (ispunct(c))
            cout << "pubct ";
        if (isgraph(c))
            cout << "graph ";
        if (isprint(c))
            cout << "print ";
        cout << endl;
    }
}

int main()
{
     while (true)
     {
        string str;
         cin >> str;
		 analyse_char(str);
     }
    return 0;
}
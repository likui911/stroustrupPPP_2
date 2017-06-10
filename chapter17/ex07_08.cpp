/*
Write a program that reads characters from cin into an array that you allocate on the free store. Read individual
characters until an exclamation mark (!) is entered. Do not use a std::string. Do not worry about memory exhaustion
*/
#include <iostream>
#include <string>

using namespace std;

char *ex07(istream &is)
{
    char c=' ';
    char *chs = new char[512];
    int idx = 0;
    for (; is >> c && c != '!'; ++idx)
    {
        chs[idx] = c;
    }
    chs[idx] = '\0';
    return &chs[0];
}

string ex08(istream &is)
{
    char c=' ';
    string s;
    while (is >> c && c != '!')
    {
        s.push_back(c);
    }
    return s;
}

int main()
{
    char *chs = ex07(cin);
    cin.sync();//discards all unread characters
    string s = ex08(cin);

    return 0;
}
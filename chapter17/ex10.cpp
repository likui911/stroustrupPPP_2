/*
Look at your solution of exercise 7. Is there any way that input could get the array to overflow; that is, is there any way you
could enter more characters than you allocated space for (a serious error)? Does anything reasonable happen if you try
to enter more characters than you allocated?
*/
#include <iostream>
#include <string>

using namespace std;

char *ex07(istream &is)
{
    char c = ' ';
    char *chs = new char[10];
    int idx = 0;
    for (; is >> c && c != '!'; ++idx)
    {
        chs[idx] = c;
    }
    chs[idx] = '\0';
    return &chs[0];
}
int main()
{
    //read more characters than you allocated ,undefined behaviour
    char *chs = ex07(cin);
    return 0;
}
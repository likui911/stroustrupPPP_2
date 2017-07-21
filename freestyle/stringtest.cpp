#include "string.h"
#include <iostream>
using std::cout;
using std::endl;
int main()
{
    string s1("hello");
    string s2("world");

    string s3(s2);
    cout << s3 << endl;

    s3 = s1;
    cout << s3 << endl;
    cout << s2 << endl;
    cout << s1 << endl;
    return 0;
}
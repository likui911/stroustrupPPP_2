/*
Write a function, string cat_dot(const string& s1, const string& s2), that concatenates two strings with a dot in
between. For example, cat_dot("Niels", "Bohr") will return a string containing Niels.Bohr

Modify cat_dot() from the previous exercise to take a string to be used as the separator (rather than dot) as its third
argument

*/
#include <string>
#include <iostream>

using namespace std;

string cat_dot(const string &s1, const string &s2)
{
    return s1 + "." + s2;
}

string cat_dot(const string &s1, const string &s2,const string &sep)
{
    return s1 + sep + s2;
}

int main()
{
    cout<<cat_dot("Niels","Bohr")<<endl;
    cout<<cat_dot("Niels","Bohr","-")<<endl;
    return 0;
}
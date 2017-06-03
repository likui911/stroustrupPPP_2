/*
Write a function vector<string> split(const string& s) that returns a vector of whitespace-separated substrings
from the argument s
*/
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

vector<string> split(const string &s)
{
    vector<string> vc;
    stringstream ss(s);
    for (string word; ss >> word;)
    {
        vc.push_back(word);
    }
    return vc;
}

int main()
{
    vector<string> vc = split("hello world ");
    for (string s : vc)
    {
        cout << s << " ";
    }
    cout << endl;
    return 0;
}
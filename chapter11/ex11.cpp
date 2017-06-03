/*
Write a function vector<string> split(const string& s, const string& w) that returns a vector of whitespace
separated substrings from the argument s, where whitespace is defined as “ordinary whitespace” plus the 
characters in w
*/
#include "./punc.h"
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

vector<string> split(const string &s, const string &w)
{
    // convert spliter to whitespace
    string temp = s;
    for (char &ch : temp)
        for (char x : w)
            if (ch == x)
                ch = ' ';

    stringstream ss{temp};
    string word;
    vector<string> vec;
    while (ss >> word)
        vec.push_back(word);
    return vec;
}

int main()
{
    vector<string> vc = split("hel,lo wo.rld;my "," ,.;");
    for (string s : vc)
    {
        cout << s << " ";
    }
    cout << endl;
    return 0;
}
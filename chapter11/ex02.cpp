/*
Write a program that given a file name and a word outputs each line that contains that word 
together with the line number. Hint: getline().
*/
#include "../std_lib_facilities.h"
#include <fstream>
using namespace std;

void do_something(const string &file, const string &word)
{
    ifstream ifs{file};
    if (!ifs)
        error("FileError");
    int line = 1;
    for (; ifs; ++line)
    {
        string str;
        getline(ifs, str);
        cout << word << line << "\t" << str << endl;
    }
}

int main()
{
    try
    {
        do_something("./chapter11/in_file.txt", "Line");
    }
    catch (exception &ex)
    {
        cerr << ex.what() << endl;
    }
    return 0;
}
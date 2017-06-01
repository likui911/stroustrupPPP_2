/*
Write a program that reads a text file and converts its input to all lower case, producing a new file.
*/
#include "../std_lib_facilities.h"
#include <fstream>
#include <cctype>

using namespace std;

void do_something()
{
    ifstream ifs{"./chapter11/in_file.txt"};
    ofstream ofs{"./chapter11/out_file.txt"};
    if (!ifs || !ofs)
        error("File Error");
    while (ifs)
    {
        char c;
        ifs.get(c);
        if (isalpha(c))
            c = tolower(c);
        ofs << c;
    }
}

int main()
{
    try
    {
        do_something();
    }
    catch (exception &ex)
    {
        cerr << ex.what() << endl;
    }
    return 0;
}
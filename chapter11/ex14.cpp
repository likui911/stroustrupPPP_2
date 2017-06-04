/*
Write a program that reads a text file and writes out how many characters of each character classification 
(§11.6) are in the file.
*/
#include "../std_lib_facilities.h"

void char_class(const string &file)
{
    int count_space = 0;
    int count_digit = 0;
    int count_aplpa = 0;
    int count_else = 0;

    ifstream ifs{file};
    if (!ifs)
        error("can't open ", file);

    for (char ch; ifs.get(ch);)
    {
        if (isspace(ch))
            ++count_space;
        else if (isdigit(ch))
            ++count_digit;
        else if (isalpha(ch))
            ++count_aplpa;
        else
            ++count_else;
    }

    cout << "space " << count_space << " digit " << count_digit << " aplpa "
         << count_aplpa << " else " << count_else << endl;
}

int main()
{
    try
    {
        char_class("./chapter11/belt.txt");
    }
    catch (exception &ex)
    {
        cerr << ex.what() << endl;
        keep_window_open();
    }
    return 0;
}
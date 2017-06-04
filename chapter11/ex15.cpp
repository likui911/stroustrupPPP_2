/*
Write a program that reads a file of whitespace-separated numbers and outputs a file of numbers 
using scientific format and precision 8 in four fields of 20 characters per line
*/
#include "../std_lib_facilities.h"
#include <iomanip>

using namespace std;

void format_digit(const string &infile, const string &outfile)
{
    ifstream ifs{infile};
    if (!ifs)
        error("can't open ", infile);
    ofstream ofs{outfile};
    if (!ofs)
        error("can't open ", outfile);

    string line;
    while (getline(ifs, line))
    {
        stringstream ss{line};
        for (double d; ss >> d;)
        {
           ofs << scientific << setprecision(8) << setw(20) << d;
        }
        ofs << "\n";
    }
}

int main()
{
    try
    {
        format_digit("./chapter11/in_digit.txt", "./chapter11/out_digit.txt");
    }
    catch (exception &ex)
    {
        cerr << ex.what() << endl;
        keep_window_open();
    }
    return 0;
}
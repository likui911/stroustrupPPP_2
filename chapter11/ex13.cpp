/*
Reverse the order of words (defined as whitespace-separated strings) in a file. For example, 
Norwegian Blue parrot becomes parrot Blue Norwegian. You are allowed to assume that all the 
strings from the file will fit into memory at once.
*/
#include "../std_lib_facilities.h"
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

void reverse_order(const string &file)
{
    ifstream ifs{file};
    if (!ifs)
        error("Can't open file ", file);

    string line;
    vector<string> lines;
    //获得整行 ，reverse
    while (getline(ifs, line))
    {
        stringstream ss(line);
        line = {};
        for (string word; ss >> word;)
        {
            line = word + " " + line;
        }
        line += '\n';
        lines.push_back(line);
    }
    ifs.close();

    ofstream ofs{file};
    if (!ofs)
        error("Can't open file ", file);
    for (int i = lines.size()-1; i >= 0; --i)
    {
        ofs << lines[i];
    }
    ofs.close();
}

int main()
{
    try
    {
        reverse_order("./chapter11/belt.txt");
    }
    catch (exception &ex)
    {
        cerr << ex.what() << endl;
        keep_window_open();
    }
    return 0;
}
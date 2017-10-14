
#include <regex>
#include <fstream>
#include <iostream>

using namespace std;

int main()
{
    ifstream ifs{"./chapter23/file.txt"};
    if (!ifs)
    {
        cerr << "no file\n";
    }
    //2个字母0-多空格5个数字 (-四个数字)可选
    regex pat{R"(\w{2}\s*\d{5}(-\d{4})?)"};
    int lineno = 0;
    for (string line; getline(ifs, line);)
    {
        ++lineno;
        smatch matches;
        if (regex_search(line, matches, pat))
        {
            cout << lineno << " : " << matches[0] << endl;
            if (matches[1].matched)
            {
                cout << "\t" << matches[1] << endl;
            }
        }
    }
    return 0;
}
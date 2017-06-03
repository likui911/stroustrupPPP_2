/*
Modify the program from the previous exercise so that it replaces don't with do not, 
can't with cannot, etc.; leaves hyphens within words intact (so that we get “ do not 
use the as-if rule ”); and converts all characters to lower case.
*/

#include <string>
#include <cctype>
#include <iostream>

using namespace std;

void replace_punct(string &str)
{
    // convert to lowercase
    for (char &c : str)
        c = tolower(c);

    // replace don't with do not
    size_t found_1 = str.find("don't");
    while (found_1 != string::npos)
    {
        str.replace(found_1, 5, "do not");
        found_1 = str.find("don't");
    }
    // replace can't with can not
    size_t found_2 = str.find("don't");
    while (found_2 != string::npos)
    {
        str.replace(found_2, 5, "can not");
        found_2 = str.find("can't");
    }

    for (int i = 0; i < str.size(); ++i)
    {
        if (ispunct(str[i]) && str[i] != '\"')
        {
            if (str[i] == '-' && isalpha(str[i + 1]))
                continue;
            str[i] = ' ';
        }
    }
}

int main()
{
    string s = "\"- don't use the as-if rule. \"";
    replace_punct(s);
    cout << s << endl;
    return 0;
}
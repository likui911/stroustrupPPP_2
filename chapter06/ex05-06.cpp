/*
 Add the article the to the “English” grammar in §6.4.1, 
 so that it can describe sentences such as 
 “The birds fly but the fish swim.”
 
English Grammar
sentence:
    noun verb
    sentence conj sentence
conj:
    "and"
    "or"
    "but"
noun:
    "birds"
    "fish"
    "C++"
verb:
    "rules"
    "fly"
    "swin"
*/

#include "../std_lib_facilities.h"

bool noun()
{
    string s;
    cin >> s;
    if (s == "birds" || s == "fish" || s == "C++")
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool verb()
{
    string s;
    cin >> s;
    if (s == "rules" || s == "fly" || s == "swin")
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool conj(const string &str)
{
    if (str == "and" || str == "or" || str == "but")
    {
        return true;
    }
    else
    {
        return false;
    }
}

string sentence()
{
    if (noun() && verb())
    {
        string s;
        cin >> s;
        if (s == ".")
        {
            return "OK";
        }
        else if (conj(s))
        {
            return sentence();
        }
    }
    return "not OK";
}

int main()
{
    while (cin)
    {
        cout << sentence() << endl;
    }
    return 0;
}

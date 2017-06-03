/*
Use the program from the previous exercise to make a dictionary (as an alternative to the approach in §11.7). 
Run the result on a multi-page text file, look at the result, and see if you can improve the program to make 
a better dictionary
*/
#include <string>
#include <cctype>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

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
        if (ispunct(str[i]))
        {
            if (str[i] == '-' && isalpha(str[i + 1]))
                continue;
            str[i] = ' ';
        }
    }
}

int main()
{
    ifstream ifs{"./chapter11/belt.txt"};
    string txt, temp;
    while (getline(ifs, temp))
    {
        txt += temp;
    }
    replace_punct(txt);

    stringstream ss{txt};
    vector<string> vs;
    for (string word; ss >> word;)
    {
        auto it = find(vs.begin(), vs.end(), word);
        //if word not found ,push it to vector
        if (it == vs.end())
            vs.push_back(word);
    }

    //output the dictionary
    for (auto s : vs)
        cout << s << endl;
    return 0;
}
/*
Take the word-frequency example from §21.6.1 and modify it to output its lines 
in order of frequency (rather than in lexicographical order). 
An example line would be 3: C++ rather than C++: 3.
*/
#include <map>
#include <iostream>
using namespace std;

int main()
{
    map<string, int> words; // keep (word,frequency) pairs
    /*
    C++ is a general purpose programming language designed to make programming more 
    enjoyable for the serious programmer. Except for minor details, 
    C++ is a superset of the C programming language. In addition to the facilities
    provided by C, C++ provides flexible and efficient facilities for defining new types.
    */
    for (string s; cin >> s;)
        ++words[s]; // note: words is subscripted by a string
    for (const auto &p : words)
        cout << p.second << ": " << p.first << '\n';
    return 0;
}
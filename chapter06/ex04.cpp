/*
exercise 19 in Chapter 4:
Write a program where you first enter a set of name-and-value pairs, such as Joe 17 and Barbara 22. For each pair,
add the name to a vector called names and the number to a vector called scores (in corresponding positions, so that if
names[7]=="Joe" then scores[7]==17). Terminate input with NoName 0. Check that each name is unique and terminate
with an error message if a name is entered twice. Write out all the (name,score) pairs, one per line.

Define a class Name_value that holds a string and a value. Rework exercise 19 in Chapter 4 to use a
vector<Name_value> instead of two vectors.
*/

#include "../std_lib_facilities.h"
class Name_value
{
  public:
    Name_value(string n,unsigned v):name(n),value(v){};
    string name;
    unsigned value;
};

int main()
{
    vector<Name_value> person;
    while (cin)
    {
        string name;
        unsigned value;
        cin >> name >> value;
        if (name == "NoName" && value == 0)
        {
            keep_window_open("1");
            return 1;
        }
        for(Name_value n:person)
        {
            if(n.name==name)
            {
                cerr << "a name is entered twice\n";
                keep_window_open("2");
                return 2;
            }
        }
        Name_value nv(name,value);
        person.push_back(nv);
    }
    keep_window_open("0");
    return 0;
}
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <iostream>
using namespace std;

typedef vector<string>::const_iterator Line_iter;
class Message
{ // a Message points to the first and the last lines of a message
    Line_iter first;
    Line_iter last;

  public:
    Message(Line_iter p1, Line_iter p2) : first{p1}, last{p2} {}
    Line_iter begin() const { return first; }
    Line_iter end() const { return last; }
    // . . .
};

using Mess_iter = vector<Message>::const_iterator;
struct Mail_file
{ // a Mail_file holds all the lines from a file
    // and simplifies access to messages
    string name;                // file name
    vector<string> lines;       // the lines in order
    vector<Message> m;          // Messages in order
    Mail_file(const string &n); // read file n into lines
    Mess_iter begin() const { return m.begin(); }
    Mess_iter end() const { return m.end(); }
};

// find the name of the sender in a Message;
// return true if found
// if found, place the sender’s name in s:
bool find_from_addr(const Message *m, string &s);
// return the subject of the Message, if any, otherwise "":
string find_subject(const Message *m);

/////////////////////////////////////////////////////////////////////
//             implements
////////////////////////////////////////////////////////////////////

Mail_file::Mail_file(const string &n)
{
    ifstream ifs{n};
    if (!ifs)
    {
        cerr << "no " << n << "\n";
        exit(1);
    }
    for (string s; getline(ifs, s);)
    {
        lines.push_back(s);
    }

    auto first = lines.begin();
    for (auto p = lines.begin(); p != lines.end(); ++p)
    {
        if (*p == "----")
        {
            m.push_back(Message(first, p));
            first = p + 1;
        }
    }
}

int main()
{
    Mail_file mfile{"./chapter23/mymailfile.txt"}; // initialize mfile from a file

   for(auto mess:mfile.m)
   {
       for(auto iter=mess.begin();iter!=mess.end();++iter)
       {
           cout<<*iter<<endl;
       }
       cout<<"----"<<endl;
   }
    return 0;
}
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
};

using Mess_iter = vector<Message>::const_iterator;
struct Mail_file
{ // a Mail_file holds all the lines from a file
    // and simplifies access to messages
    string name;          // file name
    vector<string> lines; // the lines in order
    vector<Message> m;    // Messages in order
    Mail_file(const string &n)
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

    Mess_iter begin() const { return m.begin(); }
    Mess_iter end() const { return m.end(); }
};

int is_prefix(const string &s, const string &p)
// is p the first part of s?
{
    int n = p.size();
    if (string(s, 0, n) == p)
        return n;
    return 0;
}

// find the name of the sender in a Message;
// return true if found
// if found, place the sender’s name in s:
bool find_from_addr(const Message *m, string &s)
{
    for (const auto &x : *m)
    {
        if (int n = is_prefix(x, "From: "))
        {
            s = string(x, n);
            return true;
        }
    }
    return false;
}
// return the subject of the Message, if any, otherwise "":
string find_subject(const Message *m)
{
    for (const auto &x : *m)
        if (int n = is_prefix(x, "Subject: "))
            return string(x, n);
    return "";
}

int main()
{
    Mail_file mfile{"./chapter23/mymailfile.txt"}; // initialize mfile from a file

    multimap<string, const Message *> sender;

    for (auto &m : mfile)
    {
        string s = find_subject(&m);
        sender.insert(make_pair(s, &m));
    }

    //pair<const_iterator,const_iterator> 表示范围
    auto pp = sender.equal_range("");
    for (auto p = pp.first; p != pp.second; ++p)
    {
        //p->first 标题
        //p->second Message*
        for (const auto &x : *(p->second))
        {
            cout << x << endl;
        }
    }
    return 0;
}
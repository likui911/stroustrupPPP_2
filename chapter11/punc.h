#include <string>
#include <sstream>
#include <iostream>
#include <cctype>

using std::istream;
using std::istringstream;
using std::string;

class Punct_stream
{
  public:
    Punct_stream(istream &is)
        : source{is}, sensetive{true} {}
    void whitespace(const string &s) { white = s; }
    void add_white(char c) { white += c; }
    bool is_whitespace(char c);
    void case_sensetive(bool b) { sensetive = b; }
    Punct_stream &operator>>(string &s);
    operator bool();

  private:
    istream &source;
    istringstream buffer;
    string white;
    bool sensetive;
};
#ifndef _MYSTRING_
#define _MYSTRING_

#include <cstring>
#include <iostream>

class string
{
  public:
    string(const char *c = 0);
    string(const string &);
    string &operator=(const string &);
    char *get_cstr() const { return c_str; }
    ~string();

  private:
    char *c_str;
};

inline string::string(const char *c)
{
    if (c)
    {
        c_str = new char[strlen(c) + 1];
        strcpy(c_str, c);
    }
    else
    {
        c_str = new char[1];
        *c_str = '\0';
    }
}

inline string::string(const string &str)
{
    c_str = new char[strlen(str.c_str) + 1];
    strcpy(c_str, str.c_str);
}

inline string::~string()
{
    delete[] c_str;
}

inline string &string::operator=(const string &str)
{
    if (this == &str)
    {
        return *this;
    }
    delete[] c_str;
    c_str = new char[strlen(str.c_str) + 1];
    strcpy(c_str,str.c_str);
    return *this;
}

std::ostream &operator<<(std::ostream &os, string &str)
{
    os << str.get_cstr();
    return os;
}

#endif
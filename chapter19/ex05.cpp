/*
Define a class Int having a single member of class int. Define constructors, assignment, and operators +, –, *, / for it.
Test it, and improve its design as needed (e.g., define operators << and >> for convenient I/O)
*/
#include <iostream>
using std::ostream;
using std::istream;

class Int
{
  public:
    Int() : value{0} {}
    Int(int i) : value{i} {}

    Int(const Int &i)
    {
        value = i.value;
    }

    Int &operator=(const Int &i)
    {
        value = i.value;
        return *this;
    }

    int getValue() { return value; }
    void setValue(int i) { value = i; }

  private:
    int value;
};
ostream &operator<<(ostream &os, Int i)
{
    os << i.Value();
    return os;
}

istream &operator>>(istream &is, Int i)
{
    int temp;
    is >> temp;
    i.setValue(temp);
    return is;
}

Int operator+(const Int &a, const Int &b)
{
    return Int(a.getValue() + b.getValue());
}
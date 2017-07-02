#include <string>
#include <iostream>
#include "../std_lib_facilities.h"
using namespace std;

struct Person
{
    Person():n{},a{}{}//default constructor
    Person(string nn, int aa) : n{nn}, a{aa} 
    {
        if(aa>=150||aa<0)error("age range error");
        if(nn.find(";:\"'[]*&^%$#@!."))error("bad input");
    }
    string name() const { return n; }
    int age() const { return a; }

  private:
    string n;
    int a;
};

istream &operator>>(istream &is, Person &p)
{
    string name;
    int age;
    is>>name>>age;
    p=Person{name,age};
    return is;
}

ostream &operator<<(ostream &os, Person &p)
{
    os << p.name() << " - " << p.age();
    return os;
}

int main()
{
    Person p1;
    cin >> p1;
    cout << "--" << endl;
    cout << p1;
    return 0;
}
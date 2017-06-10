/*
Complete the “list of gods” example from §17.10.1 and run it
*/
#include "ex11.h"
#include <string>
#include <iostream>
using std::cout;
using std::endl;

// insert n before this object,return n
Link *Link::insert(Link *n)
{
    if (n == nullptr)
        return this;
    n->succ = this;
    if (this->prev)
        this->prev->succ = n;
    n->prev = this->prev;
    this->prev = n;
    return n;
}

// insert n after this object,return n
Link *Link::add(Link *n)
{
    if (n == nullptr)
        return this;
    n->prev = this;
    if (this->succ)
        this->succ->prev = n;
    n->succ = this->succ;
    this->succ = n;
    return n;
}

// remove this object from list,return succ
Link *Link::erase()
{
    if (this->prev)
        this->prev->succ = this->succ;
    if (this->succ)
        this->succ->prev = this->prev;
    return this->succ;
}

// find s in list
Link *Link::find(const string &s)
{
    Link *p = this;
    while (p)
    {
        if (p->value == s)
            return p;
        p = p->succ;
    }
    return nullptr;
}

// find s in const list
const Link *Link::find(const string &s) const
{
    const Link *p = this;
    while (p)
    {
        if (p->value == s)
            return p;
        p = p->succ;
    }
    return nullptr;
}

// move n positions in list
Link *Link::advance(int n) const
{
    Link *p = const_cast<Link *>(this);
    if (0 < n)
    {
        while (n--)
        {
            if (p->succ == nullptr)
                return nullptr;
            p = p->succ;
        }
    }
    else if (0 > n)
    {
        while (n++)
        {
            if (p->prev == nullptr)
                return nullptr;
            p = p->prev;
        }
    }
    return p;
}

int main()
{
    Link *norse_gods = new Link{"Thor"};
    norse_gods = norse_gods->insert(new Link{"Odin"});
    norse_gods = norse_gods->insert(new Link{"Zeus"});
    norse_gods = norse_gods->insert(new Link{"Freia"});
    cout << norse_gods->value << endl;

    Link *greek_gods = new Link{"Thor"};
    greek_gods = greek_gods->add(new Link{"Odin"});
    greek_gods = greek_gods->add(new Link{"Zeus"});
    greek_gods = greek_gods->add(new Link{"Freia"});
    cout << greek_gods->value << endl;

    greek_gods = greek_gods->advance(-2);
    cout << greek_gods->value << endl;

    Link *p = norse_gods->find("Zeus");
    cout << p->value << endl;
    return 0;
}
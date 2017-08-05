/*
Modify class Link from §17.9.3 to be a template with the type of value as the template argument. Then redo exercise 13
from Chapter 17 with Link<God>
*/
template<typename T>
struct Link
{
    T value;
    Link *prev;
    Link *succ;
    Link(const T &v, Link *p = nullptr, Link *s = nullptr)
        : value{v}, prev{p}, succ{s} {}
};


/*
In the Fruit example in §21.6.5, we copy Fruits into the set. What if we didn’t want to copy the Fruits? We could have a
set<Fruit*> instead. However, to do that, we’d have to define a comparison operation for that set. Implement the Fruit
example using a set<Fruit*, Fruit_comparison>. Discuss the differences between the two implementations.
*/
#include <set>
#include <string>
#include <iostream>

using namespace std;
struct Fruit
{
    Fruit(string n, int c) : name{n}, count{c}, unit_price{} {};
    Fruit(string n, int c, double u) : name{n}, count{c}, unit_price{u} {};

    string name;
    int count;
    double unit_price;
};
ostream &operator<<(ostream &os, const Fruit &fr)
{
    os << fr.name << " - " << fr.count << " - " << fr.unit_price;
    return os;
}

struct Fruit_order
{
    bool operator()(const Fruit &a, const Fruit &b) const
    {
        return a.name < b.name;
    }
    
    bool operator()(Fruit *a, Fruit *b) const
    {
        return a->name < b->name;
    }
};

int main()
{
    set<Fruit, Fruit_order> inventory1;
    inventory1.insert(Fruit("quince", 5));
    inventory1.insert(Fruit("apple", 200, 0.37));
    for (auto p = inventory1.begin(); p != inventory1.end(); ++p)
        cout << *p << '\n';
    set<Fruit *, Fruit_order> inventory2;
    Fruit quince("quince", 5);
    Fruit apple("apple", 200, 0.37);

    Fruit *q = &quince;
    Fruit *a = &apple;
    inventory2.insert(q);
    inventory2.insert(a);
    for (auto p = inventory2.begin(); p != inventory2.end(); ++p)
        cout << **p << '\n';

    return 0;
}
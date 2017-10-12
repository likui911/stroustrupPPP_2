#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iostream>
using namespace std;

struct Item
{
    string name;
    int iid;
    double value;
    /* 
    . . . 
    */
};
int main()
{
    /*
    Define a struct Item { string name; int iid; double value; };, 
    make a vector<Item>, vi, and fill it with ten items from a file
    */
    vector<Item> vi;
    ifstream ifs("./chapter21/drill.txt");
    string name;
    int id;
    double value;
    while (ifs >> name >> id >> value)
    {
        vi.push_back(Item{name, id, value});
    }

    /*
    Sort vi by name.
    */
    sort(vi.begin(), vi.end(), [](Item a, Item b) { return a.name < b.name; });

    /*
    Sort vi by iid.
    */
    sort(vi.begin(), vi.end(), [](Item a, Item b) { return a.iid < b.iid; });

    /*
    . Sort vi by value; print it in order of decreasing value (i.e., largest value first)
    */
    sort(vi.begin(), vi.end(), [](Item a, Item b) { return a.value > b.value; });
    // for(auto it:vi)
    // {
    //     cout<<it.name<<" "<<it.iid<<" "<<it.value<<endl;
    // }

    /*
    Insert Item("horse shoe",99,12.34) and Item("Canon S400", 9988,499.95).
    */
    vi.push_back(Item{"horse shoe", 99, 12.34});
    vi.push_back(Item{"Canon S400", 9988, 499.95});

    /*
    Remove (erase) two Items identified by name from vi
    */
    vi.erase(find_if(vi.begin(), vi.end(), [](Item it) { return it.name == "horse shoe"; }));
    /*
    Remove (erase) two Items identified by iid from vi
    */
    vi.erase(find_if(vi.begin(), vi.end(), [](Item it) { return it.iid == 9988; }));
    return 0;
}
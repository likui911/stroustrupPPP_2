/*
Improve print_until_s() from §8.5.2. Test it. What makes a good set of test cases? 
Give reasons. Then, write a print_until_ss() that prints until it sees a second occurrence 
of its quit argument.
*/
#include "../std_lib_facilities.h"

void print_until_s(vector<string> v, string quit)
{
    for (auto s : v)
    {
        if (s == quit)
            return;
        cout << s << '\n';
    }
}
void print_until_ss(vector<string> v, string quit)
{
    int occured = 0;
    for (auto s : v)
    {
        if (occured == 2)
            return;
        if (s == quit)
            occured++;
        cout << s << '\n';
    }
}

int main()
{
    vector<string> v1;
    vector<string> v2{"_", "af", "_"};
    vector<string> v3{"af", "__", "_f"};
    vector<string> v4{"ffjk"};

    print_until_s(v1, "_");
    print_until_s(v2, "_");
    print_until_s(v3, "_");
    print_until_s(v4, "_");
    return 1;
}
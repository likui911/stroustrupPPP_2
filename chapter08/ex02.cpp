/*
Write a function print() that prints a vector of ints to cout. Give it two arguments: 
a string for “labeling” the output and a vector
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void print(const string &label, vector<int> vec)
{
    for (int i : vec)
    {
        cout << label << i << endl;
    }
}

int main()
{
    vector<int> vec{1,2,3,5,7,9,0};
    print(">",vec);
    return 0;
}
/*
Read five names into a vector<string> name, then prompt the user for the ages 
of the people named and store the ages in a vector<double> age. Then print out
the five (name[i],age[i]) pairs. Sort the names (sort(name.begin(),name.end())) 
and print out the (name[i],age[i]) pairs. The tricky part here is to get the age 
vector in the correct order to match the sorted name vector. Hint: Before sorting 
name, take a copy and use that to make a copy of age in the right order after sorting 
name. Then, do that exercise again but allowing an arbitrary number of names.
*/

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void sort(vector<string> &names, vector<double> &ages)
{
    for (int i = 0; i < names.size(); ++i)
    {
        for (int j = i; j < names.size(); ++j)
        {
            if (names[i] > names[j])
            {
                string temp = names[i];
                names[i] = names[j];
                names[j] = temp;
                double temp_age = ages[i];
                ages[i] = ages[j];
                ages[j] = temp_age;
            }
        }
    }
}

int main()
{
    vector<string> names{"e", "d", "c", "b", "a"};
    vector<double> ages;
    for (int i = 0; i < names.size(); ++i)
    {
        double d;
        cin >> d;
        ages.push_back(d);
    }
    // sort names and ages
    sort(names, ages);

    // print elements
    for (int i = 0; i < names.size(); ++i)
    {
        cout << "(" << names[i] << "," << ages[i] << ")" << endl;
    }
    return 0;
}
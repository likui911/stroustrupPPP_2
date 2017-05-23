/*
Design and implement a Name_pairs class holding (name,age) pairs where name is a string and age is a double.
Represent that as a vector<string> (called name) and a vector<double> (called age) member. Provide an input
operation read_names() that reads a series of names. Provide a read_ages() operation that prompts the user for an age
for each name. Provide a print() operation that prints out the (name[i],age[i]) pairs (one per line) in the order
determined by the name vector. Provide a sort() operation that sorts the name vector in alphabetical order and
reorganizes the age vector to match. Implement all “operations” as member functions. Test the class (of course: test early
and often).
*/
#include <string>
#include <vector>
#include <iostream>

class Name_pairs
{
  public:
    Name_pairs() : names{}, ages{} {};
    // reads a series names
    void read_names(const std::vector<std::string> v_names);
    //reads ages for an age for each name
    void read_ages();
    //print out (names[i],ages[i])pairs one per line
    void print();
    //sorts the name vector in alphabetical order
    void sort();

  private:
    std::vector<std::string> names;
    std::vector<double> ages;
};

void Name_pairs::read_names(const std::vector<std::string> v_names)
{
    names.insert(names.end(), v_names.begin(), v_names.end());
}

void Name_pairs::read_ages()
{
    for (std::string name : names)
    {
        double age;
        std::cin >> age;
        ages.push_back(age);
    }
}

void Name_pairs::print()
{
    for (int i = 0; i < names.size(); ++i)
    {
        std::cout << "(" << names[i] << "," << ages[i] << ")" << std::endl;
    }
}

void Name_pairs::sort()
{
    for (int i = 0; i < names.size(); ++i)
    {
        for (int j = i; j < names.size(); ++j)
        {
            if (names[i] > names[j])
            {
                std::string temp = names[i];
                names[i] = names[j];
                names[j] = temp;
                double d = ages[i];
                ages[i] = ages[j];
                ages[j] = d;
            }
        }
    }
}

int main()
{
    using namespace std;
    vector<string> names{"f", "a", "g", "h"};
    Name_pairs pairs{};
    pairs.read_names(names);
    pairs.read_ages();
    pairs.sort();
    pairs.print();
    return 0;
}
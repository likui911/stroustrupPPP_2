/*
Replace Name_pair::print() with a (global) operator << and define == and != for Name_pairs.
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
    //sorts the name vector in alphabetical order
    void sort();
    std::vector<std::string> get_names() const { return names; }
    std::vector<double> get_ages() const { return ages; }

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

std::ostream &operator<<(std::ostream &os, Name_pairs &pairs)
{
    for (int i = 0; i < pairs.get_names().size(); ++i)
    {
        os << "(" << pairs.get_names()[i] << "," << pairs.get_ages()[i] << ")" << std::endl;
    }
    return os;
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
    cout << pairs;
    return 0;
}
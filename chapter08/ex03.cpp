/*
Create a vector of Fibonacci numbers and print them using the function from exercise 2. 
To create the vector, write a function, fibonacci(x,y,v,n), where integers x and y are ints, 
v is an empty vector<int>, and n is the number of elements to put into v; v[0] will be x and 
v[1] will be y. A Fibonacci number is one that is part of a sequence where each
element is the sum of the two previous ones. For example, starting with 1 and 2, 
we get 1, 2, 3, 5, 8, 13, 21, . . . . Your fibonacci() function should make such a sequence 
starting with its x and y arguments.
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void fibonacci(int x, int y, vector<int> &vec, int n)
{
    if (vec.size() == n)
        return;
    vec.push_back(x);
    int next_y = x + y;
    fibonacci(y, next_y, vec, n);
}

void print(const string &label, vector<int> vec)
{
    for (int i : vec)
    {
        cout << label << i << endl;
    }
}

int main()
{
    vector<int> vec;
    fibonacci(1, 2, vec, 10);
    print("-", vec);
    return 0;
}
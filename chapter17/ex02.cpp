/*
How many bytes are there in an int? In a double? In a bool? Do not use sizeof except to verify your answer
*/
#include <iostream>

using namespace std;

int main()
{
    cout << "int " << sizeof(int) << '\n'
         << "double " << sizeof(double) << '\n'
         << "bool " << sizeof(bool) << '\n';
    return 0;
}
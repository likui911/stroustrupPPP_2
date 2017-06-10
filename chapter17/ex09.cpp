/*
Which way does the stack grow: up (toward higher addresses) or down (toward lower addresses)? Which way does the
free store initially grow (that is, before you use delete)? Write a program to determine the answers.
*/
#include <iostream>
using namespace std;

int main()
{
    int a1 = 10;
    int a2 = 10;
    int a3 = 10;
    int a4 = 10;
    //stack decrease
    cout<<&a1<<" "<<&a2<<" "<<&a3<<" "<<&a4<<" "<<endl;
    int* ints=new int[10];
    //stack increase
    cout<<&ints[0]<<" "<<&ints[1]<<" "<<&ints[2]<<" "<<&ints[3]<<" "<<endl;
    return 0;
}
/*
Reverse the order of characters in a text file. For example, asdfghjkl becomes lkjhgfdsa. 
Warning: There is no really good, portable, and efficient way of reading a file backward.
*/
#include "../std_lib_facilities.h"
#include <fstream>
#include <iostream>
using namespace std;

void reverse_characters(const string &file)
{
    fstream fs{file};
    if (!fs)
        error("File Open Error", file);

    //get length of file
    fs.seekg(0, fs.end);
    int length = fs.tellg();
    fs.seekg(0, fs.beg);

    //read data as a block
    char *buffer = new char[length];
    fs.read(buffer, length);

    //reverse data
    for (int i = 0; i < length / 2; ++i)
    {
        char temp = buffer[i];
        buffer[i] = buffer[length - i - 1];
        buffer[length - i - 1] = temp;
    }
    if (!fs.good()) //check fstream state
        fs.clear();

    //write data
    fs.seekp(0, fs.beg);
    fs.write(buffer, length);

    delete[] buffer;
}

int main()
{
    try
    {
        reverse_characters("./chapter11/belt.txt");
    }
    catch (exception &ex)
    {
        cerr << ex.what() << endl;
        keep_window_open();
    }
    return 0;
}
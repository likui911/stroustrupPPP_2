/*
Write a program that creates a file of data in the form of the temperature Reading type 
defined in §10.5. For testing, fill the file with at least 50 “temperature readings.” 
Call this program store_temps.cpp and the file it creates raw_temps.txt.
*/
#include "./reading.h"
#include "../std_lib_facilities.h"
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

void store_temps(ofstream &ofs, vector<Reading> &rs)
{
    if (!ofs)
        error("File Error");
    for (auto r : rs)
    {
        ofs << r.hour << " " << r.temperature << "\n";
    }
}

int main()
{
    try
    {
        ofstream ofs{"./chapter10/raw_temps.txt"};
        vector<Reading> rs{{0, 60.7}, {1, 60.6}, {3, 60.5}, {4, 60.4}, {7, 60}, {8, 59}, {9, 54}
                        , {10, 52}, {11, 51}, {12, 40}, {13, 54}, {14, 46}, {15, 47}, {16, 69}
                        , {17, 68}, {18, 64.5}};
        store_temps(ofs, rs);
    }
    catch (exception &ex)
    {
        cerr << ex.what() << endl;
        keep_window_open();
    }
    return 0;
}
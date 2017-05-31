/*
Write a program that reads the data from raw_temps.txt created in exercise 2 into a vector and 
then calculates the mean and median temperatures in your data set. Call this program temp_stats.cpp.
*/
#include "./reading.h"
#include "../std_lib_facilities.h"
#include <fstream>

using namespace std;

vector<Reading> read_temps(ifstream &ifs)
{
    if (!ifs)
        error("File Error");
    vector<Reading> vec_r{};
    while (ifs)
    {
        Reading r;
        ifs >> r.hour >> r.temperature;
        vec_r.push_back(r);
    }
    return vec_r;
}

void median_mean_temps(vector<Reading> vcr)
{
    double mean = 0.0;
    for (auto r : vcr)
    {
        mean += r.temperature;
    }
    mean /= vcr.size();

    for (int i = 0; i < vcr.size(); ++i)
    {
        for (int j = i; j < vcr.size(); ++j)
        {
            if (vcr[i].temperature > vcr[j].temperature)
            {
                Reading temp = vcr[i];
                vcr[i] = vcr[j];
                vcr[j] = temp;
            }
        }
    }
    cout << "mean: " << mean << " median: " << vcr[vcr.size()/2].temperature << endl;
}

int main()
{
    try
    {
        ifstream ifs{"./chapter10/raw_temps.txt"};
        vector<Reading> v_r = read_temps(ifs);
        median_mean_temps(v_r);
    }
    catch (exception &ex)
    {
        cerr << ex.what() << endl;
        keep_window_open();
    }
    return 0;
}
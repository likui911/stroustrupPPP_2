/*
Write a function that finds the smallest and the largest element of a vector argument 
and also computes the mean and the median. Do not use global variables. Either return 
a struct containing the results or pass them back through reference arguments. Which 
of the two ways of returning several result values do you prefer and why?
*/
#include "../std_lib_facilities.h"
#include <limits>

struct Vector_element
{
    int largest;
    int smallest;
    int mean;
    int median;
};

// prefer this way
Vector_element pass_back_struct(vector<int> vec)
{
    Vector_element v_e;
    int counter = 0;
    //sort vector and counter
    for (int i = 0; i < vec.size(); ++i)
    {
        counter += vec[i];
        for (int j = i; j < vec.size(); ++j)
        {
            if (vec[i] > vec[j])
            {
                int temp = vec[i];
                vec[i] = vec[j];
                vec[j] = temp;
            }
        }
    }
    v_e.largest = vec[0];
    v_e.smallest = vec[vec.size() - 1];
    v_e.median = vec[vec.size() / 2];
    v_e.mean = counter / 2;
    return v_e;
}

void pass_back_ref(vector<int> vec, int &largest, int &smallest, int &mean, int &median)
{
    int counter = 0;
    //sort vector and counter
    for (int i = 0; i < vec.size(); ++i)
    {
        counter += vec[i];
        for (int j = i; j < vec.size(); ++j)
        {
            if (vec[i] > vec[j])
            {
                int temp = vec[i];
                vec[i] = vec[j];
                vec[j] = temp;
            }
        }
    }
    largest = vec[0];
    smallest = vec[vec.size() - 1];
    median = vec[vec.size() / 2];
    mean = counter / 2;
}
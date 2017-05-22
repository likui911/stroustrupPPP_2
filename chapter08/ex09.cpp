/*
Write a function that given two vector<double>s price and weight computes a value 
(an “index”) that is the sum of all price[i]*weight[i]. Make sure to have 
weight.size()==price.size()
*/
#include "../std_lib_facilities.h"

double sum(const vector<double> &price, const vector<double> &weight)
{
    double sum = 0.0;
    if (price.size() != weight.size())
        error("please make sure that weight.size() equal to price.size()");
    for (int i = 0; i < price.size(); ++i)
    {
        sum += price[i] * weight[i];
    }
    return sum;
}
int main()
{
    vector<double> price{1.0, 2.0, 3.0, 4.0, 5.0};
    vector<double> weight{5.0, 4.0, 3.0, 2.0, 1.0};
    try
    {
        cout << sum(price, weight);
    }
    catch (exception &e)
    {
        cerr << e.what() << endl;
    }
    return 0;
}
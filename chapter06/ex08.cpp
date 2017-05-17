/*
    Redo the “Bulls and Cows” game from exercise 12 in Chapter 5 to use four 
    letters rather than four digits
*/

#include "../std_lib_facilities.h"

using namespace std;

bool bull_cow(vector<char> &vec_i, vector<char> &vec_guess)
{
    int bull = 0;
    int cow = 0;
    for (size_t i = 0; i < vec_i.size(); ++i)
    {
        for (size_t j = 0; j < vec_guess.size(); ++j)
        {
            if (vec_guess[j] == vec_i[i])
            {
                if (i == j)
                    ++bull;
                else
                    ++cow;
            }
        }
    }
    if (bull == 4)
    {
        cout << "congratulations,you are right" << endl;
        return true;
    }
    else
    {
        cout << bull << " bull and " << cow << " cow" << endl;
        return false;
    }
}

int main()
{
    vector<char> vec_i{'A', 'B', 'C', 'D'};
    vector<char> vec_guess(4);
    while (cin)
    {
        for (auto &c : vec_guess)
        {
            cin >> c;
        }
        if (bull_cow(vec_i, vec_guess))
            break;
    }

    keep_window_open("1");
    return 0;
}
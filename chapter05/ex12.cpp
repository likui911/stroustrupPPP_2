/*
Implement a little guessing game called (for some obscure reason) “Bulls and Cows.” 
The program has a vector of four different integers in the range 0 to 9 (e.g., 1234 but not 1122) 
and it is the user’s task to discover those numbers by repeated guesses. Say the 
number to be guessed is 1234 and the user guesses 1359; the response should be “1 bull
and 1 cow” because the user got one digit (1) right and in the right position (a bull) 
and one digit (3) right but in the wrong position (a cow). The guessing continues until 
the user gets four bulls, that is, has the four digits correct and in the correct order
*/

#include "../std_lib_facilities.h"

using namespace std;

int main()
{
    vector<char> vec_i{'1', '2', '3', '4'};
    vector<char> vec_guess(4);

    while (cin)
    {
        int bull = 0;
        int cow = 0;
        // guesting
        for (auto &c : vec_guess)
        {
            cin >> c;
        }
        for (size_t i = 0; i < vec_i.size(); ++i)
        {
            for (size_t j = 0; j < vec_guess.size(); ++j)
            {
                if (vec_guess[j] == vec_i[i])
                {
                    if (i == j)
                    {
                        ++bull;
                    }
                    else
                    {
                        ++cow;
                    }
                }
            }
        }
        if (bull == 4)
        {
            cout << "congratulations,you are right" << endl;
            break;
        }
        else
            cout << bull << " bull and " << cow << " cow" << endl;
    }
    keep_window_open("1");
    return 0;
}
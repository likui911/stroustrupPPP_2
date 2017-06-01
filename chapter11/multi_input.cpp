/*
Write a program called multi_input.cpp that prompts the user to enter several integers 
in any combination of octal, decimal, or hexadecimal, using the 0 and 0x base suffixes; 
interprets the numbers correctly; and converts them to decimal form. Then your program 
should output the values in properly spaced columns like this:

0x43  hexadecimal converts to 67 decimal
0123  octal converts to 83 decimal
65    decimal converts to 65 decimal
*/
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void do_something()
{
    while (true)
    {
        int a;
        string num;
        cin >> num;
        //put all characters back to istream
        for (int i = num.size() - 1; i >= 0; --i)
            cin.putback(num[i]);

        cin.unsetf(ios::dec); //don't assume decimal
        if (num[0] != '0' || num.size() <= 2)
        {
            cin >> a;
            cout << num << " decimal converts to " << a << " decimal" << endl;
        }
        else if (num[0] == '0' && num[1] == 'x')
        {
            cin >> a;
            cout << num << " hexadecimal converts to " << a << " decimal" << endl;
        }
        else
        {
            cin >> a;
            cout << num << " octal converts to " << a << " decimal" << endl;
        }
    }
}

int main()
{
    cout << "please input num one by one:" << endl;
    do_something();
    return 0;
}
/*
Write a program that reads digits and composes them into integers. For example, 
123 is read as the characters 1, 2,and 3. The program should output 123 is 1 hundred 
and 2 tens and 3 ones. The number should be output as an int value. Handle numbers 
with one, two, three, or four digits. Hint: To get the integer value 5 from the 
character '5' subtract '0', that is, '5'–'0'==5.
*/

#include "../std_lib_facilities.h"

int char_to_int(char c)
{
    if (!(c >= '0' && c <= '9'))
    {
        error("please input digits");
    }
    return c - '0';
}

int digit_to_dec(int *num, int bit)
{
    int result = 0;
    for (int i = 0; i < bit; ++i)
    {
        result = result * 10 + num[i];
    }
    return result;
}

void do_main_operator()
{
    cout << ">";
    char c;
    int num[] = {0, 0, 0, 0};
    int bit = 0;
    while (cin.get(c) && c != '\n')
    {
        if (bit >= 4)
        {
            error("too many input");
        }
        num[bit] = char_to_int(c);
        ++bit;
    }
    cout << "=" << digit_to_dec(num, bit) << endl;
}

int main()
{
    try
    {
        while (cin)
        {
            do_main_operator();
        }
    }
    catch (exception &e)
    {
        cerr << e.what() << endl;
        keep_window_open("~");
    }

    return 0;
}
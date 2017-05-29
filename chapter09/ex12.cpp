#include "./ex12.h"

constexpr int leap_month_days[]{31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
constexpr int month_days[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int Date::year() const
{
    long int d = 0;
    int y = 1970;
    while (true)
    {
        d += leapyear(y) ? 366 : 365;
        if (d <= m_days)
            ++y;
        else
            break;
    }
    return y;
}

Month Date::month() const
{
    long int d = 0;
    int y = year();
    for (int i = 1970; i < y; ++i)
    {
        d += leapyear(y) ? 366 : 365;
    }
    d = m_days - d;
    long int dd = 0;
    Month m;
    for (int i = 0; i < 12; ++i)
    {
        dd += leapyear(y) ? leap_month_days[i] : month_days[i];
        if (dd > d)
        {
            m = Month(i + 1);
            break;
        }
    }
    return m;
}

int Date::day() const
{
    int y = year();
    Month m = month();
    long int d = 0;
    for (int i = 1970; i < y; ++i)
    {
        d += leapyear(i) ? 366 : 365;
    }
    y = year();
    for (int i = 0; i < (int)m - 1; ++i)
    {
        d += leapyear(y) ? leap_month_days[i] : month_days[i];
    }
    return m_days - d + 1;
}

void Date::add_day(int d)
{
    m_days += d;
}

void Date::add_month(int m)
{
    int the_day = day();
    int yy = m / 12;
    int mm = m % 12;
    add_year(yy);

    long int dd = 0;
    Month the_month = month();
    for (int i = 0, y = (int)the_month; i < mm; ++i, ++y)
    {
        int idx = (y > 12 ? y -= 12 : y) - 1;
        dd += leapyear(year()) ? leap_month_days[idx] : month_days[idx];
    }
    the_month = month();
    int month_day = leapyear(year()) ? leap_month_days[(int)the_month - 1] : month_days[(int)the_month - 1];
    if (the_day > month_day)
        dd -= (the_day - month_day);
    m_days += dd;
}

void Date::add_year(int y)
{
    int the_day = day();
    int yy = year();
    long int dd = 0;
    for (int i = 0; i < y; ++i)
    {
        dd += leapyear(yy + i+1) ? 366 : 365;
    }
    Month the_month = month();
    int month_day = leapyear(yy + y) ? leap_month_days[(int)the_month - 1] : month_days[(int)the_month - 1];
    if (the_day > month_day)
        dd -= (the_day - month_day);
    m_days += dd;
}

// https://en.wikipedia.org/wiki/Leap_year#Algorithm
bool leapyear(int y)
{
    if (y % 4 != 0)
        return false;
    else if (y % 100 != 0)
        return true;
    else if (y % 400 != 0)
        return false;
    return true;
}

int main()
{
    // too many bugs,shit
    using namespace std;
    Date date{3700}; // Friday, 28 February 1980
    cout << date.year() << "-" << (int)date.month() << "-" << date.day() << endl;
     date.add_year(2);
     cout << date.year() << "-" << (int)date.month() << "-" << date.day() << endl;
    // date.add_month(12);
    // cout << date.year() << "-" << (int)date.month() << "-" << date.day() << endl;
    return 0;
}
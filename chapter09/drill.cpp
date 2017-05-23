#include "./drill.h"
#include "../std_lib_facilities.h"
namespace Chrono
{
Date::Date(int yy, Month mm, int dd) : m_year(yy), m_month(mm), m_day(dd)
{
    if (!is_date(yy, mm, dd))
        throw InvalidDate{};
}

const Date &default_date()
{
    static const Date d{2001, Month::jan, 1};
    return d;
}

Date::Date() : m_year(default_date().year()),
               m_month(default_date().month()),
               m_day(default_date().day()) {}

void Date::add_day(int dd)
{
    if (dd > 0)
    {
        for (; dd > 0; --dd)
        {
            int temp_d = m_day + 1;
            switch (month())
            {
            case Month::feb:
                if ((leapyear(m_year) && temp_d > 29) || (!leapyear(m_year) && temp_d > 28))
                {
                    temp_d = 1;
                    m_month = Month::mar;
                }
                break;
            case Month::apr:
            case Month::jun:
            case Month::sep:
            case Month::nov:
                if (temp_d > 30)
                {
                    temp_d = 1;
                    m_month = Month((int)m_month + 1);
                }
                break;
            case Month::dec:
                if (temp_d > 31)
                {
                    temp_d = 1;
                    m_month = Month::jan;
                    m_year += 1;
                }
                break;
            default:
                if (temp_d > 31)
                {
                    temp_d = 1;
                    m_month = Month((int)m_month + 1);
                }
                break;
            }
            m_day = temp_d;
        }
    }
    else if (dd < 0)
    {
        for (; dd < 0; ++dd)
        {
            int temp_d = day() - 1;
            if (temp_d <= 0)
            {
                switch (month())
                {
                case Month::jan:
                    m_month = Month::dec;
                    temp_d = 31;
                    m_year -= 1;
                    break;
                case Month::mar:
                    m_month = Month::feb;
                    if (leapyear(m_year))
                        temp_d = 29;
                    else
                        temp_d = 28;
                    break;
                case Month::feb:
                case Month::apr:
                case Month::jun:
                case Month::oct:
                case Month::sep:
                case Month::nov:
                    temp_d = 31;
                    m_month = Month((int)m_month - 1);
                    break;
                default:
                    temp_d = 30;
                    m_month = Month((int)m_month - 1);
                    break;
                }
            }
            m_day = temp_d;
        }
    }
}

void Date::add_month(int month)
{
    int temp_y = month / 12 + m_year;
    int temp_m = month % 12 + (int)m_day;

    if (temp_y <= 0)
    {
        temp_y--;
        temp_m = temp_m + 12;
    }
    else if (temp_m > 12)
    {
        temp_y++;
        temp_m = temp_m - 12;
    }
    m_year = temp_y;
    m_month = Month(temp_m);
    switch (m_month)
    {
    case Month::feb:
        if (leapyear(m_year) && m_day > 29)
            m_day = 29;
        else if (!leapyear(m_year) && m_day > 28)
            m_day = 28;
        break;
    case Month::apr:
    case Month::jun:
    case Month::sep:
    case Month::nov:
        if (m_day > 30)
            m_day = 30;
    default:
        break;
    }
}

void Date::add_year(int n)
{
    if (month() == Month::feb && day() == 29 && !leapyear(m_year + n))
        m_day = 28;
    m_year += n;
}

bool is_date(int y, Month m, int d)
{
    if (d <= 0)
        return false;
    if (m < Month::jan || m > Month::dec)
        return false;
    int days_in_month;
    switch (m)
    {
    case Month::feb:
        days_in_month = leapyear(y) ? 29 : 28;
        break;
    case Month::apr:
    case Month::jun:
    case Month::sep:
    case Month::nov:
        days_in_month = 30;
        break;
    default:
        days_in_month = 31;
        break;
    }
    if (days_in_month < d)
        return false;
    return true;
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
bool operator==(const Date &a, const Date &b)
{
    return a.year() == b.year() && a.month() == b.month() && a.day() == b.day();
}

bool operator!=(const Date &a, const Date &b)
{
    return !(a == b);
}

ostream &operator<<(ostream &os, const Date &d)
{
    return os << '(' << d.year()
              << ',' << (int)d.month()
              << ',' << d.day() << ')';
}

ostream &operator<<(ostream &os, const Day &d)
{
    vector<string> weekdays{"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    os << weekdays[(int)d];
    return os;
}

// format (2017,5,23)
istream &operator>>(istream &is, Date &d)
{
    int yy, mm, dd;
    char ch1, ch2, ch3, ch4;
    is >> ch1 >> yy >> ch2 >> mm >> ch3 >> dd >> ch4;
    if (!is)
        return is;
    if (ch1 != '(' || ch2 != ',' || ch3 != ',' || ch4 != ')')
        is.clear(ios_base::failbit);
    d = Date{yy, Month(mm), dd};
    return is;
}

// https://cs.uwaterloo.ca/~alopez-o/math-faq/node73.html
Day day_of_week(const Date &date)
{
    int y = date.year();
    int m = (int)date.month();
    int d = date.day();
    y -= m < 3;
    int day_of_week = (y + y / 4 - y / 100 + y / 400 + "-bed=pen+mad."[m] + d) % 7;
    return Day(day_of_week);
}
Date next_Sunday(const Date &d)
{
    Date d1 = d;
    while (day_of_week(d1) != Day::sun)
    {
        d1.add_day(1);
    }
    return d1;
}

Date next_weekday(const Date &d)
{
    Date d1 = d;
    if (day_of_week(d1) == Day::sat)
        d1.add_day(2);
    else if (day_of_week(d1) == Day::fri)
        d1.add_day(3);
    else
        d1.add_day(1);
    return d1;
}
}

int main()
{
    using namespace Chrono;
    try
    {
        Date d{2017, Month::may, 1};
        d.add_day(26);
        cout << d << endl;
        cout << day_of_week(d) << endl;
        Date d1 = next_Sunday(d);
        cout << d1 << " " << day_of_week(d1) << endl;
        Date d2 = next_weekday(d);
        cout << d2 << " " << day_of_week(d2) << endl;
        Date d3 = next_weekday(d2);
        cout << d3 << " " << day_of_week(d3) << endl;
    }
    catch (InvalidDate &e)
    {
        cerr << e.what() << endl;
        keep_window_open();
    }
    return 0;
}

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

enum class Day
{
    sun, //sunday
    mon, //monday
    tue, //tuesday
    wed, //wednesday
    thu, // thursday
    fri, //friday
    sat  //saturday
};

Day day_of_week(const Date &d)
{
    // 这一天是周几
}
Date next_Sunday(const Date &d)
{
    // 下一个周日
}

Date next_weekday(const Date &d)
{
    //下一个工作日
}
}

int main()
{
    using namespace Chrono;
    try
    {
        Date d{2007, Month::mar, 1};
        d.add_day(-3000);
        std::cout << d.year() << " | " << (int)d.month() << " | " << d.day() << std::endl;
    }
    catch (InvalidDate &e)
    {
        cerr << e.what() << endl;
        keep_window_open();
    }
    return 0;
}
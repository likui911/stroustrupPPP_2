#include <iostream>

using std::istream;
using std::ostream;

namespace Chrono
{
enum class Month
{
  jan = 1, //January
  feb,     //February
  mar,     //March
  apr,     //April
  may,     //May
  jun,     //June
  jul,     //July
  aug,     //August
  sep,     //September
  oct,     //October
  nov,     //November
  dec      //December
};
class InvalidDate
{
public:
  std::string what() { return "InValid Date Occured"; };
};
class Date
{
public:
  Date();
  Date(int yy, Month mm, int dd);
  int day() const { return m_day; }
  int year() const { return m_year; }
  Month month() const { return m_month; }

  void add_day(int dd);
  void add_month(int mm);
  void add_year(int yy);

private:
  int m_year;
  Month m_month;
  int m_day;
};
bool is_date(int y, Month m, int d);
bool leapyear(int y);
bool operator==(const Date &a, const Date &b);
bool operator!=(const Date &a, const Date &b);
ostream &operator<<(ostream &os, const Date &d);
istream &operator>>(istream &is, Date &dd);
}
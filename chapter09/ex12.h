/*
Change the representation of a Date to be the number of days since January 1, 1970 (known as day 0), 
represented as a long int, and re-implement the functions from §9.8. Be sure to reject dates outside 
the range we can represent that way (feel free to reject days before day 0, i.e., no negative days).
*/
#include <iostream>

enum class Month
{
  jan = 1,
  feb,
  mar,
  apr,
  may,
  jun,
  jul,
  aug,
  sep,
  oct,
  nov,
  dec
};

class Date
{
public:
  Date() : m_days{0} {};
  Date(long int dd) : m_days{dd} {};

  int day() const;
  Month month() const;
  int year() const;
  void add_day(int d);
  void add_month(int m);
  void add_year(int y);

private:
  long int m_days;//January 1, 1970
};

bool is_date(int y, Month m, int d); // true for valid date
bool leapyear(int y);                // true if y is a leap year
bool operator==(const Date &a, const Date &b);
bool operator!=(const Date &a, const Date &b);
std::ostream &operator<<(std::ostream &os, const Date &d);
std::istream &operator>>(std::istream &is, Date &dd);

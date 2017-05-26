/*
This exercise and the next few require you to design and implement a Book class, such as you can imagine as part of
software for a library. Class Book should have members for the ISBN, title, author, and copyright date. Also store data on
whether or not the book is checked out. Create functions for returning those data values. Create functions for checking a
book in and out. Do simple validation of data entered into a Book; for example, accept ISBNs only of the form n-n-n-x
where n is an integer and x is a digit or a letter. Store an ISBN as a string.
*/
#include <string>
#include <vector>
#include <iostream>
#include "drill.h"

class Invalid
{
public:
  std::string what() { return "InValid Occured"; };
};

enum class Genre
{
  fiction,
  nonfiction,
  periodical,
  biography,
  children
};

class Book
{
public:
  Book(std::string isbn, std::string title, std::string author, std::string date, bool checked, Genre genre);
  std::string get_isbn() const { return m_isbn; }
  std::string get_title() const { return m_title; }
  std::string get_author() const { return m_author; }
  std::string get_date() const { return m_date; }
  Genre get_genre() const { return m_genre; }
  bool is_checked() const { return m_checked; }
  void check_book(bool is_checked){ m_checked = is_checked; }

private:
  std::string m_isbn;
  std::string m_title;
  std::string m_author;
  std::string m_date;
  bool m_checked;
  Genre m_genre;
};

class Patron
{
public:
  Patron(std::string username, std::string card, double fees);
  std::string get_username() const { return m_username; }
  std::string get_cardnum() const { return m_cardnum; }
  double get_libfees() const { return m_libfees; }
  void set_libfees(double fees) { m_libfees = fees; }

private:
  std::string m_username;
  std::string m_cardnum;
  double m_libfees;
};

struct Transaction
{
  Book m_book;
  Patron m_patron;
  Chrono::Date m_date;
};

class Library
{
public:
  Library();
  void add_books(std::vector<Book> books);
  void add_patrons(std::vector<Patron> patrons);
  void checkout_book(const Patron &p, const Book &book, const Chrono::Date &d);
  std::vector<Patron> get_all_fees();
  std::vector<Transaction> get_trans(){return m_trans;};

private:
  std::vector<Book> m_books;
  std::vector<Patron> m_patrons;
  std::vector<Transaction> m_trans;
};

// Book helper functions
bool operator==(const Book &a, const Book &b);
bool operator!=(const Book &a, const Book &b);
ostream &operator<<(ostream &os, const Book &a);
bool is_isbn(std::string isbn);

// Patron helper functions
bool is_fee(const Patron &p);
bool operator==(const Patron &a, const Patron &b);
bool operator!=(const Patron &a, const Patron &b);

// Transaction helper functions
ostream &operator<<(ostream &os, const Transaction &t);

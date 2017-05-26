#include "ex05_09.h"
#include <cctype>
#include <algorithm>

using std::string;
using std::cerr;
using std::endl;
using std::cout;

Book::Book(string i, string t, string a, string d, bool c, Genre g)
    : m_isbn{i}, m_title{t}, m_author{a}, m_date{d}, m_checked{c}, m_genre{g}
{
    if (!is_isbn(i))
        throw Invalid{};
}

bool operator==(const Book &a, const Book &b)
{
    if (a.get_isbn() == b.get_isbn())
        return true;
    return false;
}

bool operator!=(const Book &a, const Book &b)
{
    return !(a == b);
}

ostream &operator<<(ostream &os, const Book &a)
{
    os << a.get_title() << "\n"
       << a.get_author() << "\n"
       << a.get_isbn();
    return os;
}

//accept ISBNs only of the form n-n-n-x where n is an integer and x is a digit or a letter
bool is_isbn(string isbn)
{
    //check first n
    size_t pos_1 = isbn.find_first_of("-");
    if (pos_1 == string::npos)
        return false;
    string str1 = isbn.substr(0, pos_1);
    for (char c : str1)
    {
        if (!isdigit(c))
            return false;
    }
    //check second n
    size_t pos_2 = isbn.find_first_of("-", pos_1 + 1);
    if (pos_2 == string::npos)
        return false;
    string str2 = isbn.substr(pos_1 + 1, pos_2 - pos_1 - 1);
    for (char c : str2)
    {
        if (!isdigit(c))
            return false;
    }
    //check the last n
    size_t pos_3 = isbn.find_first_of("-", pos_2 + 1);
    if (pos_3 == string::npos)
        return false;
    string str3 = isbn.substr(pos_2 + 1, pos_3 - pos_2 - 1);
    for (char c : str3)
    {
        if (!isdigit(c))
            return false;
    }
    //check x
    string str4 = isbn.substr(pos_3 + 1);
    if (!isalnum(str4[0]) || str4.size() > 1)
        return false;

    return true;
}

Patron::Patron(std::string username, std::string card, double fees = 0.0)
    : m_username{username}, m_cardnum{card}, m_libfees{fees} {}

bool is_fee(const Patron &p)
{
    if (p.get_libfees() > 0.0)
        return true;
    return false;
}

bool operator==(const Patron &a, const Patron &b)
{
    if (a.get_cardnum() == b.get_cardnum() && a.get_cardnum() == b.get_cardnum())
        return true;
    return false;
}
bool operator!=(const Patron &a, const Patron &b)
{
    return !(a == b);
}

Library::Library() : m_books{}, m_patrons{}, m_trans{} {}

void Library::add_books(std::vector<Book> books)
{
    for (Book b : books)
    {
        m_books.push_back(b);
    }
}
void Library::add_patrons(std::vector<Patron> patrons)
{
    for (Patron p : patrons)
    {
        m_patrons.push_back(p);
    }
}

void Library::checkout_book(const Patron &p, const Book &book, const Chrono::Date &d)
{
    auto it_1 = std::find(m_books.begin(), m_books.end(), book);
    auto it_2 = std::find(m_patrons.begin(), m_patrons.end(), p);
    if (it_1 == m_books.end() || it_2 == m_patrons.end())
        throw Invalid{};
    if (is_fee(p))
        throw Invalid{};
    //set book check out
    (*it_1).check_book(true);
    // add transaction
    Transaction tran{book, p, d};
    m_trans.push_back(tran);
}

std::vector<Patron> Library::get_all_fees()
{
    std::vector<Patron> ptrs{};
    for (auto &p : m_patrons)
    {
        if (is_fee(p))
            ptrs.push_back(p);
    }
    return ptrs;
}

ostream &operator<<(ostream &os, const Transaction &t)
{
    cout << t.m_book;
    return os;
}

// compile g++ drill.cpp ex05_09.cpp -o ../build/ex05_09.exe
int main()
{
    try
    {
        Patron pt{"lk", "ID1234"};
        Book ux{"123-456-789-x", "UX&UT", "Bjauron", "2017", false, Genre::fiction};
        Library lib{};
        lib.add_patrons({Patron{"lk", "ID1234"}, Patron{"lm", "ID1734"}});
        lib.add_books({Book{"123-476-789-x", "Ux&UT", "Bjauron", "2017", false, Genre::fiction},
                       Book{"123-456-789-x", "UX&UT", "Bjauron", "2017", false, Genre::fiction}});
        lib.checkout_book(pt, ux, Chrono::Date{2017, Chrono::Month::may, 26});
        std::vector<Transaction> trans = lib.get_trans();
        for (auto t : trans)
        {
            cout << t << endl;
        }
    }
    catch (Invalid &ex)
    {
        cerr << ex.what();
    }

    return 0;
}
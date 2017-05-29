#include "ex13.h"
#include <iostream>

using std::cout;
using std::endl;

Rational::Rational(int n, int d) : m_numerator{n}, m_denominator{d}
{
    if (d == 0)
        throw Invalid{};
}

Rational operator+(Rational r1, Rational r2)
{
    int num = r1.numerator() * r2.denominator() + r2.numerator() * r1.denominator();
    int deno = r1.denominator() * r2.denominator();
    return Rational{num, deno};
}

Rational operator-(Rational r1, Rational r2)
{
    int num = r1.numerator() * r2.denominator() - r2.numerator() * r1.denominator();
    int deno = r1.denominator() * r2.denominator();
    return Rational{num, deno};
}

Rational operator*(Rational r1, Rational r2)
{
    int num = r1.numerator() * r2.numerator();
    int deno = r1.denominator() * r2.denominator();
    return Rational{num, deno};
}

Rational operator/(Rational r1, Rational r2)
{
    return r1 * Rational(r2.denominator(), r2.numerator());
}

bool operator==(Rational r1, Rational r2)
{
    if (r1.numerator() * r2.denominator() == r1.denominator() * r2.numerator())
        return true;
    return false;
}

bool operator!=(Rational r1, Rational r2)
{
    return !(r1 == r2);
}

std::ostream &operator<<(std::ostream &os, Rational r)
{
    os << r.value();
    return os;
}

int main()
{
    Rational r1{1, 2};
    Rational r2{1, 3};
    cout << r1 + r2 << endl;
    Rational r3{4, 8};
    if (r1 == r3)
        cout << "r1==r3" << endl;
    if (r1 != r2)
        cout << "r1!=r2" << endl;
    return 0;
}
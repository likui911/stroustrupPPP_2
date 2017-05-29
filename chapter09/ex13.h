#include <iostream>

class Invalid
{
};

class Rational
{
  public:
    Rational(int n, int d);
    double value() const { return (double)m_numerator / m_denominator; }
    int numerator() const { return m_numerator; }
    int denominator() const { return m_denominator; }

  private:
    int m_numerator;
    int m_denominator;
};

// helper functions
Rational operator+(Rational r1, Rational r2);
Rational operator-(Rational r1, Rational r2);
Rational operator*(Rational r1, Rational r2);
Rational operator/(Rational r1, Rational r2);
bool operator==(Rational r1, Rational r2);
bool operator!=(Rational r1, Rational r2);
std::ostream &operator<<(std::ostream &os, Rational r);

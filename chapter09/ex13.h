/*
Design and implement a rational number class, Rational. A rational number has two parts: a numerator and a
denominator, for example, 5/6 (five-sixths, also known as approximately .83333). Look up the definition if 
you need to. Provide assignment, addition, subtraction, multiplication, division, and equality operators. 
Also, provide a conversion to double. Why would people want to use a Rational class?
*/

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

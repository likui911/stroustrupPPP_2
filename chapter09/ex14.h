/*
Design and implement a Money class for calculations involving dollars and cents where arithmetic 
has to be accurate to the last cent using the 4/5 rounding rule (.5 of a cent rounds up; anything 
less than .5 rounds down). Represent a monetary amount as a number of cents in a long int, but input 
and output as dollars and cents, e.g., $123.45. Do not worry about amounts that don’t fit into a long int
*/
#include <iostream>

class Money
{
  public:
    Money(double money);
    long double dollar() const { return (long double)monetary / 100; }

  private:
    long int monetary; //number of cents
};

std::ostream &operator<<(std::ostream &os, Money m);
#include "./ex14.h"
#include <iostream>

Money::Money(double money) : monetary{0}
{
    long int cents = static_cast<int>(money * 100 + 0.5); //4/5 rounding rule
    monetary = cents;
}

std::ostream &operator<<(std::ostream &os, Money m)
{
    os << "$" << m.dollar();
}

int main()
{
    Money d1{123.456};
    std::cout<<d1<<std::endl;
    return 0;
}
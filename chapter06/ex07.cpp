/*
Write a grammar for bitwise logical expressions. A bitwise logical expression 
is much like an arithmetic expression except that the operators are ! (not), ~ 
(complement), & (and), | (or), and ^ (exclusive or). Each operator does its
operation to each bit of its integer operands (see §25.5). ! and ~ are prefix 
unary operators. A ^ binds tighter than a |(just as * binds tighter than +) so 
that x|y^z means x|(y^z) rather than (x|y)^z. The & operator binds tighter than 
^ so that x^y&z means x^(y&z).

Bitwise Grammar:

    inclusive OR 
        |
    exclusive OR 
        ^
    AND 
        &
    unary
        ！
        ~
*/

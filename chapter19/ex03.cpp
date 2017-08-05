/*
Write a template class Pair that can hold a pair of values of any type. Use this to implement a simple symbol table like
the one we used in the calculator (§7.8)
*/
template <typename N, typename V>
class pair
{
  public:
    N name;
    V value;
};
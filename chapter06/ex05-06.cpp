/*
 Add the article the to the “English” grammar in §6.4.1, so that it can describe sentences such as 
 “The birds fly but the fish swim.”
English Grammar
sentence:
    noun verb
    sentence conj sentence
conj:
    "and"
    "or"
    "but"
noun:
    "birds"
    "fish"
    "C++"
verb:
    "rules"
    "fly"
    "swin"
*/

/*
    思路
    首先获取sentence判断是否满足noun verb
    然后判断下一个字符是不是. 如果是，那么这个就是一个正常的语法
        如果不是，判断是否为conj，如果是，再获取sentence
    get_sentence // noun verb
    get_conj



*/

#include "../std_lib_facilities.h"
void sentence()
{

}

int main()
{
    cout<<sentence()<<endl;
    return 0;
}
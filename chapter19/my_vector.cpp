#include "my_vector.h"
#include <iostream>

template <typename T>
vector<T> &vector<T>::operator=(const vector<T> &arg)
{
    if (&arg == this)
        return *this;
    else if (arg.sz <= space)
    {
        for (int i = 0; i < arg.sz; ++i)
        {
            elem[i] = arg.elem[i];
        }
        sz = arg.sz;
        return *this;
    }
    T *p = new T[arg.sz];
    std::copy(arg.elem, arg.elem + arg.sz, p);
    delete[] elem;
    elem = p;
    sz = arg.sz;
    space = arg.space;
}

template <typename T>
vector<T> &vector<T>::operator=(vector<T> &&arg)
{
    elem = arg.elem;
    sz = arg.sz;
    space = arg.space;
    arg.elem = nullptr;
    return *this;
}

template <typename T>
T &vector<T>::operator[](int d)
{
    return elem[d];
}

template <typename T>
T vector<T>::operator[](int d) const
{
    return elem[d];
}

template <typename T>
void vector<T>::reserve(size_t newalloc)
{
    if (newalloc <= space)
        return;
    T *p = new T[newalloc];
    std::copy(elem, elem + sz, p);
    delete[] elem;
    elem = p;
    space = newalloc;
}

template <typename T>
void vector<T>::resize(size_t newsize)
{
    reserve(newsize);
    for (int i = sz; i < space; ++i)
    {
        elem[i] = T{};
    }
    sz = newsize;
}

template <typename T>
void vector<T>::push_back(T d)
{
    if (space == 0)
        reserve(8);
    else if (sz == space)
        reserve(2 * space);
    elem[sz] = d;
    ++sz;
}

int main()
{

    using namespace std;
    vector<int> vec{};
    for (int i = 0; i < 100; ++i)
    {
        vec.push_back(i * i);
    }
    cout << vec[50] << endl;
    return 0;
}
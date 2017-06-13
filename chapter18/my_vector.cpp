
#include <initializer_list>
#include <algorithm>
#include <iostream>

class vector
{
  public:
    vector() : sz{0}, elem{nullptr}, space{sz} {} //default constructor

    explicit vector(std::size_t s) // constructor with size
        : sz{s}, elem{new double[s]}, space{sz}
    {
        for (int i = 0; i < sz; ++i)
            elem[i] = 0.0;
    }

    vector(std::initializer_list<double> lst) //constructor with initializer_list
        : sz{lst.size()}, elem{new double[sz]}, space{sz}
    {
        std::copy(lst.begin(), lst.end(), elem);
    }

    vector(const vector &arg) //copy constructor
        : sz{arg.sz}, space{arg.space}, elem{new double[sz]}
    {
        std::copy(arg.elem, arg.elem + sz, elem);
    }

    vector(vector &&arg) //move constructor
        : sz{arg.sz}, space{arg.space}, elem{arg.elem}
    {
        arg.elem = nullptr;
    }

    ~vector() // destructor
    {
        delete[] elem;
    }

    vector &operator=(const vector &arg);
    vector &operator=(vector &&arg);

    double &operator[](int n)
    {
        return elem[n];
    }

    double operator[](int n) const
    {
        return elem[n];
    }

    void reserve(size_t newalloc);
    void resize(size_t newsize);
    size_t capacity() { return space; }
    size_t size() { return sz; }
    void push_back(double d);

  private:
    std::size_t sz;
    double *elem;
    std::size_t space;
};

vector &vector::operator=(const vector &arg)
{
    if (this == &arg) //自赋值，什么都不做
        return *this;
    if (arg.sz <= space) //如果空间足够，不需要分配空间
    {
        for (int i = 0; i < arg.sz; ++i)
            elem[i] = arg.elem[i];
        sz = arg.sz;
        return *this;
    }
    double *p = new double[arg.sz];
    std::copy(arg.elem, arg.elem + arg.sz, p);
    delete[] elem;
    sz = arg.sz;
    elem = p;
    space = arg.space;
    return *this;
}

vector &vector::operator=(vector &&arg)
{
    delete[] elem;
    elem = arg.elem;
    sz = arg.sz;
    arg.elem = nullptr;
    return *this;
}

void vector::reserve(size_t newalloc)
{
    if (newalloc <= space)
        return;
    double *p = new double[newalloc];
    for (int i = 0; i < sz; ++i)
        p[i] = elem[i];
    delete[] elem;
    elem = p;
    space = newalloc;
}
void vector::resize(size_t newsize)
{
    reserve(newsize);
    for (int i = sz; i < newsize; ++i)
        elem[i] = 0.0;
    sz = newsize;
}
void vector::push_back(double d)
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
    #include <iostream>
    using namespace std;
    vector vec{};
    for (int i = 0; i < 100; ++i)
    {
        vec.push_back(i * i);
    }
    cout<<vec[50]<<endl;
    return 0;
}
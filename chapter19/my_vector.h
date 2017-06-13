#include <initializer_list>
#include <algorithm>

template <typename T>
class vector
{
  public:
    vector() : sz{0}, elem{nullptr}, space{0} {} //默认构造器
    vector(std::size_t s) : sz{s}, space{sz}, elem{new T[sz]}
    {
        for (int i = 0; i < sz; ++i)
            elem[i] = T{};
    }
    vector(const vector<T> &arg) //拷贝构造器
        : sz{arg.sz}, space{arg.space}, elem{new T[sz]}
    {
        std::copy(arg.elem, arg.elem + arg.sz, elem);
    }
    vector(vector<T> &&arg) //移动构造器
        : sz{arg.sz}, space{arg.space}, elem{arg.elem}
    {
        arg.elem = nullptr;
    }
    vector(std::initializer_list<T> lst) //初始化列表构造器
        : sz{lst.size()}, space{sz}, elem{new T[sz]}
    {
        std::copy(lst.begin(), lst.end(), elem);
    }
    ~vector() //析构函数
    {
        delete[] elem;
    }
    vector<T> &operator=(const vector<T> &arg);
    vector<T> &operator=(vector<T> &&arg);
    T &operator[](int d);
    T operator[](int d) const;
    void reserve(size_t newalloc);
    void resize(size_t newsize);
    size_t capacity() { return space; }
    size_t size() { return sz; }
    void push_back(T d);

  private:
    std::size_t sz;    // the size
    T *elem;           // pointer to the elements (or 0)
    std::size_t space; // number of elements plus number of free slots
};

#include <memory>
#include <iostream>
using std::allocator;
using std::initializer_list;

template <typename T, typename A = allocator<T>>
class vector
{
	A alloc;
	T *elem;
	size_t sz;
	size_t space;

  public:
	vector() : sz{0}, space{0}, elem{nullptr} {};
	~vector();
	explicit vector(std::size_t n, const T &val = T());
	explicit vector(initializer_list<T> lst);
	explicit vector(const vector &vec);
	explicit vector(const vector &&vec);

	vector &operator=(const vector &vec);
	vector &operator=(const vector &&vec);

	size_t size() { return sz; }
	void resize(size_t n, const T &val = T());
	size_t capacity() { return space; }
	void reserve(size_t n);

	T &operator[](size_t i);
	const T &operator[](size_t i) const;

	void push_back(const T &val);
	void pop_back(const T &val);

	void print()
	{
		for (int i = 0; i < sz; ++i)
		{
			std::cout << elem[i] << std::endl;
		}
	}
};

template <typename T, typename A>
vector<T, A>::vector(initializer_list<T> lst)
{
	elem = alloc.allocate(lst.size());
	for (int i = 0; i < lst.size(); ++i)
	{
		alloc.construct(&elem[i], *(lst.begin() + i));
	}
	sz = lst.size();
	space = lst.size();
}

template <typename T, typename A>
vector<T, A>::~vector()
{
	for (int i = 0; i < sz; ++i)
	{
		alloc.destroy(&elem[i]);
	}
	alloc.deallocate(elem, space);
}

template <typename T, typename A>
vector<T, A>::vector(const vector &vec)
{
	T *p = alloc.allocate(vec.sz);
	for (int i = 0; i < vec.sz; ++i)
	{
		alloc.construct(&p[i], vec.elem[i]);
	}
	elem = p;
	sz = vec.sz;
	space = sz;
}

template <typename T, typename A>
vector<T, A>::vector(const vector &&vec) : sz{vec.sz}, space{vec.space}, elem{vec.elem}
{
	vec.sz = 0;
	vec.elem = nullptr;
}

template <typename T, typename A>
vector<T, A>::vector(size_t n, const T &val) : sz{n}, space{sz}
{
	elem = alloc.allocate(n);
	for (int i = 0; i < sz; ++i)
	{
		alloc.construct(&elem[i], val);
	}
}

template <typename T, typename A>
vector<T, A> &vector<T, A>::operator=(const vector &vec)
{
	if (this == &vec)
	{
		return *this;
	}
	T *p = alloc.allocate(vec.sz);
	for (int i = 0; i < vec.sz; ++i)
	{
		alloc.construct(&p[i], vec.elem[i]);
	}
	for (int i = 0; i < sz; ++i)
	{
		alloc.destroy(&elem[i]);
	}
	alloc.deallocate(elem, sz);

	elem = p;
	sz = vec.sz;
	space = vec.space;
	return *this;
}

template <typename T, typename A>
vector<T, A> &vector<T, A>::operator=(const vector &&vec)
{
	for (int i = 0; i < sz; ++i)
	{
		alloc.destroy(&elem[i]);
	}
	alloc.deallocate(elem, sz);
	elem = vec.elem;
	sz = vec.sz;

	vec.elem = nullptr;
	vec.sz = 0;
	return *this;
}

template <typename T, typename A>
void vector<T, A>::resize(size_t n, const T &val)
{
	//如果n<sz,移出并销毁超出的部分
	//如果sz<n<space,构造未初始化空间
	//如果n>space,重新分配空间
}

template <typename T, typename A>
void vector<T, A>::reserve(size_t n)
{
	if (n <= space)
	{
		return;
	}

	T *p = alloc.allocate(n);
	for (int i = 0; i < sz; ++i)
	{
		alloc.construct(&p[i], elem[i]);
	}
	for (int i = 0; i < sz; ++i)
	{
		alloc.destroy(*elem[i]);
	}
	alloc.deallocate(elem, space);

	elem = p;
	space = n;
}

template <typename T, typename A>
T &vector<T, A>::operator[](size_t n)
{
	return elem[n];
}

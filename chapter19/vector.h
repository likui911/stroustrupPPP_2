#include <memory>
#include <iostream>

using std::allocator;
using std::initializer_list;

template <typename T, typename A = allocator<T>>
class vector
{
  public:
	typedef T *iterator;
	typedef const T *const_iterator;
	typedef std::reverse_iterator<iterator> reverse_iterator;
	typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
	typedef unsigned int size_type;

	vector() : sz{0}, space{0}, elem{nullptr} {};
	~vector();
	explicit vector(size_type n, const T &val = T());
	explicit vector(initializer_list<T> lst);
	vector(const vector &vec);
	vector(vector &&vec);

	vector &operator=(const vector &vec);
	vector &operator=(vector &&vec);

	iterator begin();
	const_iterator begin() const;
	reverse_iterator rbegin();
	const_reverse_iterator rbegin() const;
	reverse_iterator rend();
	const_reverse_iterator rend() const;
	const_iterator cbegin() const;
	const_iterator cend() const;
	const_reverse_iterator crbegin() const;
	const_reverse_iterator crend() const;

	size_type size()
	{
		return sz;
	}
	void resize(size_type n, const T &val = T());
	size_type capacity()
	{
		return space;
	}
	bool empty() const
	{
		return sz == 0;
	};
	void reserve(size_type n);
	void shrink_to_fit();

	T &operator[](size_type i);
	const T &operator[](size_type i) const;
	T &at(size_type i);
	const T &at(size_type i) const;
	T &front()
	{
		return elem[0];
	}
	const T &front() const
	{
		return elem[0];
	}
	T &back()
	{
		return elem[sz];
	}
	const T &back() const
	{
		return elem[sz];
	}
	T *data()
	{
		return &elem[0];
	}
	const T *data() const
	{
		&elem[0];
	}

	void push_back(const T &val);
	void pop_back();

	void swap(vector &x);
	void clear();

  private:
	A alloc;
	T *elem;
	size_type sz;
	size_type space;
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
vector<T, A>::vector(const vector<T, A> &vec)
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
vector<T, A>::vector(vector<T, A> &&vec) : sz{vec.sz}, space{vec.space}, elem{vec.elem}
{
	vec.sz = 0;
	vec.elem = nullptr;
}

template <typename T, typename A>
vector<T, A>::vector(size_type n, const T &val) : sz{n}, space{sz}
{
	elem = alloc.allocate(n);
	for (int i = 0; i < sz; ++i)
	{
		alloc.construct(&elem[i], val);
	}
}

template <typename T, typename A>
vector<T, A> &vector<T, A>::operator=(const vector<T, A> &vec)
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
vector<T, A> &vector<T, A>::operator=(vector<T, A> &&vec)
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

// todo
// iterator begin();
// const_iterator begin() const;
// reverse_iterator rbegin();
// const_reverse_iterator rbegin() const;
// reverse_iterator rend();
// const_reverse_iterator rend() const;
// const_iterator cbegin() const;
// const_iterator cend() const;
// const_reverse_iterator crbegin() const;
// const_reverse_iterator crend() const;

template <typename T, typename A>
void vector<T, A>::resize(size_type n, const T &val)
{
	if (n < sz)
	{
		for (int i = n; i < sz; ++i)
		{
			alloc.destroy(&elem[i]);
		}
		sz = n;
	}
	else if (n > sz && n < space)
	{
		for (int i = sz; i < n; ++i)
		{
			alloc.construct(&elem[i], val);
		}
		sz = n;
	}
	else
	{
		T *p = alloc.allocate(n);
		for (int i = 0; i < sz; ++i)
		{
			alloc.construct(&p[i], elem[i]);
		}
		for (int i = sz; i < n; ++i)
		{
			alloc.construct(&p[i], val);
		}
		sz = n;
		space = n;
	}
}

template <typename T, typename A>
void vector<T, A>::reserve(size_type n)
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
		alloc.destroy(&elem[i]);
	}
	alloc.deallocate(elem, space);

	elem = p;
	space = n;
}

template <typename T, typename A>
void vector<T, A>::shrink_to_fit()
{
	T *p = alloc.allocate(sz);
	for (int i = 0; i < sz; ++i)
	{
		alloc.construct(&p[i], elem[i]);
	}

	for (int i = 0; i < sz; ++i)
	{
		alloc.destroy(&elem[i]);
	}
	alloc.deallocate(elem, space);

	elem = p;
	space = sz;
}

template <typename T, typename A>
T &vector<T, A>::operator[](size_type n)
{
	return elem[n];
}

template <typename T, typename A>
const T &vector<T, A>::operator[](size_type n) const
{
	return elem[n];
}
template <typename T, typename A>
T &vector<T, A>::at(size_type n)
{
	if (sz << n)
		throw std::out_of_range("acess out of range exception");
	return elem[n];
}

template <typename T, typename A>
const T &vector<T, A>::at(size_type n) const
{
	if (sz << n)
		throw std::out_of_range("acess out of range exception");
	return elem[n];
}

template <typename T, typename A>
void vector<T, A>::push_back(const T &val)
{
	if (sz == 0)
	{
		reserve(8);
	}
	if (sz == space)
	{
		reserve(2 * sz);
	}
	alloc.construct(&elem[sz], val);
	sz++;
}

template <typename T, typename A>
void vector<T, A>::pop_back()
{
	alloc.destroy(&elem[sz]);
	sz--;
}

template <typename T, typename A>
void vector<T, A>::swap(vector &vec)
{
	if (this != &vec)
	{
		size_type _size = sz;
		size_type _space = space;
		T *_elem = elem;

		elem = vec.elem;
		vec.elem = _elem;

		sz = vec.sz;
		vec.sz = _size;
		space = vec.space;
		vec.space = _space;
	}
}

template <typename T, typename A>
void vector<T, A>::clear()
{
	for (int i = 0; i < sz; ++i)
	{
		alloc.destroy(&elem[i]);
	}
	sz = 0;
}
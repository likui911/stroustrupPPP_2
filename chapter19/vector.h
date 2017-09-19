#include <memory>
#include <iterator>
#include <iostream>

using std::allocator;
using std::initializer_list;

template <typename T, typename A = allocator<T>>
class vector
{
  public:
	typedef T value_type;
	typedef value_type &reference;
	typedef const value_type &const_reference;
	typedef value_type *pointer;
	typedef const value_type *const_pointer;

	typedef pointer iterator;
	typedef const_pointer const_iterator;
	typedef std::reverse_iterator<iterator> reverse_iterator;
	typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

	typedef int size_type;

	vector() : sz{0}, space{0}, elem{nullptr} {};
	~vector();
	explicit vector(size_type n, const_reference val = value_type());
	explicit vector(initializer_list<value_type> lst);

	template <class InputIterator>
	vector(InputIterator first, InputIterator last);
	vector(const vector &vec);
	vector(vector &&vec);

	vector &operator=(const vector &vec);
	vector &operator=(initializer_list<value_type> il);
	vector &operator=(vector &&vec);

	iterator begin();
	const_iterator cbegin() const;
	iterator end();
	const_iterator cend() const;

	reverse_iterator rbegin();
	const_reverse_iterator crbegin() const;
	reverse_iterator rend();
	const_reverse_iterator crend() const;

	size_type size()
	{
		return sz;
	}
	void resize(size_type n, const_reference val = value_type());
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

	reference operator[](size_type i);
	const_reference operator[](size_type i) const;
	reference at(size_type i);
	const_reference at(size_type i) const;
	reference front()
	{
		return elem[0];
	}
	const_reference front() const
	{
		return elem[0];
	}
	reference back()
	{
		return elem[sz];
	}
	const_reference back() const
	{
		return elem[sz];
	}
	pointer data()
	{
		return &elem[0];
	}
	const_pointer data() const
	{
		&elem[0];
	}

	void push_back(const_reference val);
	void pop_back();

	void swap(vector &x);
	void clear();

  private:
	A alloc;
	pointer elem;
	size_type sz;
	size_type space;
};

template <typename value_type, typename A>
vector<value_type, A>::vector(initializer_list<value_type> lst)
{
	elem = alloc.allocate(lst.size());
	for (int i = 0; i < lst.size(); ++i)
	{
		alloc.construct(&elem[i], *(lst.begin() + i));
	}
	sz = lst.size();
	space = lst.size();
}

template <typename value_type, typename A>
vector<value_type, A>::~vector()
{
	for (int i = 0; i < sz; ++i)
	{
		alloc.destroy(&elem[i]);
	}
	alloc.deallocate(elem, space);
}

template <typename value_type, typename A>
vector<value_type, A>::vector(const vector<value_type, A> &vec)
{
	pointer p = alloc.allocate(vec.sz);
	for (int i = 0; i < vec.sz; ++i)
	{
		alloc.construct(&p[i], vec.elem[i]);
	}
	elem = p;
	sz = vec.sz;
	space = sz;
}

template <typename value_type, typename A>
template <class InputIterator>
vector<value_type, A>::vector(InputIterator first, InputIterator last)
{
	int count = last - first;
	pointer p = alloc.allocate(count);

	for (int i = 0; i < count; ++i, ++first)
	{
		alloc.construct(&p[i], *(first));
	}

	elem = p;
	sz = count;
	space = sz;
}

template <typename value_type, typename A>
vector<value_type, A>::vector(vector<value_type, A> &&vec)
	: sz{vec.sz}, space{vec.space}, elem{vec.elem}
{
	vec.sz = 0;
	vec.elem = nullptr;
}

template <typename value_type, typename A>
vector<value_type, A>::vector(size_type n, const_reference val)
	: sz{n}, space{sz}
{
	elem = alloc.allocate(n);
	for (int i = 0; i < sz; ++i)
	{
		alloc.construct(&elem[i], val);
	}
}

template <typename value_type, typename A>
vector<value_type, A> &vector<value_type, A>::operator=(const vector<value_type, A> &vec)
{
	if (this == &vec)
	{
		return *this;
	}
	pointer p = alloc.allocate(vec.sz);
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

template <typename value_type, typename A>
vector<value_type, A> &vector<value_type, A>::operator=(initializer_list<value_type> il)
{

	//todo
}

template <typename value_type, typename A>
vector<value_type, A> &vector<value_type, A>::operator=(vector<value_type, A> &&vec)
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

template <typename value_type, typename A>
typename vector<value_type, A>::iterator vector<value_type, A>::begin()
{
	return elem;
}

template <typename value_type, typename A>
typename vector<value_type, A>::const_iterator vector<value_type, A>::cbegin() const
{
	return elem;
}

template <typename value_type, typename A>
typename vector<value_type, A>::iterator vector<value_type, A>::end()
{
	return elem + sz;
}

template <typename value_type, typename A>
typename vector<value_type, A>::const_iterator vector<value_type, A>::cend() const
{
	return elem + sz;
}

template <typename value_type, typename A>
typename vector<value_type, A>::reverse_iterator vector<value_type, A>::rbegin()
{
	return reverse_iterator(elem + sz);
}

template <typename value_type, typename A>
typename vector<value_type, A>::const_reverse_iterator vector<value_type, A>::crbegin() const
{
	return reverse_iterator(elem + sz);
}

template <typename value_type, typename A>
typename vector<value_type, A>::reverse_iterator vector<value_type, A>::rend()
{
	return reverse_iterator(elem);
}

template <typename value_type, typename A>
typename vector<value_type, A>::const_reverse_iterator vector<value_type, A>::crend() const
{
	return reverse_iterator(elem);
}

template <typename value_type, typename A>
void vector<value_type, A>::resize(size_type n, const_reference val)
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
		pointer p = alloc.allocate(n);
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

template <typename value_type, typename A>
void vector<value_type, A>::reserve(size_type n)
{
	if (n <= space)
	{
		return;
	}

	pointer p = alloc.allocate(n);
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

template <typename value_type, typename A>
void vector<value_type, A>::shrink_to_fit()
{
	pointer p = alloc.allocate(sz);
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

template <typename value_type, typename A>
typename vector<value_type, A>::reference vector<value_type, A>::operator[](size_type n)
{
	return elem[n];
}

template <typename value_type, typename A>
typename vector<value_type, A>::const_reference vector<value_type, A>::operator[](size_type n) const
{
	return elem[n];
}
template <typename value_type, typename A>
typename vector<value_type, A>::reference vector<value_type, A>::at(size_type n)
{
	if (sz << n)
		throw std::out_of_range("acess out of range exception");
	return elem[n];
}

template <typename value_type, typename A>
typename vector<value_type, A>::const_reference vector<value_type, A>::at(size_type n) const
{
	if (sz << n)
		throw std::out_of_range("acess out of range exception");
	return elem[n];
}

template <typename value_type, typename A>
void vector<value_type, A>::push_back(const_reference val)
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

template <typename value_type, typename A>
void vector<value_type, A>::pop_back()
{
	alloc.destroy(&elem[sz]);
	sz--;
}

template <typename value_type, typename A>
void vector<value_type, A>::swap(vector &vec)
{
	if (this != &vec)
	{
		size_type _size = sz;
		size_type _space = space;
		pointer _elem = elem;

		elem = vec.elem;
		vec.elem = _elem;

		sz = vec.sz;
		vec.sz = _size;
		space = vec.space;
		vec.space = _space;
	}
}

template <typename value_type, typename A>
void vector<value_type, A>::clear()
{
	for (int i = 0; i < sz; ++i)
	{
		alloc.destroy(&elem[i]);
	}
	sz = 0;
}
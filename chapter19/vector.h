#include <memory>
#include <iterator>
#include <initializer_list>

#ifndef LK_VECTOR
#define LK_VECTOR

using std::allocator;
using std::initializer_list;

template <typename T, typename A = allocator<T>>
class vector
{
  public:
	typedef T value_type;
	typedef value_type *iterator;
	typedef const value_type *const_iterator;
	typedef std::reverse_iterator<iterator> reverse_iterator;
	typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
	typedef allocator<T> allocator_type;

	typedef int size_type;

	vector() : sz{0}, space{0}, elem{nullptr} {};
	~vector();
	explicit vector(size_type n, const value_type &val = value_type());
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

	size_type size() const { return sz; }
	void resize(size_type n, const value_type &val = value_type());
	size_type capacity() const { return space; }
	bool empty() const { return sz == 0; };
	void reserve(size_type n);
	void shrink_to_fit();

	value_type &operator[](size_type i);
	const value_type &operator[](size_type i) const;

	value_type &at(size_type i);
	const value_type &at(size_type i) const;

	value_type &front() { return elem[0]; }
	const value_type &front() const { return elem[0]; }

	value_type &back() { return elem[sz]; }
	const value_type &back() const { return elem[sz]; }

	value_type *data() { return &elem[0]; }
	const value_type *data() const { &elem[0]; }

	template <class InputIterator>
	void assign(InputIterator first, InputIterator last);
	void assign(size_type n, const value_type &val);
	void assign(initializer_list<value_type> il);

	void push_back(const value_type &val);
	void push_back(value_type &&val);
	void pop_back();

	iterator insert(const_iterator position, const value_type &val);
	iterator insert(const_iterator position, size_type n, const value_type &val);
	template <class InputIterator>
	iterator insert(const_iterator position, InputIterator first, InputIterator last);
	iterator insert(const_iterator position, value_type &&val);
	iterator insert(const_iterator position, initializer_list<value_type> il);

	iterator erase(const_iterator position);
	iterator erase(const_iterator first, const_iterator last);

	void swap(vector &x);
	void clear();

	template <class... Args>
	iterator emplace(const_iterator position, Args &&... args);

	template <class... Args>
	void emplace_back(Args &&... args);

	allocator_type get_allocator() const { return alloc; }

  private:
	A alloc;
	value_type *elem;
	size_type sz;
	size_type space;
};

template <typename value_type, typename A>
bool operator==(const vector<value_type, A> &lhs, const vector<value_type, A> &rhs)
{
	if (lhs.size() != rhs.size())
		return false;

	for (int i = 0; i < lhs.size(); ++i)
	{
		if (lhs[i] != rhs[i])
		{
			return false;
		}
	}
	return true;
}

template <typename value_type, typename A>
bool operator!=(const vector<value_type, A> &lhs, const vector<value_type, A> &rhs)
{
	if (lhs.size() != rhs.size())
		return true;

	for (int i = 0; i < lhs.size(); ++i)
	{
		if (lhs[i] != rhs[i])
		{
			return true;
		}
	}
	return false;
}

template <typename value_type, typename A>
bool operator<(const vector<value_type, A> &lhs, const vector<value_type, A> &rhs)
{
	typename vector<value_type, A>::size_type
		count = lhs.size() >= rhs.size() ? rhs.size() : lhs.size();

	for (typename vector<value_type, A>::size_type i = 0; i < count; ++i)
	{
		if (lhs[i] != rhs[i])
		{
			return lhs[i] < rhs[i];
		}
	}
	return lhs.size() < rhs.size();
}

template <typename value_type, typename A>
bool operator<=(const vector<value_type, A> &lhs, const vector<value_type, A> &rhs)
{
	typename vector<value_type, A>::size_type
		count = lhs.size() >= rhs.size() ? rhs.size() : lhs.size();

	for (typename vector<value_type, A>::size_type i = 0; i < count; ++i)
	{
		if (lhs[i] != rhs[i])
		{
			return lhs[i] < rhs[i];
		}
	}
	return lhs.size() <= rhs.size();
}

template <typename value_type, typename A>
bool operator>(const vector<value_type, A> &lhs, const vector<value_type, A> &rhs)
{
	typename vector<value_type, A>::size_type
		count = lhs.size() >= rhs.size() ? rhs.size() : lhs.size();

	for (typename vector<value_type, A>::size_type i = 0; i < count; ++i)
	{
		if (lhs[i] != rhs[i])
		{
			return lhs[i] > rhs[i];
		}
	}
	return lhs.size() > rhs.size();
}

template <typename value_type, typename A>
bool operator>=(const vector<value_type, A> &lhs, const vector<value_type, A> &rhs)
{
	typename vector<value_type, A>::size_type
		count = lhs.size() >= rhs.size() ? rhs.size() : lhs.size();

	for (typename vector<value_type, A>::size_type i = 0; i < count; ++i)
	{
		if (lhs[i] != rhs[i])
		{
			return lhs[i] > rhs[i];
		}
	}
	return lhs.size() >= rhs.size();
}

template <typename value_type, typename A>
void swap(vector<value_type, A> &x, vector<value_type, A> &y)
{
	if (x != y)
	{
		vector<value_type, A> temp = x;
		x = y;
		y = temp;
	}
}

template <typename value_type, typename A>
vector<value_type, A>::vector(initializer_list<value_type> lst)
{
	elem = alloc.allocate(lst.size());
	for (size_type i = 0; i < lst.size(); ++i)
	{
		alloc.construct(&elem[i], *(lst.begin() + i));
	}
	sz = lst.size();
	space = lst.size();
}

template <typename value_type, typename A>
vector<value_type, A>::~vector()
{
	for (size_type i = 0; i < sz; ++i)
	{
		alloc.destroy(&elem[i]);
	}
	alloc.deallocate(elem, space);
}

template <typename value_type, typename A>
vector<value_type, A>::vector(const vector<value_type, A> &vec)
{
	value_type *p = alloc.allocate(vec.sz);
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
	value_type *p = alloc.allocate(count);

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
vector<value_type, A>::vector(size_type n, const value_type &val)
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
	value_type *p = alloc.allocate(vec.sz);
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
	value_type *p = alloc.allocate(il.size());
	for (int i = 0; i < il.size(); ++i)
	{
		alloc.construct(&p[i], *(il.begin() + i));
	}
	for (int i = 0; i < sz; ++i)
	{
		alloc.destroy(&elem[i]);
	}
	alloc.deallocate(elem, space);

	elem = p;
	sz = il.size();
	space = il.size();
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
void vector<value_type, A>::resize(size_type n, const value_type &val)
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
		value_type *p = alloc.allocate(n);
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

	value_type *p = alloc.allocate(n);
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
	value_type *p = alloc.allocate(sz);
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
typename vector<value_type, A>::value_type &vector<value_type, A>::operator[](size_type n)
{
	return elem[n];
}

template <typename value_type, typename A>
const typename vector<value_type, A>::value_type &vector<value_type, A>::operator[](size_type n) const
{
	return elem[n];
}
template <typename value_type, typename A>
typename vector<value_type, A>::value_type &vector<value_type, A>::at(size_type n)
{
	if (sz << n)
		throw std::out_of_range("acess out of range exception");
	return elem[n];
}

template <typename value_type, typename A>
const typename vector<value_type, A>::value_type &vector<value_type, A>::at(size_type n) const
{
	if (sz << n)
		throw std::out_of_range("acess out of range exception");
	return elem[n];
}

template <typename T, typename A>
template <class InputIterator>
void vector<T, A>::assign(InputIterator first, InputIterator last)
{
	int count = last - first;

	for (int i = 0; i < sz; ++i)
	{
		alloc.destroy(&elem[i]);
	}
	if (count > space)
	{
		alloc.deallocate(elem, space);
		elem = alloc.allocate(count);
		space = count;
	}
	for (int i = 0; i < count; ++i)
	{
		alloc.construct(&elem[i], *(first + i));
	}
	sz = count;
}

template <typename T, typename A>
void vector<T, A>::assign(size_type n, const value_type &val)
{
	for (int i = 0; i < sz; ++i)
	{
		alloc.destroy(&elem[i]);
	}
	if (n > space)
	{
		alloc.deallocate(elem, space);
		elem = alloc.allocate(n);
		space = n;
	}
	for (int i = 0; i < n; ++i)
	{
		alloc.construct(&elem[i], val);
	}
	sz = n;
}

template <typename T, typename A>
void vector<T, A>::assign(initializer_list<value_type> il)
{
	int n = il.size();
	for (int i = 0; i < sz; ++i)
	{
		alloc.destroy(&elem[i]);
	}
	if (n > space)
	{
		alloc.deallocate(elem, space);
		elem = alloc.allocate(n);
		space = n;
	}
	for (int i = 0; i < n; ++i)
	{
		alloc.construct(&elem[i], *(il.begin() + i));
	}
	sz = n;
}

template <typename value_type, typename A>
void vector<value_type, A>::push_back(const value_type &val)
{
	reserve(size() == 0 ? 8 : 2 * size());
	alloc.construct(&elem[sz], val);
	sz++;
}

template <typename value_type, typename A>
void vector<value_type, A>::push_back(value_type &&val)
{
	reserve(size() == 0 ? 8 : 2 * size());
	alloc.construct(&elem[sz], std::move(val));
	sz++;
}

template <typename value_type, typename A>
void vector<value_type, A>::pop_back()
{
	alloc.destroy(&elem[sz]);
	sz--;
}

template <typename value_type, typename A>
typename vector<value_type, A>::iterator
vector<value_type, A>::insert(const_iterator position, const value_type &val)
{
	int index = position - begin();
	if (size() == capacity())
		reserve(size() == 0 ? 8 : 2 * size());

	alloc.construct(elem + sz, back());
	++sz;
	iterator pp = begin() + index;
	for (auto pos = end() - 1; pos != pp; --pos)
	{
		*pos = *(pos - 1);
	}
	*(begin() + index) = val;
	return pp;
}

template <typename value_type, typename A>
typename vector<value_type, A>::iterator
vector<value_type, A>::insert(const_iterator position, size_type n, const value_type &val)
{
	int index = position - elem;
	if (size() + n >= capacity())
		reserve(size() == 0 ? n : 2 * size() + n);

	sz += n;
	iterator pp = begin() + index;
	for (int i = size() - 1; i >= index + n; --i)
	{
		alloc.construct(&elem[i], elem[i - n]);
	}

	for (int i = index; i < (index + n); ++i)
	{
		elem[i] = val;
	}
	return pp;
}

template <typename value_type, typename A>
template <class InputIterator>
typename vector<value_type, A>::iterator
vector<value_type, A>::insert(const_iterator position, InputIterator first, InputIterator last)
{
	int index = position - elem;
	int n = last - first;
	if (size() + n >= capacity())
		reserve(size() == 0 ? n : 2 * size() + n);
	sz += n;

	iterator pp = begin() + index;
	for (int i = size() - 1; i >= index + n; --i)
	{
		alloc.construct(&elem[i], elem[i - n]);
	}

	for (int i = index; first != last; ++i, ++first)
	{
		elem[i] = *first;
	}
	return pp;
}

template <typename value_type, typename A>
typename vector<value_type, A>::iterator
vector<value_type, A>::insert(const_iterator position, value_type &&val)
{
	int index = position - begin();
	if (size() == capacity())
		reserve(size() == 0 ? 8 : 2 * size());

	alloc.construct(elem + sz, back());
	++sz;
	iterator pp = begin() + index;
	for (auto pos = end() - 1; pos != pp; --pos)
	{
		*pos = *(pos - 1);
	}
	*(begin() + index) = std::move(val);
	return pp;
}

template <typename value_type, typename A>
typename vector<value_type, A>::iterator
vector<value_type, A>::insert(const_iterator position, initializer_list<value_type> il)
{
	int index = position - elem;
	int n = il.size();
	if (size() + n >= capacity())
		reserve(size() == 0 ? n : 2 * size() + n);
	sz += n;
	iterator pp = begin() + index;
	for (int i = size() - 1; i >= index + n; --i)
	{
		alloc.construct(&elem[i], elem[i - n]);
	}

	const value_type *iter = il.begin();
	for (int i = index; iter != il.end(); ++i, ++iter)
	{
		elem[i] = *iter;
	}
	return pp;
}

template <typename value_type, typename A>
typename vector<value_type, A>::iterator vector<value_type, A>::erase(const_iterator pos)
{
	iterator pp = begin() + (pos - elem);
	if (pp == end())
		return pp;
	for (auto p = pp + 1; p != end(); ++p)
	{
		*(p - 1) = *p;
	}
	alloc.destroy(&*(end() - 1));
	--sz;
	return pp;
}

template <typename value_type, typename A>
typename vector<value_type, A>::iterator vector<value_type, A>::erase(const_iterator first, const_iterator last)
{
	iterator iter_f = begin() + (first - elem);
	iterator iter_l = begin() + (last - elem);
	if (iter_f == end())
		return iter_f;

	int n = iter_l - iter_f;
	for (auto p = iter_l; p != end(); ++p)
	{
		*(p - n) = *p;
	}
	for (auto p = end() - n; p != end(); ++p)
	{
		alloc.destroy(&*p);
	}
	sz -= n;
	return iter_f;
}

template <typename value_type, typename A>
void vector<value_type, A>::swap(vector &vec)
{
	if (this != &vec)
	{
		size_type _size = sz;
		size_type _space = space;
		value_type *_elem = elem;

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

template <typename value_type, typename A>
template <class... Args>
void vector<value_type, A>::emplace_back(Args &&... args)
{
	reserve(size() == 0 ? 8 : 2 * size());

	alloc.construct(&elem[sz], back());
	elem[sz] = std::move(std::forward<value_type>(args)...);
	sz++;
}

template <typename value_type, typename A>
template <class... Args>
typename vector<value_type, A>::iterator
vector<value_type, A>::emplace(const_iterator position, Args &&... args)
{
	int index = position - begin();
	if (size() == capacity())
		reserve(size() == 0 ? 8 : 2 * size());

	alloc.construct(elem + sz, back());
	++sz;
	iterator pp = begin() + index;
	for (auto pos = end() - 1; pos != pp; --pos)
	{
		*pos = *(pos - 1);
	}
	*(begin() + index) = std::move(std::forward<value_type>(args)...);
	return pp;
}

#endif
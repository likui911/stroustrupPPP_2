//#include "vector.h"
#include <vector>
#include <iostream>
using namespace std;

void test_iterator()
{
	vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9};
	for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); ++iter)
	{
		*iter *= 2;
		std::cout << *iter << "  ";
	}
	std::cout << std::endl;

	for (vector<int>::reverse_iterator iter = vec.rbegin(); iter != vec.rend(); ++iter)
	{
		*iter *= 2;
		std::cout << *iter << "  ";
	}
	std::cout << std::endl;

	vector<int> const_vec{1, 2, 3, 4, 5, 6, 7, 8, 9};
	for (vector<int>::const_iterator iter = const_vec.cbegin(); iter != const_vec.cend(); ++iter)
	{
		std::cout << *iter << "  ";
	}
	std::cout << std::endl;

	for (vector<int>::const_reverse_iterator iter = vec.crbegin(); iter != vec.crend(); ++iter)
	{
		std::cout << *iter << "  ";
	}
	std::cout << std::endl;

	vector<int> vec1(vec.begin(), vec.end());
	for (vector<int>::iterator iter = vec1.begin(); iter != vec1.end(); ++iter)
	{
		std::cout << *iter << "  ";
	}
	std::cout << std::endl;
}

void test_assign()
{
	vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	vector<int> vec1(100);
	vector<int> vec2;
	vec1.assign(vec.begin(), vec.end());
	vec2.assign(vec.begin(), vec.end());
	cout << "vec1: " << vec1.size() << " - " << vec1.capacity() << endl;
	cout << "vec2: " << vec2.size() << " - " << vec2.capacity() << endl;
	vector<int> vec3(100);
	vector<int> vec4;
	vec3.assign(10, 11);
	vec4.assign(10, 12);
	cout << "vec3: " << vec3.size() << " - " << vec3.capacity() << endl;
	cout << "vec4: " << vec4.size() << " - " << vec4.capacity() << endl;
	vector<int> vec5;
	vec5.assign({1, 2, 3, 4, 5, 6, 7, 8, 9, 0});
	cout << "vec5: " << vec5.size() << " - " << vec5.capacity() << endl;
}

void test_insert()
{
	vector<int> vec{1, 2, 3, 4, 5, 6};
	vec.insert(vec.end(), 9);
	for (int i : vec)
	{
		cout << i << " ";
	}
	cout<<endl;

	vector<int> vec1{1, 2, 3, 4, 5, 6,7,8};
	vec1.insert(vec1.begin() + 1, 10, 9);
	for (int i : vec1)
	{
		cout << i << " ";
	}
	cout<<endl;
}

void test_erase()
{
	vector<int> vec{0,1,2,3,4,5,6,7,8,9};
	auto iter=vec.erase(vec.begin()+1);
	cout<<*iter<<endl;
	for(auto i:vec)
	{
		cout<<i<<" ";
	}
	cout<<endl;
	auto iter1=vec.erase(vec.begin()+1,vec.begin()+3);
	cout<<*iter1<<endl;
	for(auto i:vec)
	{
		cout<<i<<" ";
	}
	cout<<endl;
}

int main()
{
	//test_insert();
	test_erase();
	return 0;
}
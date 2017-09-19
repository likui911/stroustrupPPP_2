#include "vector.h"
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

	vector<int> vec1(vec.begin(),vec.end());
	for (vector<int>::iterator iter = vec1.begin(); iter != vec1.end(); ++iter)
	{
		std::cout << *iter << "  ";
	}
	std::cout << std::endl;
}

int main()
{
	test_iterator();

	return 0;
}
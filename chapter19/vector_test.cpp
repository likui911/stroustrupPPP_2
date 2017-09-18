#include "vector.h"
#include <iostream>
using namespace std;


vector<int> make_vec()
{
	vector<int> res{1,2,3,4,5,6,7,8,9,0};
	//这里按理说应该调用vector(vector&&)移动构造
	return res;
}

int main()
{
	std::cout<<make_vec().size()<<std::endl;

	return 0;
}
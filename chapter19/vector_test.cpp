#include "vector.h"

int main()
{
	vector<int> vec1;
	vector<int> vec2(10);
	vector<int> vec3{1,2,3,4,5,6,7,8,9,0};
	vector<int> vec4(vec3);
	vec2=vec4;
	vec4=vec4;
	vec2.print();
	return 0;
}
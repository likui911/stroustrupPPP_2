/*
Write a function, char* strdup(const char*), that copies a C-style string into memory it allocates on the free store. Do
not use any standard library functions.
*/
#include <iostream>
#include <string.h>

using namespace std;

char *strdup(const char *s);

int main()
{
	char source[] = "Hello";
	char *destination = NULL;

	destination = strdup(source);

	cout << destination << endl;

	delete[] destination;
	return 0;
}

char *strdup(const char *source)
{
	//strlen not include the last \0
	int len = strlen(source) + 1;

	//allocate memory enough for copy
	char *dest = new char[len];

	for (int i = 0; i < len; i++)
		dest[i] = source[i];

	return dest;
}

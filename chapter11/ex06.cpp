/*
Write a program that replaces punctuation with whitespace. Consider . (dot), ;
(semicolon), , (comma), ? (question mark), - (dash), ' (single quote) punctuation
characters. Don't modify characters within a pair of double quotes ("). For example,
 "- don't use the as-if rule." becomes " don t use the as if rule ".
*/
#include <string>
#include <cctype>
#include <iostream>

using namespace std;

void replace_punct(string &str)
{

	for (int i = 0; i < str.size(); ++i)
	{
		if (ispunct(str[i]) && str[i] != '\"')
		{
			str[i] = ' ';
		}
	}
}

int main()
{
	string s = "\"- don't use the as-if rule.\"";
	replace_punct(s);
	cout << s << endl;
	return 0;
}
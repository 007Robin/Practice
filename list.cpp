#include <iostream>
#include <cctype>
#include <string>
#include <vector>
using namespace std;
using std::vector;

void fun(initializer_list<string> a)
{
	for (auto beg = a.begin(); beg != a.end(); ++beg)
	{
		cout << *beg << " ";
	}
	cout << endl;
}

int main()
{
	string expected = "abc";
	string actual = "acb";
	if (expected != actual)
		fun({"functionX", expected, actual});
	else
		fun({"functionX", "okey"});


} 

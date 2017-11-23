#include <iostream>
#include <cctype>
#include <string>
#include <vector>
using std::cout; using std::endl; using std::string;
using std::cin;

bool findAZ( string const &s)
{
	for (auto i : s){
		if (isupper(i)) return true;
	}
	return false;
}

int main()
{
	string s;
	cin >> s;
	bool result = findAZ(s);
	cout << result << endl;
	
}

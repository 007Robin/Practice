#include<iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cctype>
using namespace std;

string cal(string a, string b, string op)
{
	string s;
	if( op == "+")
		// go to look implementation of stoi
		// consider a number which is bigger than 2 ^ 31 - 1 
		// or smaller - 2^31
		// http://en.cppreference.com/w/cpp/string/basic_string/stol
		// 
		s = to_string(stoi(a) + stoi(b));
	if( op == "-")
		s = to_string(stoi(a) - stoi(b));
	if( op == "*")
		s = to_string(stoi(a) * stoi(b));
	if( op == "/")
		s = to_string(stoi(a) / stoi(b));

	return s;

}

int main()
{
	string s("2*(1+5)/(4-1)"); // 4
	// string s("2*12-24"); // 4 
	stack<string> stack;
	for(auto iter = s.begin(); iter != s.end(); ) {

		// border judge: At least 3 elements
		if(stack.size() == 3) {
			string b = stack.top(); stack.pop();
			string op = stack.top(); stack.pop();
			string a = stack.top(); stack.pop();
			stack.push(cal(a,b,op));    
		}

		// push '('
		if (*iter == '(') {
			stack.push(string(1, *iter));
			++iter;
			while(*iter != ')') {

				// push one byte to statck
				// curtNum = 0
				// if *iter is a number *iter++
				// curt*10 + *iter
				// 1234
				// else if *iter = * | + | - | \
				// push curtNum(consider when to push curtNum)
				// push op
				// else
				// *iter++ //ignore this
				stack.push(string(1, *iter));
				++iter;
			}
		}
		// consider how to avoid miscalculation
		// consider (1 + 2 + 3) * 6 will be ( 1 + 5 * 6
		else if( *iter == ')') {

			string b = stack.top(); stack.pop();
			string op = stack.top(); stack.pop();
			string a = stack.top(); stack.pop();
			stack.pop();
			stack.push(cal(a,b,op));
			++iter;    
		}
		else {
			stack.push(string(1, *iter));
			++iter;
		}
	}  

	while( !stack.empty())  {
		string b = stack.top(); stack.pop();
		string op = stack.top(); stack.pop();
		string a = stack.top(); stack.pop();
		stack.push(cal(a,b,op)); 

		cout << stack.top() << endl;
		stack.pop();

	} 

	return 0;


}

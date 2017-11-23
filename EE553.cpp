#include<iostream>
#include<string>
#include<cmath>
using namespace std;

void print(string msg, int n) {
	while(n > 0){
		cout << msg;
		n--;
	}
}

string repeat(string msg, int n) {
	string big = msg;
	while(n > 0) {
		big += msg;
		n--;
	}
	return big;
}

char nextChar(char c) {
	return c + 1;
}
int factorial(int n) {
	int f = 1;
	while(n > 0) {
		f *= n;
		n--;
	}
	return f;
}

double factorial2(double n) {
	double f = 1;
	while(n > 0) {
		f *= n;
		n--;
	}
	return f;
}
double choose(double a, double b) {
	double ans;
	return factorial2(a) /(factorial2(b)*factorial2(a-b));
}

string reverse(string msg) {

}

int main() {
	print("hello", 3);
	cout << endl;
	string big = repeat("yo", 9);
	cout << big << endl;
	cout << nextChar('a')<< endl;
	cout << factorial(5) << endl;
	cout << factorial2(21) << endl;
//	cout << factorial(51) << endl;
	cout << choose(6, 3) << endl; //6!(52-6)! 52co

	string a = "abc";
	
}


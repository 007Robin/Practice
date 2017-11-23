//Xin Song -- print string
#include<iostream>
#include<string>
using namespace std;

void reverse(string &s) {
	int left = 0;
	int right = s.size() - 1;
	while(left <= right) {
		char temp = s[left];
		s[left] = s[right];
		s[right] = temp;
		left++;
		right--;
	}
	return;
}

int main() {
	cout << "please input a number: " << endl;
	int64_t n;
	while(cin >> n) {
		string s{};
		if(n == 0) {
			char x = '0';
			s = x;
		}
		// n is positive
		while(n > 0) {
			char x = n % 10 + '0';
			n = n / 10;
			s += x;
		}
	    // n is negative
		if( n < 0) {	
			n = -1 * n;
			while(n > 0) {
				char x = n % 10 + '0';
				n = n / 10;
				s += x;
			}
			s += '-';
		}
		reverse(s);	
		cout << "convert numbers to string : " << s << endl;
	}
}

//Xin Song -- 3n+1 conjecture
#include<iostream>
using namespace std;

int main() {
	cout << "Please input a number : " << endl;
	int n;
	while(cin >> n) {
		cout << "Repeat until the number converges to 1." << endl << n << " ";
		while(n != 1) {
			if( n % 2 != 0) {
				n = 3 * n + 1;
				cout << n << " ";
			}
			else {
				n = n / 2;
				cout << n << " ";
			}
		}
		cout << endl;
		if( n == 1) break;
	}
}

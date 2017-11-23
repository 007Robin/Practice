//Xin Song -- read in number and computer n factorial
#include<iostream>
using namespace std;

int main() {
	double n;
	cout << "Please input a number n : "<< endl;
	while(cin >> n) {
		double factorial = 1;
		for(n; n > 0; --n) {
			factorial *= n;
		}
		cout << "n factorial = " << factorial << endl;
	}

}

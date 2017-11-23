#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;
//Always use double!!! never float
int main() {
//	double x = 6.023e+22;
	double y = 1.23456789012345e-300;
	double z = 1.23456789012345e+308;

	for (float i = 0 ; i < 10 ; i+= 0.1) {
		cout << i << ' ';
	}
	cout << endl;

	for (double i = 0 ; i < 100 ; i+= 0.1) {
		cout << i << ' ';
	}
	cout << endl;

	double x = 0;
	for (int i = 0 ; i < 100 ; i++, x+= 0.1) {
		cout << x << ' ';
	}
	cout << endl;

	for (int i = 0 ; i < 100 ; i++) {
		cout << i*0.1 << ' ';
	}
	cout << endl;
	double sum = 0;
	for (double i = 0 ; i < 1000000 ; i+= 0.1) {
		sum += i;
	}
	cout << setprecision(15);
	cout << sum << ' ';
	
	cout << endl;


}

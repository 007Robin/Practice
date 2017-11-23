//Xin Song -- sum reciprocals
#include<iostream>
#include<iomanip>

using namespace std;

int main() {
	
	float sum1f = 0;
	for(float i = 1; i < 101; ++i) {
		sum1f += (1 / i);
	}
	cout << setprecision(20) << endl;
	cout << "sum1f = " << sum1f << endl;

	float sum2f = 0;
	for(float j = 100; j > 0; --j) {
		sum2f += (1 / j);
	}
	cout << "sum2f = " << sum2f << endl;

	cout << "sum1f - sum2f = " << sum1f - sum2f << endl;
	
	
	double sum1d = 0;
	for(double i = 1; i < 101; ++i) {
		sum1d += (1 / i);
	}
	cout << "sum1d = " << sum1d << endl;

	double sum2d = 0;
	for(double j = 100; j > 0; --j) {
		sum2d += (1 / j);
	}
	cout << "sum2d = " << sum2d << endl;

	cout << "sum1d - sum2d = " << sum1d - sum2d << endl;
}

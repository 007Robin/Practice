//Xin Song -- Mystery Sum
#include<iostream>
#include<cmath>
using namespace std;

int main() {
	float n = 1;
	float sum = 0;
	while((1 /(float) (n * n)) >= 0.000001) {
		sum += (1 /(float) (n * n));
		n++;
	}
	cout << "n = "<< n << " sqrt(6*S) = " << sqrt(6 * sum) << endl;
	
	float sum1 = 0, sum2 = 0;
	float i = 1;
	for(i; i < 100001; i++) {
		sum1 += (1 /(float) (i * i));
	}
	cout << "n = 100000" << " sqrt(6*S1) = " << sqrt(6 * sum1) << endl;
	
	float j = 100000;
	for(j; j > 0; j--) {
		sum2 += (1 /(float) (j * j));
	}
	cout << "n = 100000" << " sqrt(6*S2) = " << sqrt(6 * sum2) << endl;
}


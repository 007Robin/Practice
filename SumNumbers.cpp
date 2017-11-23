// Xin Song -- sum the numbers from 1 to 100
#include<iostream>
using namespace std;

int main() {
	//Gauss formula
	int n = 100;
	int Gauss_sum = 0;
	Gauss_sum = n * (1 + n) / 2;
	cout << "Using the Gauss formula n(1+n)/2, the sum is :  " << Gauss_sum << endl;
	//Loop
	int Loop_sum = 0;
	for(int i = 0; i < 101; ++i) {
		Loop_sum += i;
	}
	cout << "Using a loop, the sum is :  " << Loop_sum << endl;

	if(Loop_sum == Gauss_sum) {
		cout << "both answers are the same" << endl;
	}
	else {
		cout << "both answers are not the same" << endl;
	}
}


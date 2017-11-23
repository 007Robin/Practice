#include<iostream>
using namespace std;

double average(const int x[], int n) {
	int sum = 0;
	for(int i = 0; i < n; ++i){
		sum += x[i];
	}
	return sum/n;

}

void readIn(int x[], int n) {
	int m;
	for(int i = 0; i < n; ++i) {
		cin >> m;
		x[i] = m;
	}
}

int main() {
	int grades[] = {85, 90, 91, 87};
	cout << "av1:" <<average(grades, sizeof(grades)/sizeof(int));
	cout << endl;
	int n;
	cout << "Please enter the number of grades:";
	cin >> n;

	int grades2[n];
	readIn(grades2, n);
	cout << "av2:"<< average(grades2, n) << '\n';
}

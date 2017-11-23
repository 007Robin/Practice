//Xin Song -- Windchill
#include<iostream>
#include<math.h>
using namespace std;

int main() {
	int T[18] = {};
	int V[12] = {};
	for (int i = 40, j = 0; i >= -45; i -= 5, j++) {
		T[j] = i;
	}
	for (int i = 5, j = 0; i <= 60; i += 5, j++) {
		V[j] = i;
	}
	double wc[12][18];
	for( int i = 0; i < 12; ++i) {
		for( int j = 0; j < 18; ++j) {
	  		wc[i][j] = 35.74 + 0.6215 * T[j] - 35.75* pow(V[i], 0.16) + 0.4275 * T[j] * (pow(V[i], 0.16));
			cout << round(wc[i][j]) << " ";
		}
		cout << endl;
	}
}

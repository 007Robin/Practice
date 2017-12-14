#include<iostream>
#include<omp.h>
using namespace std;

int main() {
	cout << "Numbers of thread : " << omp_get_num_threads() << endl;

#pragma omp for
	for(int n = 0; n < 10; ++n) {
		cout << n;
	}
	cout << endl;
}

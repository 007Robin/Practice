#include<iostream>
using namespace std;

template<typename T, unsigned N> constexpr
unsigned size(const T (&v)[N]){
	return N;
}

int main(){
	const int A[3] = {1,2, 5};
	cout << size(A) << endl;
	const double B[3] = {1.11,2.222, 5.555};
	cout << size(B) << endl;
}

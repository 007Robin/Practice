//Xin Song -- Primes
#include<iostream>
#include<math.h>
using namespace std;

bool isPrime(unsigned long long p) {
	if( p < 2) {
		return false;
	}
	for( unsigned long long i = 2; i <= sqrt(p); ++i) {
		if( p % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	cout << "please input a number : " << endl;
	unsigned long long n;
	while(cin >> n) {
		if(isPrime(n)) {
			cout << n << " is a prime" << endl;
		}
		else{
			cout << n << " is not a prime" << endl;
		}
	}
}

//Xin Song -- Multiple Primes
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

int countPrimes(unsigned long long a, unsigned long long b) {
	int count = 0;
	while(a <= b) {
		if(isPrime(a)) {
			count++;
		}
		++a;
	}
	return count;
}

int main() {
	cout << "please input two numbers : " << endl;
	unsigned long long a, b;
	while(cin >> a >> b) {
			int ans = countPrimes(a,b);
			cout << ans << endl;
	}
}

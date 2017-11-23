#include<iostream>
#include<cstdint>
using namespace std;

inline int f(int x) { //inline means don't go , it is faster ==> y = 2*2
	return x*x;
}

int main() {
	
	uint8_t a = 0; //0...255
	uint16_t b = 0; //0...65535
	uint32_t c = 1231241;
	uint64_t d = 0; 

	int32_t i = -1234;
	
	bool x = false; //sizeof(x)
	x = true;
	double dd = 1.23;
	long double d2 = 23L; //sizeof(x) depend on your complier
	char cc = 'a';
	
	int y = f(2);
	cout << y << endl;
	
}

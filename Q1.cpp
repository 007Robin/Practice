#include<iostream>
#include<typeinfo>
using namespace std;


int main() {
	cout << "size of short: " << sizeof(short) << endl;
	cout << "size of int: " << sizeof(int) << endl;
	cout << "size of long: " << sizeof(long) << endl;
	cout << "size of long long: " << sizeof(long long) << endl;
	
	cout << "size of uint32_t: " << sizeof(uint32_t) << endl;
	cout << "size of uint64_t: " << sizeof(uint64_t) << endl;
	cout << "size of int16_t: " << sizeof(int16_t) << endl;
	cout << "size of int32_t: " << sizeof(int32_t) << endl;
	
	
	cout << "size of float: " << sizeof(float) << endl;
	cout << "size of double: " << sizeof(double) << endl;

	int g[10];
	cout << "sizeof int[10]: " << sizeof(g) << endl;
	double h[20];
	cout << "sizeof double[20]: " << sizeof(h) << endl;
	double j[3][4];
	cout << "sizeof double[3][4]: " << sizeof(j) << endl;
	char i[80];
	cout << "sizeof char i[80]: " << sizeof(i) << endl;

	cout << "type of 5: " << typeid(5).name() << endl;
	cout << "type of -5: " << typeid(-5).name() << endl;
	cout << "type of 1.25L: " << typeid(1.25L).name() << endl;
	cout << "type of 1.234567e+28: " << typeid(1.234567e+28).name() << endl;

	int aa = 5%2;
	cout <<"a: "<< aa << endl;
	double bb = 5%2 + 3%2;
	cout << "b: " << bb << endl;
	char cc = 'A' + 1;
	cout << "c: " << cc << endl; 
	float dd = 1.0 + 0.5;
	cout << "d: " << dd << endl;
	double ee = 2.5;
	cout << "e: " << ee<< endl;
	double ff = (int)5.0/2.0;
	cout << "f: " << ff<< endl;
	double gg = int(5.0)/2.0;
	cout << "g: " << gg << endl;
	int hh = int(5.0/2.0);
	cout << "h: " << hh << endl;

	
	long long x = 1;
	cout << typeid(x).name() << endl;
	unsigned long int y = 1;
	cout << typeid(y).name() << endl;
	
	
	
	



}

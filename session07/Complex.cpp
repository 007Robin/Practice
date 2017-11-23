#include<iostream>
#include "Complex.hh"

using namespace std;
 
void f(); 

int main() {
	f();
	const Complex c1(1.0, 2.5);
	const Complex c2(1.0);
	const Complex c3 = c1 + c2;

}

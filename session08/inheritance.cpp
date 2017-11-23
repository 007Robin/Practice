#include "inheritance.hh"
#include<iostream>
#include<string>
using namespace std;

int main() {
	base b1;
	b1.print(cout);
	derived d1;
	d1.print(cout);
	return 0;
}

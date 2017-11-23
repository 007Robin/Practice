#include<iostream>
using namespace std;

extern int x ;
const extern double pi;// magled name is really pi_cd

void g() {
	cout << x;
	// pi = 4;
}

#include<iostream>
using namespace std;

void g();

void f() {
	int x = 2;
	cout << x;
	g();
	static int y = 3; // this is only see in f, but live global 
	cout << y;
	y++; // 1st is 3, next time is 4
}
// global are initialized when task is loaded, usually the value is in the executable 
int x = 4; //global (visible to everyone in the program
// need to be const because everyone can change it dangerous.
const int y = 0 ; // initialied to 0(if not assign 0)
const double pi = 3.1415926; // internal name is pi_d

int main(){
	int x = 3;
	int y; // y is random juck because it is auto (on the stack)
	cout << x;
	f();
	if(x < 5) {
		int x = 6;
		cout << x;
	}
	cout << x;
	cout << ::x; // print the global x
	f(); // the varible in f() created again 
}

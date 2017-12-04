#include<iostream>
using namespace std;

class A {
	private:
		int  speed;
	public:
		A(int s) : speed(s) { cout << "a";}
		virtual void f() = 0; // pure virtual
};
class B : public A {
	public:
		B() : A(55) { cout << "b";}
		void f() override { cout << "B"; }
		
};
class C : public A {
	public:
		C() : A(55) { cout << "c";}
		void f() override { cout << "C"; }
};

int main() {
	//  A a1; // ILLEGAL: A is an abstract class because it contains 1 pure virtual
	
	A* a1; // LEGAL  didn't create any object, just a pointer to A type
	B b1; // LEGAL  //first construct father a, then itself b
	b1.f(); // LEGAL, and just as fast as if f() were not virtual   
	C c1; // LEGAL
	c1.f(); // LEGAL output: C
	a1 = &b1;
	a1->f();  // slower (LEGAL)
	(*a1).f();
	a1 = &c1;
	a1->f(); // output: C
	//abBacCBBC
}

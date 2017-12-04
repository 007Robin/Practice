#include<iostream>
using namespace std;
class A{
	private: 
		int x;
	protected: //children can see
		int y;
	public:
		int z;
		A(int x, int y, int z) : x(x), y(y), z(z) {
		cout << "A";
		}
		void f() {cout << "hello";}
};
// public inheritance is what is private in the base is INVISIBLE
class B : public A {
	// private -- INVISIBLE
	// protected -- protected
	// public -- public
	private: 
		int x;
	protected:
		int w;
	public:
		int z;
	B():A(1,2,3) {cout << "B";}
};

class C : private A {
	// what was private -- now INVISIBLE
	// protected -- private
	// public -- private
	public:
		C():A(1,2,3) {cout << "C";}
};

class D : protected A {
	//private -- INVISIBLE
	//protected or public -- protected
	public:	
		D():A(1,2,3) {cout << "D";}

};
int main() {
//	A* p1 = new D(); // not legal, 'A' is an inaccessible base of 'D'
//	A* p2 = new C(); // not legal, 'A' is an inaccessible base of 'C' 
	A* p3 = new B(); // legal,
	A a1(1,2,3);
	B b1;
	C c1;
	D d1;
	//ABAABACAD
}

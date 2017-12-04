#include<iostream>
#include<string>
using namespace std;
class Base {
	private:
		int x;
	public:
		Base(int x) : x(x) { cout << "p"; }
		~Base() { cout << 'q';}
		virtual void f() const {cout <<  "base"; };
};

class Derived : public Base{
	private:
		int y;
	public:
		Derived(int x, int y) : Base(x), y(y) { cout << "jo!"; }
		~Derived() { cout << 'x';}
		void f() const override { cout << "derived"; }
};

int main() {
	//Base b; //illegal
	Base b1(2); //legal
	b1.f();
	Derived d1(1, 2);  // pjo!derivedxq
	d1.f(); //
}

//OUTPUT: pbasepjo!derivedxqq

#include<iostream>
#include<math.h>
using  namespace std;
class A {
	private:
		int x;
		static int count;
	public:
		A(int x) :x(x) {
			count++;
			cout << x << 'A';
		}
		A(const A& a) : x(a.x) {
			count++;
			cout << "copy";
		}
		A& operator =(const A& a) {
			count++;
			cout << "=";
		}
		~A() {
			count--;
			cout << x << "~A\n";
		}
		void f() { cout << "test";}
		static int getCount() { return count;}
};
int A::count = 0;
void f() {
A a1(5);
a1.f();
}
int main() {
	f();
	cout << "count=" << A::getCount() << endl;
	f();
	return 0;
}

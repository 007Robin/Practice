class A{};
class B : public A {
	public:
		int x;

		B(int x) : x(x) { cout << "p"; }
		~B() { cout << 'q'};
};

int main() {
	A a1; // legal
	A* pal; // legal

	// cout << *pal; // illegal, looking at unitialized memory (crash)

	//B b1; //illegal, no such constructor
	B b1(5); //legal
	B b2(5.2); //legal, but warning 
	B b3((int)5.2);
	B *pb4;  // legal, points alwasys legal
	pb4 = &pb3; //points to b3
	// pb4->x = 5; //illegal (x is private)

}

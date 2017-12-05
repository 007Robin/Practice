#include "02LinkedList.hh"
#include "02LinkedList.hpp"
#include<string>
using namespace std;

int main(){
	LinkedList<int> a;//empty
	a.addFirst(3);
	a.addFirst(1);
	a.addFirst(4);
	a.addLast(1);	// 4 1 3 1
	a.removeFirst(); //1 3 1
	std::cout << a << std::endl;
	
	LinkedList<string> b;
	b.addFirst("Hello");
	b.addLast("Goodbye");
	std::cout << b << std::endl;
	
	LinkedList<double> c;
	c.addFirst(1.97);
	c.addLast(2.45);
	std::cout << c << std::endl;

}

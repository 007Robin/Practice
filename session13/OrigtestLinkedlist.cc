#include "OrigLinkedList.hh"
#include<string>
using namespace std;

int main(){
	LinkedList<int> a;//empty
	a.addFirst(3);
	a.addFirst(1);
	a.addFirst(4);
	a.addLast(1);	// 4 1 3 1
	a.removeFirst(); //1 3 1
	cout << a << endl;
	LinkedList<string> b;
	b.addFirst("Hello");
	b.addLast("Goodbye");

	cout << b << endl;
}

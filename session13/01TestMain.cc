#include "01LinkedList.hh"
#include<string>
using namespace std;

int main(){
/*	LinkedList a;//empty
	a.addFirst(3);
	a.addFirst(1);
	a.addFirst(4);
	a.addLast(1);	// 4 1 3 1
	a.removeFirst(); //1 3 1
	cout << a << endl;
*/

	LinkedList b;//empty
	b.addFirst("hello");
	b.addFirst("you");
	b.addFirst("goodbey");
	b.addLast("bey");	// 4 1 3 1
	b.removeFirst(); //1 3 1
	cout << b << endl;

}

/*
g++-4.9 -std=c++11 01LinkedList.cc -c
g++-4.9 -std=c++11 01TestMain.cc -c
g++-4.9 -std=c++11 01TestMain.o 01LinkedList.o -o 01LinkedList   
 */

#include<iostream>
using namespace std;

int main() {
	int a = 5;
	cout << a + 2 << '\n';
	cout << " &a: "<< &a<< '\n';
	
	int* p; //unintitialize p point to random
	//cout << *p; ----- probably segmentation fault. 
	p = &a; // p = a means p point to memery[5]. 
	cout << "  p: " << p << '\n';
	cout << " &p: " << &p << '\n';
	
	int** q; // q is a pointer to pointer to int
	// q = &a; ---- wrong type
	//*q = &a; ---- segmentation fault on try to assign *p.
	q = &p;  // q pointer to p(p point to a)
	cout << " *q: "<<  *q << '\n';  // get &a <==> p
	cout << "**q: "<< **q << '\n';  // get a

}

/******************
7                                                                                                                          
 &a: 0x7ffca9618b8c                                                                                                        
  p: 0x7ffca9618b8c                                                                                                        
 &p: 0x7ffca9618b90                                                                                                        
 *q: 0x7ffca9618b8c                                                                                                        
**q: 5 
******************/

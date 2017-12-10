#include<iostream>
using namespace std;

void rect2polar(double x, double y, double r, double  theta) {

}
void rect2polar(double x, double y, double &r, double  &theta) {

}


int main() {
	int a = 3; // regular int what location??? 
	int b = 4;
	cout << &a << '\n';
	cout << &b << '\n';
	int * p = &a; // point p to where a lives, p is a's memeroy location
	int *q; // q is a pointer to int
	q = &a;  
	*p = 5; // a = 5, *p means : go where you live and change a
	cout << &p; //int *p address of p is a pointer to pointer to int
	int**q = &p; 
	**q = 6; // a = 6
	
	//cout << ++*q++; //read that, sucker.

	cout << *q << '\n';
	q = &b; 
	cout << *q << '\n';
//	q = 10; // q point to the memeroy lacation 10
//	q = (int*)10; // it is int*. 
//	cout << *q << '\n'; //segmation fault
	
	const double pi = 3.1415926;
/*	double* death = &pi;  //常量指针与一个指向常量的指针
	const double* death = &pi; //death is a pointer const 
	double* const death = &pi;
	*death = 4;    
*/
	double* dd = (double*)&pi;
	*dd = 4;
	cout << pi <<'\n';


	double x = 2, y = 5;
	double r, theta;
	rect2polar(x,y,r,theta);
	rect2polar(x, y, &r, &theta);
}


// int b = 0xFF0080; //RGB HTML #FF0080 (255*256+0)*256+128

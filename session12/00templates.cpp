#include<iostream>
using namespace std;

int f(int x){
	return 2*x;
}
double f(double x){
	return 2*x;
}
int main() {
	int y = f(2);
	double y2 = f(2.5);
	cout << f(2.2f) << endl; //Error don't know which one to choose
	cout << y << " " << y2 << endl;
}

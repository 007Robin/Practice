#include<iostream> 
#include<math.h>
#include<cmath>
using namespace std;
/*
   (x, y) -> (r theta) theta = atan(y/x)
*/
void rect2polar(double x,double y, double& r, double& theta) {
	r = sqrt(x*x + y*y);
	theta = atan2(y/x); //never use atan, we use atan2
}

int main() {
	double x,y, r, theta;
	cout << "Enter x y : "<< endl;
	cin >> x >> y;
	rect2polar(x, y, r, theta);
	cout << r << "\t" << theta << '\n';
}


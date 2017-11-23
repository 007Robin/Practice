#include "vehicle.hh"
#include<iostream>
using namespace std;

int main() {
	Vehicle v(55., 1000.);
	Car c1("yellow", 99., 1000.);
	cout << c1 << endl;
	Bus b1(28,35., 1000.);
	cout << b1 << endl;
//	Truck t1(19000, 42);
//	cout << t1 << endl;
	Space s;
	cout << "vehicle:"<<sizeof(v) << endl;
	cout << "string:"<<sizeof(string) << endl;
	cout << "car:" <<sizeof(c1) << endl;
	cout <<"b1:" <<sizeof(b1) << endl;
	cout <<"int:" <<sizeof(int) << endl;
	cout << "A:"<<sizeof(A) << endl;
	cout << "Space:"<<sizeof(Space) << endl;
	cout << "Space2:"<<sizeof(Space2) << endl;
	cout << "Space3:"<<sizeof(Space3) << endl;
//	cout << "Person:"<<sizeof(Person) << endl;
	short int x[10] = {1,2,3};
	cout << &x[0] << endl;
	cout << &x[1] << endl;;

#if 0
	vector<Vehicle*> vehicles;
	vehicles.push_back(new Car());
	vehicles.push_back(new Bus());
	for( auto v : vehicles) {
		v.payToll();
	}
#endif

}

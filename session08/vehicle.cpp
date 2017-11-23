#include "vehicle.hh"
#include<iostream>
using namespace std;

int main() {
	Car c1("yellow", 99);
	cout << c1 << endl;
	Bus b1(28,35);
	cout << b1 << endl;
	Truck t1(19000, 42);
	cout << t1 << endl;

#if 0
	vector<Vehicle*> vehicles;
	vehicles.push_back(new Car());
	vehicles.push_back(new Bus());
	for( auto v : vehicles) {
		v.payToll();
	}
#endif

}

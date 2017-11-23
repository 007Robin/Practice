#include "Mvehicle.hh"
#include<iostream>
#include<vector>
using namespace std;

int main() {
//	Vehicle v(55., 1000.);
	Car c1("yellow", 99., 1000.);
	cout << c1 << endl;
	Bus b1(28,35., 1000.);
	cout << b1 << endl;
	Truck t1(42 ,19000, 4);
	cout << t1 << endl;
	//	v.payToll();
	c1.payToll();
	b1.payToll();
	t1.payToll();
	Vehicle* p;
	p = &t1;
	p->payToll();
	p = &c1;
	p->payToll();
	cout << "SIZE OF CAR2: " << sizeof(Car) << endl;
	int* pointer;
	cout << "SIZE OF int* pointer: " << sizeof(pointer) << endl;
	TrafficSim traffic;
	traffic.addCar();
	traffic.addBus();
	traffic.addCar();
	traffic.addBus();
	traffic.addCar();
	traffic.addCar();
	traffic.payToll();
}

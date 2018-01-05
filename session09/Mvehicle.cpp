#include "Mvehicle.hh"
#include<iostream>
#include<vector>
using namespace std;

int main() {
//	Vehicle v(55., 1000.);
	Car c1("yellow", 99., 1000.);	//new <-> delete
	cout << c1 << endl;		//I am a car and my speed = 99, my color is yellow
	Bus b1(28,35., 1000.);
	cout << b1 << endl;		//I am a bus and my speed = 35, my passengers are 28
	Truck t1(42 ,19000, 4);
	cout << t1 << endl;		//I am a turck and my speed = 42
	//	v.payToll();
	c1.payToll();			//Car pays:14
	b1.payToll();			//Bus pays: 4
	t1.payToll();			//Truck pays:380000
	Vehicle* p;
	p = &t1;
	p->payToll();			//Truck pays:380000
	p = &c1;
	p->payToll();			//Car pays:14
	cout << "SIZE OF CAR2: " << sizeof(Car) << endl;	//40
	int* pointer;
	cout << "SIZE OF int* pointer: " << sizeof(pointer) << endl;	//8
	TrafficSim traffic;
	traffic.addCar();
	traffic.addBus();
	traffic.addCar();
	traffic.addBus();
	traffic.addCar();
	traffic.addCar();
	traffic.payToll();		//
}
/*
Car pays:14
Bus pays: 4
Car pays:14
Bus pays: 4
Car pays:14
Car pays:14
car destructor
bus destructor nothing to do
car destructor
bus destructor nothing to do
car destructor
car destructor
bus destructor nothing to do ->line 10
car destructor		->line 8
*/

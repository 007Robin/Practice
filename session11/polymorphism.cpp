//polymorphism: sent the same message to different objects
//execute different methods (at runtime)
#include<iostream>
#include<vector>
#include<iterator>
using namespace std;

class Vehicle{
	friend ostream& operator <<(ostream& s, const Vehicle& v) {
		v.Vehicle::print(s);
		v.print(s);
//		return s << "vehicle\n"; 		
		return s;
	}
public:
	virtual void payToll() const = 0;
	virtual void print(ostream& s) const {s << "I'm A Vehicle!!--";}
};
//inheritance: a car is a vehicle
class Car : public Vehicle{
	public: 
		void payToll() const {
			cout << "I'm a car pay 4" << endl;
		}
	virtual void print(ostream& s) const {s << "I'm A Car!" << endl;}
};
class Truck : public Vehicle{
	public: 
		void payToll() const {
			cout << "I'm a truck pay 8" << endl;
		}
	virtual void print(ostream& s) const {s << "I'm A truck!" << endl;}
};

int main() {
	Car c1;
	c1.payToll();
	
	Truck t1;

	Vehicle* p = & c1;
	p->payToll(); //polymorphism, we do know which one is executed
	
	p = &t1;
	p->payToll();

	vector<Vehicle*> vehicles;
	vehicles.push_back(new Car());
	vehicles.push_back(new Truck());
	vehicles.push_back(new Car());
#if 0	
	for(int i = 0; i < vehiclea.size(); ++i) {
		cout << vehicles[i] << " " << *vehicles[i];
	}
	for(int i = 0; i < vehiclea.size(); ++i) {
		vehicles[i]->payToll();
	}
	for(int i = 0; i < vehiclea.size(); ++i) {
		delete vehicles[i];
	}
#endif
	for(vector<Vehicle*>::iterator i = vehicles.begin(); i != vehicles.end(); i++) {
		cout << "*i: "<<  *i << " **i: " << **i << endl;
	}
	for(vector<Vehicle*>::iterator i = vehicles.begin(); i != vehicles.end(); i++) {
		(*i)->payToll();
		cout << endl;
	}
	for(vector<Vehicle*>::iterator i = vehicles.begin(); i != vehicles.end(); i++) {
		delete (*i);
	}
}

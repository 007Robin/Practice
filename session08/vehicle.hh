#include<iostream>

// parent class super class (object-oriented terminology)
//base class in C++ and Java
class Vehicle{
	private:
		int speed;
	public:
		Vehicle(int speed) : speed(speed) {}
		void setSpeed(int s) { speed = s; }
		friend std::ostream& operator<< (std::ostream& s, const Vehicle& v) {
			return s << v.speed; 
		}

};

// A truck carries cargo (weight) speed
class Truck : public Vehicle{ // A truck is A Vehicle
	private:
		double weight;
	public:
		Truck(double weight, int s) : Vehicle(s), weight(weight) {
		}
		friend std::ostream& operator<< (std::ostream&s, const Truck& t) {
			return s << "I am a turck and my speed = " << (const Vehicle&)t << ", Cargo weight = " << t.weight;
		}
};
// A bus carries passenger (people) speed
class Bus : public Vehicle{
	private:
		int numPasseger;
	public:
		Bus(int numP, int s) : Vehicle(s), numPasseger(numP) {
		}
		friend std::ostream& operator<< (std::ostream& s, const Bus& b) {
			return s << "I am a bus and my speed = " << (const Vehicle&)b << ", my passengers are " << b.numPasseger;  
		}
};
// A car has a color and speed
class Car : public Vehicle {
	private:
		std::string color;
	public:
		Car(const std::string& color, int s) : Vehicle(s), color(color) {
		}
		friend std::ostream& operator<<(std::ostream& s, const Car& c) {
			return s << "I am a car and my speed = " << (const Vehicle&)c << ", my color is "<< c.color; 
		}
};


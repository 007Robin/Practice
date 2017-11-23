#include<iostream>

// parent class super class (object-oriented terminology)
//base class in C++ and Java
class Vehicle{
	private:
		double speed;
		double weight;
//		const static double pi;
		static int count;
	public:
		Vehicle(double speed, double weight) : speed(speed), weight(weight) { count++; }
		void setSpeed(double speed) { speed = speed; }
		double getSpeed() { return speed; }
		friend std::ostream& operator<< (std::ostream& s, const Vehicle& v) {
			return s << v.speed; 
		}
		// method function only take memeroy when you call them. 
};

//const double Vehicle::pi = 3.14159;
int Vehicle::count = 0;

// A truck carries cargo (weight) speed
class Truck : public Vehicle{ // A truck is A Vehicle
	private:
		int axle;
	public:
		Truck(double speed, int axle, double weight) : Vehicle(speed, weight), axle(axle) {
		}
		friend std::ostream& operator<< (std::ostream&s, const Truck& t) {
			return s << "I am a turck and my speed = " << (const Vehicle&)t;
		}
		void payToll() {
			std::cout << 20 * axle;
		}
};
// A bus carries passenger (people) speed
class Bus : public Vehicle{
	private:
		int numPasseger;
	public:
		Bus(int numP, double speed, double weight) : Vehicle(speed, weight), numPasseger(numP) {
		}
		friend std::ostream& operator<< (std::ostream& s, const Bus& b) {
			return s << "I am a bus and my speed = " << (const Vehicle&)b << ", my passengers are " << b.numPasseger;  
		}
		void payToll() {
			std::cout << 4;
		}
};
// A car has a color and speed
class Car : public Vehicle {  
	private:
		std::string color;
	public:
		Car(const std::string& color, double speed ,double weight) : Vehicle(speed, weight), color(color) {
		}
		friend std::ostream& operator<<(std::ostream& s, const Car& c) {
			return s << "I am a car and my speed = " << (const Vehicle&)c << ", my color is "<< c.color; 
		}
		void payToll() {
			std::cout << 14;
		}
};
class A{};  //size = 1
/*
0 1 2 3 4 5 6 7 
8 9 10 11 12 13 14 15
16 17 18 19 20 21 22 23
24 
   */
class Space{ // size = 32
	char a; // 1st byte -- 3 bytes padding
	int b; // 4th - 7th
	double c; // 8..15 th bit
	char d; // 16th
	unsigned int x : 2; // bit field 17
	int e; // 20 .. 23th
	signed int y : 3; // -4 -3 -2 -1 0 1 2 3 byte 24.. 32:
};
class Space2{ //size = 24
	double c; // 0..7 th bit
	int b; // 8th - 11th
	char d; // 12th
	char a; // 13st byte -- 3 bytes padding
	unsigned int x : 2; // bit field 14
	signed int y : 3; // -4 -3 -2 -1 0 1 2 3 byte 14
	int e; // 20...23
};
class Space3{ //size = 16
	double c; // 0..7 th bit
	int b; // 8th - 11th
	char d; // 12th
	char a; // 13st byte -- 3 bytes padding
	unsigned int x : 2; // bit field 14
	signed int y : 3; // -4 -3 -2 -1 0 1 2 3 byte 14
	int e : 11; // 20...23
};
class Person{
	unsigned char age;
	unsigned int gender:1;
	unsigned int a:1, b:1, c:1, d:1;
};

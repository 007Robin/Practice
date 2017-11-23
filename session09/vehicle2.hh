#include<iostream>
#include<vector>

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
		virtual void payToll() = 0;
		/*void payToll() {
			std::cout << "what do i pay" << std::endl;
		}*/
		virtual ~Vehicle() { }
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
			return s << "I am a turck and my speed = " << (const Vehicle&)t << std::endl;
		}
		void payToll() {
			std::cout << "Truck pays:" << 20 * axle << std::endl;
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
			std::cout << "Bus pays: "<< 4 << std::endl;
		}
		~Bus() { std::cout << "bus destructor nothing to do" << std::endl; }
};
// A car has a color and speed
class Car : public Vehicle {  
	private:
		std::string color;
		int* p;
	public:
		Car(const std::string& color, double speed ,double weight) : Vehicle(speed, weight), color(color) {
			p = new int[30];
		}
		friend std::ostream& operator<<(std::ostream& s, const Car& c) {
			return s << "I am a car and my speed = " << (const Vehicle&)c << ", my color is "<< c.color; 
		}
		void payToll() {
			std::cout << "Car pays:" << 14 << std::endl;
		}
		~Car() {
			std::cout << "car destructor" << std::endl;
			delete []p;
		}
};

class TrafficSim{
	private:
		Vehicle* vehicles[10]; 
		int n;
	public:
		TrafficSim() {
			n = 0;
		}
		~TrafficSim() {
			for(int i = 0; i < n ; i++) {
				delete vehicles[i];
			}
		}
		void addCar() {
			vehicles[n++] = new Car("red", 55, 1200);
		}
		void addBus() {
			vehicles[n++] = new Bus(30, 15, 1200);
		}
		void payToll() 
		{
			for (int i = 0; i < n; i++) {
				vehicles[i]->payToll();
			}
		}
};

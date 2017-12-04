#include<iostream>
using namespace std;
// speed(double)
class Vehicle {
	private:
		double speed;
	public:
		Vehicle(double s) : speed(s) {
			cout << "A";
		}
		~Vehicle() { cout << "a"; }
};

//hp(double)
class Engine {
	private:
		double hp;
	public:
		Engine(double hp) : hp(hp) { cout << "B";}
		~Engine() { cout << "b"; }
};

//pressure (int)
class Wheel {
	private:
		int pressure;
	public:
		Wheel(int p) : pressure(p) { cout << "C"; }
		~Wheel() { cout << "c"; }
};


class Car : public Vehicle {
	private:
		Wheel w1,w2,w3,w4;
		Engine e;
		//  Wheel w[4]; // automatically calls Wheel()
	public:
		//initialization order make no sence
		Car(double s, int pressure,  double hp) : e(hp), Vehicle(s), w1(pressure), w2(pressure), w3(pressure), w4(pressure) { cout << "D"; }
		~Car() { cout << "d"; }
};
int main() {
	Car c1(55.0, 200.0, 28);  //ACCCCBDdbcccca  have no any connection with initialization order, only related to veriate create order
}

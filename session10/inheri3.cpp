class Vehicle {
	private:
		int speed;
	public:
		Vehicle(double s) : speed(s) {}

};
class Engine {
	private:
		double hp;
	public:
		Engine(double hp) : hp(hp) {}
		~Engine() { cout << "c"; }
};
class Wheel {
	private:
		int pressure;
	public:
		Wheel(int p) : pressure(p) {}
};
class Car : public Vehicle{
	private:
		Engine e;
		Wheel w1,w2,w3,w4; //
	public:
		Car(double speed, double hp, int pressure) : Vehicle(s) , e(hp), w1(pressure), w2(pressure), w3(pressure), w4(pressure) {}
		~Car() {
			cout << "d";
		}

};

int main() {
	Car c1(55.0, 200.0, 28); // dccccba
}

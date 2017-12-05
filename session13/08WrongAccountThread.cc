#include<thread>
#include<iostream>
#include<unistd.h>
using namespace std;
class Account{
	private:
		double bal;
	public:
		Account() {bal = 0;}

		void deposit(double amt){
			//first read bal into register, add amt, write back
			bal += amt;
		}
		bool withdraw(double amt){
			if(bal < amt)
				return false;
			else { 
				bal -= amt;
				return true;
			}
		}
		//	~Account(){};
		//friend std::ostream& operator <<(std::ostream& s, const Account& a); 
		double balance() const {
			return bal;
		}
};

Account a; //0

void deposits() {
	for(int i = 0; i < 1000000; i++){
		a.deposit(1);
	}
}
void withdraws() {
	for(int i = 0; i < 500000; i++){
		a.withdraw(1);
	}
}
int main() {
	thread t1(deposits);
	thread t2(withdraws);
    t1.join();
    t2.join();

	cout << a.balance() << endl;
}

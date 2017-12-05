#include<string>
#include<iostream>
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

int main() {
	Account a;
	for(int i = 0; i < 100000000; i++){
		a.deposit(1);
	}
	for(int i = 0; i < 50000000; i++){
		a.withdraw(1);
	}
	cout << a.balance() << endl;
}

#include "Account.h"
using namespace std;

Account::Account(const string& firstname,const string& lastname, uint64_t id) : firstname(firstname), lastname(lastname), id(id), balance(0) {

}

void Account::deposit(double amt){
	balance += 3 * amt;
}

ostream& operator <<(ostream& s, const Account& a) {

	return s << a.firstname << " " << a.lastname << " " << a.id << " " << a.balance;
}

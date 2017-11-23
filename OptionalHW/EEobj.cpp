#include<iostream>

using namespace std;

int x;

class Fraction {
private:
	int numerator; //top
	int denominator; //bottom
public:
	Fraction() { numerator = 0; denominator = 1; }
	Fraction(int n, int d) throw(const string) { 
		if ( d == 0) 
			throw "Divide by 0, die!!";
		numerator = n;
		denominator = d;
	}
	// method(object -oriented terminology
	//member function(C++)
	int getNum() const { // read only method have const after the method name.
		return numerator;
	}
	void setNum(int n) { numerator = n; }
	int getDenum() const {
		return denominator;
	}
	void setDenum(int d) { denominator = d; }

	void print() const { //if it is a read only function, must add const!!, or a.print() it will show error
		cout << this->numerator << "/" << this->denominator << endl;
	}

	friend Fraction add(Fraction x, Fraction y);  //add is not in class, we can't use, but we can declare it is friend.
	Fraction add(Fraction y) {
		Fraction ans;
		ans.numerator = numerator * y.denominator + y.numerator * denominator; //denominator is this, who I speak to!  y is another one. 
		ans.denominator = this->denominator * y.denominator; //this
		return ans;
	}
};

Fraction add (Fraction x, Fraction y ) {
	Fraction ans;
	ans.numerator = x.numerator * y.denominator + y.numerator * x.denominator ;
	ans.denominator = x.denominator * y.denominator;
	return ans;
}
// you must declare before you can use
int main() {
	Fraction a; // create an object a of type of Fraction sizeof(Fraction) = 1
	Fraction b[100]; // create an object b of type of Fraction sizeof(Fraction) = 1
	//every object must has at least 1 byte
	//object a and b have diff indenty
	int y;	//create an object y of type of int
	//cout << a.numerator<< "/" << a.denominator << '\n';

	//when memebers are private, you can't use, you need to use memberfunction to read them.
	cout << a.getNum() << "/" << a.getDenum() << '\n';
/*
	//when members are public, you can use	
	for (int i = 0; i < 100; ++i) {
		cout << b[i].numerator << "/" << b[i].denominator << '\n'; // if no intialize, mess
	}
*/
	a.setNum(5);
	cout << a.getNum() << "/" << a.getDenum() << '\n';
/*	Fraction c(1,2);
	cout << c.getNum() << "/" << c.getDenum() << '\n';
*/
	const double pi = 3.1415926; //M_PI in old math library	
	a.print();

	Fraction aa(1,2);
	Fraction bb(1,3);
	aa.print();
	bb.print();
	Fraction cc = add(aa,bb);
	Fraction dd = aa.add(bb);
	cc.print();
	dd.print();
//	Fraction ee = a + b;  // format c

}



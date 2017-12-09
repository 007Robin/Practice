//Xin Song -- Complex (template)
#include<iostream>
#include<math.h>
using namespace std;

template<typename Precision>
class Complex{
	private:
		Precision r, i;
	public:
		Complex(Precision r = 0,  Precision i = 0) : r(r),i(i) {}
		friend Complex operator +(const Complex& c1, const Complex c2){
			return Complex(c1.r + c2.r, c1.i + c2.i);
		}
		friend Complex operator -(const Complex& c1, const Complex c2){
			return Complex(c1.r - c2.r, c1.i - c2.i);
		}
		friend ostream& operator <<(ostream& s, const Complex& c){
			s << c.r << "+" << c.i << "i";
			return s;
		}
		Precision abs(){
			return sqrt(r*r + i*i);
		}
};

int main(){
	Complex<float> a(1.0f, 1.5f);
	Complex<double> b(1.0, 1.5);
	Complex<long double> c(1.0L, 2.5L);

	Complex<double> d(1.5, 1.0);
	Complex<double> e = b + d;
	
	cout << e << '\n';
	cout << a.abs() << '\n'; // compute the absolute value 
	cout << b.abs() << '\n'; // compute the absolute value 
	cout << c.abs() << '\n'; // compute the absolute value
}

//Xin Song -- Complex class
#include<iostream>
#include<math.h>
using namespace std;

class Complex {
	private: 
		double m_real;
		double m_imag;
	public:
		Complex() { m_real = 0.0; m_imag = 0.0;}
		Complex(double real) {
			m_real = real;
			m_imag = 0.0;
		}
		Complex(double real, double imag) {
			m_real = real;
			m_imag = imag;
		}
		//getReal, getImag functions
		double getReal() const {
			return m_real;
		}
		double getImag() const {
			return m_imag;
		}
		//add function
		Complex add(Complex y) {
			Complex ans;
			ans.m_real = this->m_real + y.m_real;
			ans.m_imag = this->m_imag + y.m_imag;
			return ans;
		}
		
		friend Complex operator +(Complex& x, Complex& y);
		friend Complex operator -(Complex& x, Complex& y);
		friend Complex operator *(Complex& x, Complex& y);
		friend Complex operator /(Complex& x, Complex& y);
		friend Complex operator -(Complex& x);
		friend ostream& operator <<(ostream& s, Complex& x);
};
// complex + complex
Complex operator +(Complex& x, Complex& y) {
	Complex ans;
	ans.m_real = x.m_real + y.m_real;
	ans.m_imag = x.m_imag + y.m_imag;
	return ans;
}

//complex - complex
Complex operator -(Complex& x, Complex& y) {
	Complex ans;
	ans.m_real = x.m_real - y.m_real;
	ans.m_imag = x.m_imag - y.m_imag;
	return ans;
}

//complex * complex
Complex operator *(Complex& x, Complex& y) {
	Complex ans;
	ans.m_real = x.m_real * y.m_real - x.m_imag * y.m_imag;
	ans.m_imag = x.m_imag * y.m_real + x.m_real * y.m_imag;
	return ans;
}

//complex / complex
Complex operator /(Complex& x, Complex& y) {
	Complex ans;
	ans.m_real = (x.m_real * y.m_real + x.m_imag * y.m_imag) / (pow(y.m_real, 2) + pow(y.m_imag, 2));
	ans.m_imag = (x.m_imag * y.m_real - x.m_real * y.m_imag) / (pow(y.m_real, 2) + pow(y.m_imag, 2));
	return ans;
}

//-complex
Complex operator -(Complex& x) {
	Complex ans;
	ans.m_real = -1 * x.m_real;
	ans.m_imag = x.m_imag;
	return ans;
}

ostream& operator <<(ostream& s, Complex& x) {
	s << x.m_real << "+" << x.m_imag << "i" ;
	return s;	
}

int main() {
	Complex c1(1.5,2.0);
	Complex c2(-1.3); // -1.3 + 0.0i
	Complex c5;  // 0+0i
	Complex c3 = c1 + c2;
	Complex c4 = -c1; // unary operator has only one parameter
	cout << c1 << c3 << c4 << '\n';
	cout << c5;
	cout << '\n';
}

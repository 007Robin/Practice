//Xin Song -- Complex class
#include<iostream>
using namespace std;

class Complex {
	private: 
		double m_real;
		double m_imag;
	public:
		Complex() { m_real = 0.0; m_imag = 0.0;}
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
		//print funtion
		void print() const {
			cout << this->m_real << "+" << this->m_imag << "i ";
		}
		//add function
		Complex add(Complex y) {
			Complex ans;
			ans.m_real = this->m_real + y.m_real;
			ans.m_imag = this->m_imag + y.m_imag;
			return ans;
		}
};

int main() {
	Complex c1(1.0, 2.5); // real=1.0, imag = 2.5
	Complex c2(2.0, 1.5);
	const Complex c3 = c1.add(c2);  // add two complex numbers
	c3.print(); cout << "\n";
	cout << c3.getReal() << ", " << c3.getImag();
}

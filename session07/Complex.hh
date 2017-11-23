#pragma once
#include<iostream>
#include<cmath>

class Complex{
	private: 
		double r,i; // instance varibles(1 per object)
		static int count; // turns into extern int Complex::count; (project only 1, clare in Complex.cc)
	public:
		Complex(double r = 0, double i = 0) : r(r), i(i) {

		}
		~Complex() {
			count--;
		}
		Complex(const Complex& orig){
			count++;
		}
		operator =(const Complex& orig) {

		}
		friend Complex operator +(const Complex& a, const Complex& b) {
		 	return Complex(a.r + b.r, a.i + b.i);
		}
		Complex operator+(const Complex a){
			return Complex(r + a.r, i + a.i);
		}
		//unary 1method recommend
		friend Complex operator -(const Complex& a) {
		 	return Complex(-b.r, -a.i);
		}
		/*
		//unary 2method 
		Complex operator-() const{
			return Complex(-r, -i);
		}
		*/
		double abs() const{
			return std::sqrt(r*r + i*i);
		}
		friend std::ostream& operator <<(std::ostream& s, const Complex& c) {
			return s << '('  << c.r << ',' << c.i << ')';
		}
};

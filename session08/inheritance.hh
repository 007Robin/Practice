#pragma once
#include<iostream>
#include<string>
using namespace std;

class base {
	public:
		string name() { return basename;}
		virtual void print(ostream &os) { os << basename << endl; }
	private:
		string basename;
};
class derived : public base {
	public:
		void print(ostream &os) override { base::print(os); os << "derived\n " << i; }
	private:
		int i;
};

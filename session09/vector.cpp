#include<iostream>
#include<string>
template<typename T>
void swap(T& a, T& b) {
	T temp = b;
	b = a;
	b = temp;
}

using namespace std;

int main() {
	string a, b;
	swap(a, b);

	int d, e;
	swap(d, e);
	
}

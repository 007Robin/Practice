#include<iostream>
#include<vector>
#include<string>

using namespace std;

template<typename T, unsigned N>
T* start(T (&v)[N]){
	return v;
}
template<typename T, unsigned N>
T* last(T (&v)[N]){
	return v + N - 1;
}

int main(){
	int v[4] = {9,5,1,9};
	cout << *start(v) << " ";
	cout << *last(v) << " ";
	cout << endl;
	double s[5] = {9.01, 5.01, 1.01, 2.011, 6.7};
	cout << *start(s) << " ";
	cout << *last(s) << " ";
}

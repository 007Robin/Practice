#include<iostream>
#include<vector>
#include<string>

using namespace std;
//T is type parameter
//N is nontype parameter, a value. It can be int, pointer, rvalue reference... 
//passing N must be a const value, like 4 in v[4], 5 in s[5] <--> const expression

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
	
	cout << '\n';
	
	double s[5] = {9.01, 5.01, 1.01, 2.011, 6.7};
	cout << *start(s) << " ";
	cout << *last(s) << " ";
}

#include<iostream>
#include<string>
using namespace std;

template<typename T>
//int find(int x[], int target, int n )
int find(T x[], T target, int n ) {
	for(int i = 0; i < n; i++){
		if(x[i] == target){
			return i ;
		}
	}
	return -1;
}

int main() {
	int x[]={1,3,6,8,2,6,8,9};
	cout << find(x, 6, sizeof(x)/sizeof(x[0])) << endl;

	string y[] = {"dog", "pig", "apple", "hello"};
	cout << find(y, string("apple"), sizeof(y)/sizeof(y[0])) << endl; //"apple" is a char* , string"apple" is string
}

#include<string>
#include<iostream>
using namespace std;

template<typename T>
int compare(const T& t1, const T& t2){
	if (t1 < t2) return -1;
	if (t2 < t1) return 1;
	return 0;

}

int main(){
	cout << compare(10, 5);	
	cout << compare(1.98, 5.082);	
	cout << compare(string("or"), string("or"));	
}

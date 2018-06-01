#include<iostream>
#include<string>
using namespace std;

template<typename SuperArray>
void print(const SuperArray& arr){
	for(const auto& e : arr)
		cout << e << endl;
}

int main(){
	int A[5] = {1,5,7,8,0};
	print(A);
	double B[3] = {9.4, 5.6, 1.1};
	print(B);

}

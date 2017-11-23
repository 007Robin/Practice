//Xin Song -- Functions
#include<iostream>
#include<math.h>
using namespace std;

//loop n factorial
double fact(double n) {
	double ans = 1;
	while(n > 0){
		ans *= n;
		n--;
	}
	return ans;
}

//recursion n factorial
double fact2(double n) {
	if (n <= 0)
	{
		cout << "n should be a positive number\n";
		return 0;
	}
	if (n == 1)
	{
		return 1;
	}
	double ans = n * fact2(n - 1);
	return ans;
}

//loop fibonacci
int fibo(int n){
	if (n <= 2)
	{
		return 1;
	}
	int before_before = 1;
	int before = 1;
	int current = 2;
	int start = 3;
	while (start <= n)
	{
		current = before_before + before;
		before_before = before;
		before = current;
		++start;
	}
	return current;
}

//recursion fibonacci
int fibo2(int n) {
	if(n <= 0) return 0;
	if(n == 1) return 1;
	if(n == 2) return 1;
	return fibo2(n - 2) + fibo2(n - 1);
}

//choose
double choose(double n, double r) {
	return fact2(n) / (fact2(r) * fact2(n - r));
}

int main() {
	cout << fact(5) << ' ' << fact2(5) << '\n';
	cout << fact(15) << ' ' << fact2(15) << '\n';
	cout << fibo(5) << ' ' << fibo2(5) << '\n';
	cout << fibo(13) << ' ' << fibo2(13) << '\n';
	cout << choose(52,6) << '\n';
}

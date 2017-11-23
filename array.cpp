#include<iostream>
using namespace std;

int main() {
	const int SIZE = 10;
	int b[SIZE] = {0};
	for(int i = 0; i < SIZE; i++)
		b[i] = i;
	for (int i = 0; i < sizeof(b)/sizeof(int); i++)
		b[i] = SIZE - i;

	
}

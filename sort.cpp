#include <iostream>
using namespace std;
//int*const p = ...;


//  8 7 6 5 4 3 2 1
//  7 6 5 4 3 2 1 8



void sort(int* const items, int n) {		//items is a const pointer, to int
	for (int j = 0; j < n-1; j++) {
		for (int i = 0; i < n-1; i++) {
			if (items[i] > items[i+1]) {
				int temp = items[i];
				items[i] = items[i+1];
				items[i+1] = temp;
				//one varible swap two things. eg: 5,6
				//	items[i] = items[i] + items[i+1];  //11           
				//	items[i+1] = items[i] - items[i+1];//5
				//	items[i] = items[i] - items[i+1]; //11-5 = 6
			}
		}
	}
}

void print(int a[], int n) {		//a is an array const pointer, to int
	for (int i = 0; i < n; i++) {
		cout << a[i] << ' ';
	}
	cout << '\n';
}

int main()  {
	int a[] = { 3, 2, 1};
	sort(a, 3);
	print(a, 3);

	int b[] = {5, 2, 4, 1, 6};
	sort(b, sizeof(b)/sizeof(b[0]));
	print (b, sizeof(b)/sizeof(b[0]));
}




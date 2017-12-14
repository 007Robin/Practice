//Xin Song -- 2.Template sorting function
#include<iostream>
using namespace std;

template<typename T>
void bubblesort(T* const items, int n) {
	for (int j = 0; j < n-1; j++) {
		for (int i = 0; i < n-1; i++) {
			if (items[i] > items[i+1]) {
				swap(items[i], items[i+1]);
				//5,6
				//			items[i] = items[i] + items[i+1];  //11           
				//			items[i+1] = items[i] - items[i+1];//5
				//			items[i] = items[i] - items[i+1]; //11-5 = 6
			}
		}
	}
}

template <typename T, typename Key>
void bubblesort(T x[], Key T::*key, int n){  //key is a pointer to members of T, its type is Key
	// Key T::*key: inside class T, there is a pointer, to something of type Key
	for(int j = 0; j < n -1; j++){
		for(int i = 0; i < n -1; i++){
			//if key is the name, it is .name; if is the age, it is .age . (*key) is a pointer to members of T
			if(x[i].*key > x[i+1].*key)  //.* says look inside (x[i].*) at whatever key ispoint to, look inside (x[i+1].*) at whatever key is point to, compare those things.
				swap(x[i], x[i+1]);
		}
	}
}


template <typename T>
void print(T x[], int n){
	for(int i = 0; i < n; i++)
		cout << x[i] << " ";
	cout << endl;
}

class Elephant{
	//private:
	public:
		string name;	//first byte in the object
		int age;	
	public:
		Elephant(const string name, const int age) : name(name), age(age) {}

		friend bool operator >(const Elephant& e1, const Elephant& e2){
			if(e1.age > e2.age)			//if(e1.name > e2.name)
				return true;
			else 
				return false;
		}
		
		friend ostream& operator <<(ostream& s, const Elephant& e){
			s << "Elephant " << e.name << "'s age is " << e.age << ". ";
			return s;
		}
};

int main() {
	int x[] = {1,2,3,4,5};
	bubblesort(x, 5);
	print(x, 5);
	
	int y[] = {6,2,1,4,5};
	bubblesort(y, 5);
	print(y, 5);
	
	string  s[] = {"adf","egh","hty","cdef","bed"};
	bubblesort(s, 5);
	print(s, 5);

	Elephant e[] = {Elephant("alice", 20), Elephant("ferd", 22), Elephant("gerge", 19) }; 
	bubblesort(e, &Elephant::age , 3); //my address is inside class Elephant, I want the age
	//this class Elephant must match the class e, which is Elephant. 
	print(e, 3);

	bubblesort(e, &Elephant::name, 3);
	print(e,3);
}


//Xin Song -- Template sorting function
#include<iostream>
using namespace std;

template <typename T>
void bubblesort(T x[], int n){
	for(int j = 0; j < n -1; j++){
		for(int i = 0; i < n -1; i++){
			if(x[i] > x[i+1])
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
	private:
		string name;
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
	bubblesort(e, 3);
	print(e, 3);

}


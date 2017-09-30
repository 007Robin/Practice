#include<iostream>
#include<cstdint>
using namespace std;

class  String{
	private:
		char* p; // p is point to letters char(*p)
		uint32_t len; //length of letters
		uint32_t capacity; //
	
	public:
		String (const char s[]) { // s can point everywhere but not change letters
			//strlen
			// count how many letters until ASCII NUL '\0'
			// > < >= <= == !=
			int i;
			for(i = 0; s[i] != '\0'; ++i)
			;
			p = new char[i]; //i+1 keep the '\0', but now we keep only letters --- dynamically allocates i contiguous memeory 
			len = i;
			capacity = i;
			for( int j = 0; j < len; j++)
				p[j] = s[j]; 
		}
		
		String () {
			p = new char [1];
			len = 0;
			capacity = 1;
		}

		
   		// String s3("abc", 5); // abcabcabcabcabc
		String (const char s2[], int ct) {
			
			int i;
			for(i = 0; s2[i] != '\0'; ++i)
			;
			p = new char[i * ct]; //i+1 keep the '\0', but now we keep only letters --- dynamically allocates i contiguous memeory 
			len = i * ct;
			capacity = i * ct;
			int x = 0;
			for(int j = 0; j < len; j++){
				p[j] = s2[x];
				if(x < i) {
					x++;
				}
				if(x == 2) {
					x = 0;
				}
			}
		}
				
		//copy constructor  --- String s5(s3);
		String(const String& orig) : p(new char[orig.capacity]), len(orig.len), capacity(orig.capacity) { // use another way -- : variable-name(initialization) --  initialize constructor
			for(uint32_t i = 0; i < orig.len; ++i) {
				p[i] = orig.p[i];

			}
		}
		//copy constructor  --- String s5 = s3;
		String& operator = (const String& orig) {
		//	delete [] p;
			String copy(orig); 
			swap(copy.p, p);
			len = orig.len;
			capacity = orig.capacity;
			//swap(copy.len, len);
			//swap(copy.capacity, capacity);
		}
		
		//void print() const {} 	another way	we do outside
		
		//void clear() {...}
		//destructor automaticly give back memery . a object only live in {}
		~String() {
			delete [] p;
		}
		friend ostream& operator <<(ostream& s, const String& str);  //goint to look at you but don't change you
		friend String operator +(const String& a, const String& b);
};
//1. simply statement use ;
//2. declartion use ;

//void print (ostream& s, const String$ str) { //goint to look at you but don't change you --> print(cout, s1);
ostream& operator <<(ostream& s, const String& str) { //goint to look at you but don't change you. return String what you give, so change void to ostream&
	for(uint32_t i = 0; i < str.len; ++i)
		s << str.p[i]; //goin to the object to use its p 
	return s;
}


String operator +(const String& a, const String& b) {
	String result;
	result.len = a.len + b.len;
	result.p = new char[result.len];
	result.capacity = result.len;
	for(uint32_t i = 0; i < a.len; i++) {
		result.p[i] = a.p[i];
	}
	for(uint32_t i = a.len; i < result.len; i++) {
		result.p[i] = b.p[i - a.len];
	}
	return result;
}

// def --> array 'd' 'e' 'f' '\0'
int main () {
	String s1("def");
	String s2; //empty string
	cout << s1 << endl; //def
	cout << s2 << endl;;  //print nothing
	
    String s3("abc", 5); // abcabcabcabcabc
	cout << s3 << endl;
	String s4 = s3; //make a copy (call copy constructor)
	String s5(s3); // same call copy constructor 
	cout << s4 << endl;
	cout << s5 << endl;
	s4 = s1; //operator =, first deallocate what was there in s4 before it copy
	cout << s4 << endl;
	String s6 = s4 + s1; //connection
	cout << s6;
 
}

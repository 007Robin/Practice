#include "BitVec.hh"

//Bitvec primes(1000000000); // 1 billion bytes is big!  125Mb is a lot better

//0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000

class BitVec {
	private:
		uint64_t* bits;
		uint32_t size;
	public:
		BitVec(uint32_t size) : bits(new uint64_t[(size+63)/64]){
		//I want 65 bits, your bits is (65+63)/64 = 2. I want 3 bits, yours is (3+63)/64 = 1 
		}
		// constructor, destructor, copy constructor, operator = ...
		void set(uint32_t index) {}
		void clear(uint32_t index) {}
		void toggle(uint32_t index) {}
		bool isSet(uint32_t index) {}

};

//BitVec<1000000> b2;
//Stack<256> s;
int main() {
	const int n = 1000000;
	BitVec b(n);
	for (int i = 0; i < n; i += 17)
		b.set(i);
	for (int i = 0; i < n; i += 19)
		b.set(i);
	for (int i = 0; i < n; i++)
		b.toggle(i);
	for (int i = 0; i < n; i++)
		if (!b.isSet(i) && i % 4 == 0 && i % 21)
			cout << i << ' ';
	cout << '\n';
}

/*
   bit 0 is the rightmost bit
   000000000000000000000000000000000000000000000000000000000

   000000000000000000000000000000000000000000000000000000001
   if you want the bit k, use
   1 << k
   1 << 3
   000000000000000000000000000000000000000000000000000001000

   if you want to set X to 1, use OR (1 << k)
   1010101010111110000111110101010101X1010101010101001010101
   000000000000000000000000000000000010000000000000000000000
OR 101010101011111000011111010101010111010101010101001010101

   //set location k to 1
   x  = x | (1 << k)     x |= 1 << k

   HOW TO DO THIS with an array?
   bit = 100000; // how to split this into which word, which bit within?
   i = bit / 64
   k = bit % 64

   x[ i ] |= 1 << k

   10000000000 = 1024     / 64 = 16
   >> 6
   10000 = 16      
   i = 16, k = 0

   64 = 1000000		63 = 0111111

   10000000000
AND00000111111
k= 00000000000

   10000000011 = 1027   
AND00000111111
k= 00000000011 = 3
   i = 16, k = 3

   x[ind >> 6] |= 1 << (ind & 63)


   &   ~(1 << k)  CLEAR

   ^    (1 << k)  TOGGLE

   test    return (bits[i] & (1 << k)) != 0   true or false
 */
/*
int main() {
	int a = 3 & 5; // bitwise AND      0000000011 & 00000000101
	//  00000000011
	//	00000000101
	//=============
	//  00000000001 = 1
	int b = 3 | 5; // bitwise OR
	//  00000000011
	//	00000000101
	//=============
	//  00000000111 = 7

	int c = 3 ^ 5; // bitwise XOR
	//  00000000011
	//	00000000101
	//=============
	//  00000000110 = 6


	int d = ~3;    // NOT
	//00000000000000000000000000000011
	//11111111111111111111111111111100

	int e = 1 << 5; // left shift  equivalent to mult by 2 to the k
	// 00000000000000000000001
	// 00000000000000000100000 // 32


	// 50  ==> 500

	int f = 1024 >> 3; // right shift  equivalent to / 2 to the k
	// 0000000000010000000000 = 1024
	// 0000000000000010000000 = 128 = 2 to the 7
	int g = 5;

	g <<= 2;

	// there are 12 op= types    += -= *= /= %= &= |= ^= <<= >>=
	// x = x OP y   ==>  x OP= y
	int x = 192;
	const int m = 16*1024*1024/3;
	x /= 3; // compiler might do: x * m >> 24

}
*/

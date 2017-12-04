#include<iostream>
#include<fstream>
using namespace std;

int main(){
	ofstream f("test.dat");
	char buffer[8192];//8k bytes
	strncpy(buffer, "This is our class heaeder... writing STL file", 80);
	//how many triangles in your world?? a function can tell
	//&buffer[80] buffer+80
	//
	uint32_t x = 5; //Big edian(low in end): 0 0 0 5    Little edian (low in front): 5 0 0 0 
	//how much does 1 byte hold?  8 bits = 00000111 2^8 = 256
	uint32_t length = 1605;
	//
	buffer[80] = length & 0xFF; //get rightmost 8 bits
	buffer[81] = (length >> 8) & 0xFF ; //get rightmost 8 bits, divide by 2^8
	buffer[82] = (length >> 16) & 0xFF ; //divide by 65536
	buffer[83] = (length >> 24) & 0xFF ; //divide by 
/*
everything &0 will return 0
&0 -> 0
&1 -> origin
   */
/*
	buffer[80] = length % 256; //get rightmost 8 bits
	buffer[81] = length / 256 % 256; //
	buffer[82] = length / (256*256) % 256; //
	buffer[83] = length / (256*256*256) % 256; //
*/
	*((uint32_t*)(buffer+80)) = length;	
	float* p = buffer+84;
	Vector3d v(1.0, 2.0, 3.0);
	float x = float(v.x); //(float)(v.x) old way
	float y = float(v.y); //new C++ notation
	float z = float(v.z);
   
	//do this 4 times
	*p = x;
	p++; //4
	*p = y;
	p++;  //8
	*p = z;
	p++; //12 we are at byte 96 = 84 + 12


	//len = ???
	f.write(buffer,len);
}

/*
3bits unsigned int

x / 2 --> chops off rightmost bit
x % 2 --> returns the rightmost bit

8   10000   %4 -> return the rightmost 2 bits

x % 2^n  --> returns rightmost n bits
in decimal 987
987/10 -> 97
987%10 -> 7

   */

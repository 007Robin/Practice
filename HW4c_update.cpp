//Xin Song -- Bitmap
#include<iostream>
#include<iomanip>

using namespace std;

class Bitmap {
	private:
		uint32_t* rgba;
		uint32_t rows,cols;
	public:
		//constructor
		Bitmap() {
			rows = 0; 
			cols = 0;
			rgba = new uint32_t[1];
		}
		Bitmap(uint32_t r, uint32_t c) {
			rows = r;
			cols = c;
			rgba = new uint32_t[rows * cols];
			for(uint32_t i = 0; i < rows * cols; ++i){
				rgba[i] = 0;
			}
		}
		//copy constructor
		Bitmap(const Bitmap& bt) : rgba(new uint32_t[bt.rows * bt.cols]), rows(bt.rows), cols(bt.cols) {
			for(uint32_t i = 0; i < rows * cols; ++i) {
				rgba[i] = bt.rgba[i] ;
			}
		}
		//copy assignment operator
		Bitmap& operator =(const Bitmap& bt) {
			rows = bt.rows;
			cols = bt.cols;
			rgba = new uint32_t[rows * cols];
			for(uint32_t i = 0; i < rows * cols; ++i) {
				rgba[i] = bt.rgba[i];
			}
			return *this;
		}

		//destructor
		~Bitmap() {
			delete [] rgba;
		}


		void horizLine(uint32_t x1, uint32_t x2, uint32_t y, uint32_t rgb) {
			for(int i = x1; i <= x2; ++i) {
				rgba[i + cols * y] = rgb;
			}
		}
		
		void vertLine(uint32_t y1, uint32_t y2, uint32_t x, uint32_t rgb) {
			for(int i = y1; i < y2; ++i) {
				rgba[x + cols * i] = rgb;
			}
		}
		
		friend ostream& operator <<(ostream& s, const Bitmap& bt);
};


ostream& operator <<(ostream& s, const Bitmap& bt) {
	int j = 0;
	for( int i = 0; i < bt.rows * bt.cols; ++i) {
		if(j < bt.cols) {
//		s << (((bt.rgba[i]) & 0xFF000000) >> 24) << "," << (((bt.rgba[i]) & 0x00FF0000) >> 16) << "," << (((bt.rgba[i]) & 0x0000FF00) >> 8);
			s << (((bt.rgba[i]) & 0x00FF0000) >> 16) << "," << (((bt.rgba[i]) & 0x0000FF00) >> 8) << "," << (((bt.rgba[i]) & 0x000000FF));
			s << setw(4);
			j++;
		}
		if(j == bt.cols) {
			s << '\n';
			j = 0;
		}
	}
	return s;
}

int main() {
	Bitmap b1(3,5); // rows,cols or y,x (NOT x,y)
	cout << b1;
	/*
	   r,g,b   rgb = ((r*256 + g)*256 + b
	   this is the same as:
	   rgb = ((r << 8) + g) << 8) + b
	   use setw(4) in iomanip
	   0,0,0     0,0,0   255,0,255    0,0,0   255,0,0
	   0,0,0     0,0,0   255,0,255    0,0,0   255,0,0
	   0,0,0     0,0,0   255,0,255    0,0,0   255,0,0
	 */

    Bitmap b2(10,20);
	b2.horizLine(3, 15, 0, 0xFF00FF); // go from (3,0) to (15,0) writing color
//	cout << b2;
	b2.vertLine(0, 8, 0, 0x000100);// go from (0,0) to (0,8) writing color
//	cout << b2;
}

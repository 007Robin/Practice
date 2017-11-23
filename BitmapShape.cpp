//Xin Song -- Bitmap includes horizLine, vertLine, line, drawEllipse, fillEllipse, drawRect
#include<iostream>
#include<iomanip>
#include<math.h>
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

		void line(uint32_t x0, uint32_t y0, uint32_t x1, uint32_t y1, uint32_t rgb){
			double k = (x1 - x0) / (y1 - y0);
			double error = 0.0;
			uint32_t y = y0;
			for(uint32_t x = x0; x < x1; ++x) {
				rgba[x + cols * y] = rgb;
				error = error + k;
				if (error >= 0.5) {
					y++;
					error = error - 1.0;
				}
			}
		}
		int  floor(double x) {
			if(x - (int)x >= 0.5) return (int)x + 1;
			return (int)x;
		}
		void drawEllipse(int x0, int y0, int a, int b, uint32_t rgb){
			double y1 = 0, y2 = 0; 
			for(int x = x0 - a/2; x <= x0 + a/2; ++x){
				y1 = -sqrt(b*b/4.0 - (b*b/4.0)*(x - y0)*(x - y0)/(a*a/4.0)) + x0;
				y2 = sqrt(b*b/4.0 - (b*b/4.0)*(x - y0)*(x - y0)/(a*a/4.0)) + x0;
					int y11 = floor(y1);
					rgba[x + cols * y11] = rgb;
					int y22 = floor(y2);
					rgba[x + cols * y22] = rgb;
			}
		}

		void fillEllipse(int x0, int y0, int a, int b, uint32_t rgb){
			double y1 = 0, y2 = 0; 
			for(int x = x0 - a/2; x <= x0 + a/2; ++x){
				y1 = -sqrt(b*b/4.0 - (b*b/4.0)*(x - y0)*(x - y0)/(a*a/4.0)) + x0;
				y2 = sqrt(b*b/4.0 - (b*b/4.0)*(x - y0)*(x - y0)/(a*a/4.0)) + x0;
					int y11 = floor(y1);
					int y22 = floor(y2);
					for( int y = y11 + 1; y < y22; y++) {
						rgba[x + cols * y] = rgb;
					}
			}
		
		
		}
		void drawRect(uint32_t x0, uint32_t y0, uint32_t width, uint32_t height, uint32_t rgb){
			horizLine(x0, x0 + width, y0, rgb);
			horizLine(x0, x0 + width, y0 + height, rgb);
			vertLine(y0, y0 + height, x0, rgb);
			vertLine(y0, y0 + height, x0 + width, rgb);
		}
};


ostream& operator <<(ostream& s, const Bitmap& bt) {
	int j = 0;
	for( int i = 0; i < bt.rows * bt.cols; ++i) {
		if(j < bt.cols) {
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
	const uint32_t RED = 0xFF0000;
	const uint32_t GREEN = 0x00FF00;
	const uint32_t BLUE = 0x0000FF;

	Bitmap b(18,18); // all pixels = 0,0,0,0
	b.horizLine(0, 3, 0, RED); // from x=0 to x=300 at y = 0
	b.vertLine(0, 2, 3, BLUE); // from y=0 to y=200 at x = 300
	b.line(0,0, 4, 3, GREEN);  //https://en.wikipedia.org/wiki/Bresenham's_line_algorithm
	//	b.antialiasedLine(0,200, 400,300, 0xFFFF00); // OPTIONAL https://en.wikipedia.org/wiki/Xiaolin_Wu%27s_line_algorithm

	b.drawEllipse(9, 9, 12, 12, RED);    // create an ellipse centered (500,500)
	cout << b;

	b.fillEllipse(9, 9, 12, 12, GREEN);    // create an ellipse centered (500,500)

	b.drawRect(7, 6, 5, 5, RED); // draw outline rectangle
	cout <<b;
	//TODO: Next week!!
	//    b.fill(720,605, 0x0000FF);

}


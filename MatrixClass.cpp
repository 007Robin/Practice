//Xin Song --- Matrix
#include<iostream>
using namespace std;

class Matrix 
{
	double* m;
	uint32_t rows, cols;
public:
	//constructor
	Matrix(uint32_t r, uint32_t c) {
		rows = r;
		cols = c;
		m = new double[rows * cols];
		for(uint32_t i = 0; i < rows * cols; ++i) {
			m[i] = 0.0;
		}	
	}
	Matrix(uint32_t r, uint32_t c, double val) {
		rows = r;
		cols = c;
		m = new double[rows * cols];
		for(uint32_t i = 0; i < rows * cols; ++i) {
			m[i] = val;
		}
	}
	Matrix() {
		m = new double[1];
		rows = 0;
		cols = 0;
	}
	//constructor, destructor, copy constructor, operator =
    /*
		0 1  2  3
		4 5  6  7
		8 9 10 11
	   */
	
	//index function
	double operator ()(uint32_t r, uint32_t c) const {
		return m[r*cols + c];
	}
	double& operator ()(uint32_t r, uint32_t c) {
		return m[r*cols + c];
	}
	
	//copy constructor
	Matrix (const Matrix& orig): m(new double[orig.rows * orig.cols]), rows(orig.rows), cols(orig.cols) {
		for(uint32_t i = 0; i < rows * cols; ++i) {
			m[i] = orig.m[i];
		}
	}
	
	//copy assignment operator
	Matrix& operator =(const Matrix& orig){
		rows = orig.rows;
		cols = orig.cols;
		m = new double[rows * cols];
		for(uint32_t i = 0; i < rows * cols; ++i) {
			m[i] = orig.m[i];
		}
		return *this;
	}

	//destructor
	~Matrix () {
		delete [] m;
	}
	friend ostream& operator <<(ostream&, const Matrix& m);
	friend Matrix operator +(const Matrix& a, const Matrix& b);
	friend Matrix operator -(const Matrix& a, const Matrix& b);
	friend Matrix operator *(const Matrix& a, const Matrix& b);
};

ostream& operator <<(ostream& s, const Matrix& mtr) {
	int j = 0;
	for( int i = 0; i < mtr.rows * mtr.cols; ++i) {
		if(j < mtr.cols) {
			s << mtr.m[i];
			s << "   ";
			j++;
		}
		if(j == mtr.cols) { 
			s << '\n';
			j = 0;
		}
	}
	return s;
}
// Matrix + operator
Matrix operator +(const Matrix& a, const Matrix& b) {
	if(a.rows == b.rows && a.cols == b.cols) {
		Matrix result(a.rows, b.cols);
		for( uint32_t r = 0; r < a.rows; ++r) {
			for (uint32_t c = 0; c < a.cols; ++c) {
				result(r,c) = a(r,c) + b(r,c);
			}
		}
		return result;
	}
	return Matrix();
}
//Matrix - operator
Matrix operator -(const Matrix& a, const Matrix& b) {
	if(a.rows == b.rows && a.cols == b.cols) {
		Matrix result(a.rows, b.cols);
		for( uint32_t r = 0; r < a.rows; ++r) {
			for (uint32_t c = 0; c < a.cols; ++c) {
				result(r,c) = a(r,c) - b(r,c);
			}
		}
		return result;
	}
	return Matrix();
}
//Matrix * operator
Matrix operator *(const Matrix& a, const Matrix& b) {
	if( a.rows == b.cols && a.cols == b.rows) {
		Matrix result(a.rows, b.cols);	
		for (int i = 0; i < a.rows; i ++) {
			for (int k = 0; k < a.cols; k++) {
				if(a(i, k) != 0) {
					for (int j = 0 ; j < b.cols; j++) {
						result(i, j) += (a(i, k) * b(k, j));    
					}
				}
			}
		}
		return result;
	}
	return Matrix();
}

int main() {
	Matrix a(3,4, 5.2); // create 3 rows of 4 columns containing 5.2
	Matrix b(3,4); // defaults to 0.0
	cout << a << '\n';
	/*
	   5.2 5.2 5.2 5.2
	   5.2 5.2 5.2 5.2
	   5.2 5.2 5.2 5.2
	 */

	Matrix c(3,4,1.2);
	cout << c(2,2);
	c(0,0) = -1.5;
	/*
	   c=
	   -1.5 1.2 1.2 1.2
	   1.2 1.2 1.2 1.2
	   1.2 1.2 1.2 1.2
	 */
	Matrix d = a + c;
	/*
	   3.7 6.4 6.4 6.4
	   6.4 6.4 6.4 6.4
	   6.4 6.4 6.4 6.4
	 */
	cout << d;
	Matrix e = a - c;
	//optional
	Matrix f(4,3,1.5);
	Matrix g = f * b; // matrix multiplication
}

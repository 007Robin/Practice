//Xin Song 
#include<iostream>
#include<vector>
using namespace std;

class Badsize{
	private:
		const char* filename;
		int linenum;
	public:
		Badsize(const char filename[], int linenum) : filename(filename), linenum(linenum) {}
		friend ostream& operator <<(ostream& s, const Badsize& b ) {
			return s << "Badsize.filename: " <<  b.filename << " linenum: "<<  b.linenum << endl;
		}
};

class Matrix {
	double* m; //double** will be slow and complex
	uint32_t rows, cols; 
public:
	//constructor
	Matrix(uint32_t r, uint32_t c, double val = 0) {
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

	double& operator ()(int i, int j) {
		return  m[i * cols + j]; 	
	}
	double operator ()(int i, int j) const {
		return  m[i * cols + j]; 	
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

	friend Matrix operator +(const Matrix& a, const Matrix& b) {
		if( a.rows != b.rows || a.cols != b.cols) {
		//cerr << "AAAAAAAAHHH"
		//	throw "AAGH"; 
			throw Badsize(__FILE__, __LINE__); //__ is belong to c++ MUST c++
		}
		else {
			Matrix result(a.rows, b.cols);
			for( uint32_t r = 0; r < a.rows; ++r) {
				for (uint32_t c = 0; c < a.cols; ++c) {
					result(r,c) = a(r,c) + b(r,c);
				}
			}
			return result;
		}
	}
};

ostream& operator <<(ostream& s, const Matrix& mtr) {
	int j = 0;
	for( int i = 0; i < mtr.rows * mtr.cols; ++i) {
		if(j < mtr.cols) {
			s << mtr.m[i];
			s << ' ' << ' ' << ' ';
			j++;
		}
		if(j == mtr.cols) { 
			s << '\n';
			j = 0;
		}
	}
	return s;
}


int main() {

	Matrix a(3, 4, 5.2); // create 3 rows of 4 cols containing 5.2
	Matrix b(3, 4); // 0.0 default
	cout << a << '\n';
	
	const Matrix m2(4, 4);
	cout << Matrix(1, 1);
	
	try {
		Matrix m3 = a + m2;

	} catch( const Badsize& e) {
		cout << e << '\n';
	}

/*	Matrix a;
	ifstream f("hw6.dat"); 
	f >> a;
	vector<double> B;
	f >> B;
	
	a.solve(x, B) // solve Ax = B
	
	cout << x;
*/	/*
	3 
	1 2 1
	1 -1 1
	-2 1 1

	5
	4
	3
	   */
	
	/*
		5.2 5.2 5.2 5.2 
		5.2 5.2 5.2 5.2 
		5.2 5.2 5.2 5.2 

	*/
/*	Matrix c(3, 4, 1.2);
	cout << c(2,2); // call the copy read-only one
	c(0,0) = -1.5; // call the & one
	Matrix d = a + c;
	cout << d;
	Matrix e = a - c;

	//optional
	Matrix f(4, 3, 1.5);
	Matrix g = f * b;
*/
}

//Xin Song --- Vec3D
#include<iostream>
#include<math.h>
using namespace std;

class Vec3d {
//	private:
	public:
		double x,y,z;
	public :
		//constructor
		Vec3d(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {
		}
		
		//copy constructor
		Vec3d(const Vec3d& orig) : x(orig.x), y(orig.y), z(orig.z) {
		
		}
	
		//copy assignment operator
		Vec3d& operator =(const Vec3d& orig) {
			x = orig.x;
			y = orig.y;
			z = orig.z;
			return *this;
		}
		
		//destructor
		~Vec3d() {
		}

		friend ostream& operator <<(ostream& s, const Vec3d& v);
		friend Vec3d operator +(const Vec3d& v1, const Vec3d& v2);
		friend Vec3d operator -(const Vec3d& v1, const Vec3d& v2);
		friend Vec3d operator *(const Vec3d& vec, double m);		
		friend Vec3d operator *(double n, const Vec3d& vec);		
        friend double dot(Vec3d& a, Vec3d& b);
        friend double dist(Vec3d& a, Vec3d& b);
		friend Vec3d get_Normal(const Vec3d& p1, const Vec3d& p2, const Vec3d& p3 ){  
			double a = ( (p2.y-p1.y)*(p3.z-p1.z)-(p2.z-p1.z)*(p3.y-p1.y) );  
			double b = ( (p2.z-p1.z)*(p3.x-p1.x)-(p2.x-p1.x)*(p3.z-p1.z) );  
			double c = ( (p2.x-p1.x)*(p3.y-p1.y)-(p2.y-p1.y)*(p3.x-p1.x) );  
			return Vec3d(a,b,c);  
		} 

		double dot(const Vec3d& a) {
			double ans;
			ans = a.x * this->x + a.y * this->y + a.z * this->z;
			return ans;
		}

		double dist(const Vec3d& a) {
			double ans;
			ans = sqrt( pow((a.x - this->x),2) +  pow((a.y - this->y),2) +  pow((a.z - this->z),2) );
			return ans;
		}
};

ostream& operator <<(ostream& s, const Vec3d& v) {
	s << v.x << " " << v.y << " " << v.z;
	return s;
}

Vec3d operator +(const Vec3d& v1, const Vec3d& v2){
	Vec3d ans;
	ans.x = v1.x + v2.x;
	ans.y = v1.y + v2.y;
	ans.z = v1.z + v2.z;
	return ans;
}

Vec3d operator -(const Vec3d& v1, const Vec3d& v2){
	Vec3d ans;
	ans.x = v1.x - v2.x;
	ans.y = v1.y - v2.y;
	ans.z = v1.z - v2.z;
	return ans;
}

Vec3d operator *(const Vec3d& vec, double m) {
	Vec3d ans;
	ans.x = m * vec.x;
	ans.y = m * vec.y;
	ans.z = m * vec.z;
	return ans;
}

Vec3d operator *(double n, const Vec3d& vec) {
	Vec3d ans;
	ans.x = n * vec.x;
	ans.y = n * vec.y;
	ans.z = n * vec.z;
	return ans;
}
	
double dot(Vec3d& a, Vec3d& b) {
	double ans;
	ans = a.x * b.x + a.y * b.y + a.z * b.z;
	return ans;
}

double dist(Vec3d& a, Vec3d& b) {
	double ans;
	ans = sqrt( pow((a.x - b.x),2) +  pow((a.y - b.y),2) +  pow((a.z - b.z),2) );
	return ans;
}

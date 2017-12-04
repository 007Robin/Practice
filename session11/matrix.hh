//#include "vec3D.h"
//#include "Shape.hh"

class Matrix4 {
	private:
		double a,b,c,d;
		double e,f,g,h;
		double i,j,k,m;
	public:
		Matrix4(double a = 1, double b = 0, double c = 0, double d = 0, double e = 0, double f = 1, double g = 0, double h = 0,double i = 0, double j = 0, double k = 1, double m = 0) : a(a), b(b), c(c), d(d), e(e), f(f), g(g), h(h), i(i), j(j), k(k), m(m)  {}
		//no destructor beacuse no dynamic memeory
		//no copy constructor needed 
		//operator= same

		void apply(Vec3d& v) {
			double x = a*v.x + b*v.y + c*v.z + d; // d is translation in the x
			double y = e*v.x + f*v.y + g*v.z + h; // h is translation in the y
			v.z = i*v.x + j*v.y + k*v.z + m; // m is translation in the z
			v.x = x;
			v.y = y;
		}
		//make apply work polymorphically!
		void apply(Shape& s){
			Vec3d c = s.getCenter();
			vector<Vec3d> vlist = s.getVertixes();
			c = c + Vec3d(d,h,m);
			for(auto v : vlist){
				double x = a*v.x + b*v.y + c*v.z + d; // d is translation in the x
				double y = e*v.x + f*v.y + g*v.z + h; // h is translation in the y
				v.z = i*v.x + j*v.y + k*v.z + m; // m is translation in the z
				v.x = x;
				v.y = y;
			}
		}

		Matrix4 scale(Vec3d v){
			 
			 a *= v.x;
			 f *= v.y;
			 k *= v.z;
			 return *this;
		}
		
		Matrix4 translate(Vec3d v){
			
			d += v.x;
			h += v.y;
			m += v.z;
			return *this;
		}

		/*
		   scale(2, 1, 0.5)
		   2 0 0   0
		   0 1 0   0
		   0 0 0.5 0

		   rotateZ
		   cos(t) sin(t)    0  0
		   -sin(t) cost(t)  0  0 
			0      0        1  0

			rotateY
			cos(t)  0 sin(t) 0
			0       1    0   0
			-sin(t) 0 cos(t) 0

			translate(tx, ty, tz)

		  */
};

//Xin Song -- CAD_old

#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include "vec3D.h"
#include<math.h>
using namespace std;

static constexpr double pi = 3.1415926;

class Shape {
//	private: 
	public:
		double x, y, z;
	public:
		Shape(double x = 0, double y = 0, double z = 0): x(x), y(y), z(z) {}
		double getx() {
			return x;	
		}
		double gety() {
			return y;	
		}
		double getz() {
			return z;	
		}
		virtual void write(string fileName) = 0;
		virtual Vec3d getCenter() = 0;
		virtual vector<Vec3d> getVertixes() = 0;
		virtual ~Shape() {}
};

class Cylinder : public Shape{
	private:
		double r,h;
		int facets;
	public:
		Cylinder(double x, double y, double z, double r, double h, int facets) : Shape(x, y, z), r(r), h(h), facets(facets) {
		}
		Vec3d getCenter() override {
			return Vec3d(getx(), gety(), h/2 + getz());
		}
		vector<Vec3d> getVertixes() override {
			vector<Vec3d> vertixes;
			for(int i = 0; i < facets; ++i) {				
				vertixes.push_back(Vec3d (getx() + r*cos(2*pi/facets*(i)), gety() + r*sin(2*pi/facets*(i)), h + getz()));
				vertixes.push_back(Vec3d (getx() + r*cos(2*pi/facets*(i)), gety() + r*sin(2*pi/facets*(i)), getz()));
			}
			return vertixes;
			
		}
		void write(string fileName) override {
			ofstream out(fileName, ofstream::app);
			if(out) {
				Vec3d v1(getx() + r*cos(0), gety() + r*sin(0), h + getz());
				Vec3d v2(getx(), gety(), h + getz());
				Vec3d v3;
				Vec3d v1_d = v1 - Vec3d(0,0,h);
				Vec3d v2_d = v2 - Vec3d(0,0,h);
				Vec3d v3_d;
					for(int i = 0; i < facets; ++i) {				
						v3 = Vec3d (getx() + r*cos(2*pi/facets*(1+i)), gety() + r*sin(2*pi/facets*(1+i)), h + getz());
						//up circle				
						Vec3d f1 = get_Normal(v1, v3, v2);
						out << ' ' << "facet normal " << f1 << endl;
						out << ' ' << ' ' << "outer loop" << endl;
						out << ' ' << ' ' << ' ' << "vertex " << v1 << endl;
						out << ' ' << ' ' << ' ' << "vertex " << v3 << endl;
						out << ' ' << ' ' << ' ' << "vertex " << v2 << endl;
						out << ' ' << ' ' << "endloop" << endl << ' ' << "endfacet" << endl;
						//down circle
						v3_d = v3 - Vec3d(0,0,h);
						Vec3d f2 = get_Normal(v1_d, v2_d, v3_d);
						out << ' ' << "facet normal " << f2 << endl;
						out << ' ' << ' ' << "outer loop" << endl;
						out << ' ' << ' ' << ' ' << "vertex " << v1_d << endl;
						out << ' ' << ' ' << ' ' << "vertex " << v2_d << endl;
						out << ' ' << ' ' << ' ' << "vertex " << v3_d << endl;
						out << ' ' << ' ' << "endloop" << endl << ' ' << "endfacet" << endl;
						//v1 v1_d v3_d
						Vec3d f3 = get_Normal(v1, v1_d, v3);
						out << ' ' << "facet normal " << f3 << endl;
						out << ' ' << ' ' << "outer loop" << endl;
						out << ' ' << ' ' << ' ' << "vertex " << v1 << endl;
						out << ' ' << ' ' << ' ' << "vertex " << v1_d << endl;
						out << ' ' << ' ' << ' ' << "vertex " << v3_d << endl;
						out << ' ' << ' ' << "endloop" << endl << ' ' << "endfacet" << endl;
						//v3_d v3 v1
						Vec3d f4 = get_Normal(v1_d, v3, v3_d);
						out << ' ' << "facet normal " << f4 << endl;
						out << ' ' << ' ' << "outer loop" << endl;
						out << ' ' << ' ' << ' ' << "vertex " << v3_d << endl;
						out << ' ' << ' ' << ' ' << "vertex " << v3 << endl;
						out << ' ' << ' ' << ' ' << "vertex " << v1 << endl;
						out << ' ' << ' ' << "endloop" << endl << ' ' << "endfacet" << endl;

						v1 = v3;
						v1_d = v3_d;
					}	
				out.close();
			}	
		}
};

class Cube : public Shape{
	private:
		double size;
	public:
		Cube(double x, double y, double z, double size) : Shape(x, y, z), size(size) {}
		
		Vec3d getCenter() {
			return Vec3d(getx() + size/2, gety() + size/2, getz() + size/2);	
		}
		vector<Vec3d> getVertixes() {
			vector<Vec3d> vertixes;
			vertixes.push_back(Vec3d (getx(), gety(), getz()));
			vertixes.push_back(Vec3d (getx(), gety() + size, getz()));
			vertixes.push_back(Vec3d (getx() + size, gety() + size, getz()));
			vertixes.push_back(Vec3d (getx() + size, gety(), getz()));
			vertixes.push_back(Vec3d (getx(), gety(), getz() + size));
			vertixes.push_back(Vec3d (getx(), gety() + size, getz() + size));
			vertixes.push_back(Vec3d (getx() + size, gety() + size, getz() + size));
			vertixes.push_back(Vec3d (getx() + size, gety(), getz() + size));
			return vertixes;
		}
		void write(string fileName) override {
			ofstream out(fileName, ofstream::app);
			if(out) {
				Vec3d v1(getx(), gety(), getz());
				Vec3d v2(getx(), gety() + size, getz());
				Vec3d v3(getx() + size, gety() + size, getz());
				Vec3d v4(getx() + size, gety(), getz());
				Vec3d v1_u(getx(), gety(), getz() + size);
				Vec3d v2_u(getx(), gety() + size, getz() + size);
				Vec3d v3_u(getx() + size, gety() + size, getz() + size);
				Vec3d v4_u(getx() + size, gety(), getz() + size);
				Vec3d f;
				for(int i = 0; i < 12; ++i) {
					switch(i) {
						case 0: 
							f = get_Normal(v1,v2,v3);
							out << ' ' << "facet normal " << f << endl;
							out << ' ' << ' ' << "outer loop" << endl;
							out << ' ' << ' ' << ' ' << "vertex " << v1 << endl;
							out << ' ' << ' ' << ' ' << "vertex " << v2 << endl;
							out << ' ' << ' ' << ' ' << "vertex " << v3 << endl;
							out << ' ' << ' ' << "endloop" << endl << ' ' << "endfacet" << endl;
							break;
						case 1:  
							f = get_Normal(v3,v4,v1);
							out << ' ' << "facet normal " << f << endl;
							out << ' ' << ' ' << "outer loop" << endl;
							out << ' ' << ' ' << ' ' << "vertex " << v3 << endl;
							out << ' ' << ' ' << ' ' << "vertex " << v4 << endl;
							out << ' ' << ' ' << ' ' << "vertex " << v1 << endl;
							out << ' ' << ' ' << "endloop" << endl << ' ' << "endfacet" << endl;
							break;
						case 2:  
							f = get_Normal(v3_u,v2_u,v1_u);
							out << ' ' << "facet normal " << f << endl;
							out << ' ' << ' ' << "outer loop" << endl;
							out << ' ' << ' ' << ' ' << "vertex " << v3_u << endl;
							out << ' ' << ' ' << ' ' << "vertex " << v2_u << endl;
							out << ' ' << ' ' << ' ' << "vertex " << v1_u << endl;
							out << ' ' << ' ' << "endloop" << endl << ' ' << "endfacet" << endl;
							break;
						case 3:  
							f = get_Normal(v1_u,v4_u,v3_u);
							out << ' ' << "facet normal " << f << endl;
							out << ' ' << ' ' << "outer loop" << endl;
							out << ' ' << ' ' << ' ' << "vertex " << v1_u << endl;
							out << ' ' << ' ' << ' ' << "vertex " << v4_u << endl;
							out << ' ' << ' ' << ' ' << "vertex " << v3_u << endl;
							out << ' ' << ' ' << "endloop" << endl << ' ' << "endfacet" << endl;
							break;
						case 4:  
							f = get_Normal(v2,v2_u,v3_u);
							out << ' ' << "facet normal " << f << endl;
							out << ' ' << ' ' << "outer loop" << endl;
							out << ' ' << ' ' << ' ' << "vertex " << v2 << endl;
							out << ' ' << ' ' << ' ' << "vertex " << v2_u << endl;
							out << ' ' << ' ' << ' ' << "vertex " << v3_u << endl;
							out << ' ' << ' ' << "endloop" << endl << ' ' << "endfacet" << endl;
							break;
						case 5: 
							f = get_Normal(v3_u,v3,v2);
							out << ' ' << "facet normal " << f << endl;
							out << ' ' << ' ' << "outer loop" << endl;
							out << ' ' << ' ' << ' ' << "vertex " << v3_u << endl;
							out << ' ' << ' ' << ' ' << "vertex " << v3 << endl;
							out << ' ' << ' ' << ' ' << "vertex " << v2 << endl;
							out << ' ' << ' ' << "endloop" << endl << ' ' << "endfacet" << endl;
							break;
						case 6: 
							f = get_Normal(v1,v4,v4_u);
							out << ' ' << "facet normal " << f << endl;
							out << ' ' << ' ' << "outer loop" << endl;
							out << ' ' << ' ' << ' ' << "vertex " << v1 << endl;
							out << ' ' << ' ' << ' ' << "vertex " << v4 << endl;
							out << ' ' << ' ' << ' ' << "vertex " << v4_u << endl;
							out << ' ' << ' ' << "endloop" << endl << ' ' << "endfacet" << endl;
							break;
						case 7:  
							f = get_Normal(v4_u,v1_u,v1);
							out << ' ' << "facet normal " << f << endl;
							out << ' ' << ' ' << "outer loop" << endl;
							out << ' ' << ' ' << ' ' << "vertex " << v4_u << endl;
							out << ' ' << ' ' << ' ' << "vertex " << v1_u << endl;
							out << ' ' << ' ' << ' ' << "vertex " << v1 << endl;
							out << ' ' << ' ' << "endloop" << endl << ' ' << "endfacet" << endl;
							break;
						case 8:  
							f = get_Normal(v3,v3_u,v4_u);
							out << ' ' << "facet normal " << f << endl;
							out << ' ' << ' ' << "outer loop" << endl;
							out << ' ' << ' ' << ' ' << "vertex " << v3 << endl;
							out << ' ' << ' ' << ' ' << "vertex " << v3_u << endl;
							out << ' ' << ' ' << ' ' << "vertex " << v4_u << endl;
							out << ' ' << ' ' << "endloop" << endl << ' ' << "endfacet" << endl;
							break;
						case 9:  
							f = get_Normal(v4_u,v4,v3);
							out << ' ' << "facet normal " << f << endl;
							out << ' ' << ' ' << "outer loop" << endl;
							out << ' ' << ' ' << ' ' << "vertex " << v4_u << endl;
							out << ' ' << ' ' << ' ' << "vertex " << v4 << endl;
							out << ' ' << ' ' << ' ' << "vertex " << v3 << endl;
							out << ' ' << ' ' << "endloop" << endl << ' ' << "endfacet" << endl;
							break;
						case 10: 
							f = get_Normal(v2,v1,v1_u);
							out << ' ' << "facet normal " << f << endl;
							out << ' ' << ' ' << "outer loop" << endl;
							out << ' ' << ' ' << ' ' << "vertex " << v2 << endl;
							out << ' ' << ' ' << ' ' << "vertex " << v1 << endl;
							out << ' ' << ' ' << ' ' << "vertex " << v1_u << endl;
							out << ' ' << ' ' << "endloop" << endl << ' ' << "endfacet" << endl;
							break;
						case 11:  
							f = get_Normal(v1_u,v2_u,v2);
							out << ' ' << "facet normal " << f << endl;
							out << ' ' << ' ' << "outer loop" << endl;
							out << ' ' << ' ' << ' ' << "vertex " << v1_u << endl;
							out << ' ' << ' ' << ' ' << "vertex " << v2_u << endl;
							out << ' ' << ' ' << ' ' << "vertex " << v2 << endl;
							out << ' ' << ' ' << "endloop" << endl << ' ' << "endfacet" << endl;
							break;
					}

				}
				out.close();
			}
		}
};

class CAD {
	private:
		vector<Shape*> shapes;
	public:
		CAD() {}
		~CAD() {
			for(int i = 0; i < shapes.size(); ++i) {
				delete shapes[i];
			}
		}
		CAD(const CAD& orig) = delete;
		CAD& operator =(const CAD& orig) = delete;
		void add(Shape* s) {
			shapes.push_back(s);
		}
		void write(string fileName){
			ofstream out(fileName);
			if(out) {
				auto n = fileName.find('.');
				string s = fileName.substr(0, n);
				out << "solid " << s << endl;
				out.close();
				for( int i = 0; i < shapes.size(); ++i) {
					shapes[i]->write(fileName);
				}
				ofstream out(fileName, ofstream::app);
				out << "endsolid " << s;
				out.close();
			}
		}
};


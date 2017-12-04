//Xin Song -- CAD

#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include "vec3D.h"
#include<math.h>
using namespace std;

class Shape {
	private: 
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
		//virtual void write(string fileName) = 0;
		virtual void write(ofstream& s) = 0;
		virtual ~Shape() {}
		
		void writeTriangle(Vec3d v1, Vec3d v2, Vec3d v3, ofstream& out) {
			Vec3d f1 = get_Normal(v1, v2, v3);
			out << ' ' << "facet normal " << f1 << endl;
			out << ' ' << ' ' << "outer loop" << endl;
			out << ' ' << ' ' << ' ' << "vertex " << v1 << endl;
			out << ' ' << ' ' << ' ' << "vertex " << v2 << endl;
			out << ' ' << ' ' << ' ' << "vertex " << v3 << endl;
			out << ' ' << ' ' << "endloop" << endl << ' ' << "endfacet" << endl;
		}
};

class Cylinder : public Shape{
	private:
		double r,h;
		int facets;
		vector<Vec3d> vertixes;
	public:
		Cylinder(double x, double y, double z, double r, double h, int facets) : Shape(x, y, z), r(r), h(h), facets(facets) {
			for(int i = 0; i <= facets; ++i) {				
				vertixes.push_back(Vec3d (getx() + r*cos(2*M_PI/facets*(i)), gety() + r*sin(2*M_PI/facets*(i)), h/2 + getz()));
				vertixes.push_back(Vec3d (getx() + r*cos(2*M_PI/facets*(i)), gety() + r*sin(2*M_PI/facets*(i)), getz() - h/2));
			}
		}
		
		void write(ofstream& out) override {
			Vec3d vc_u(getx(), gety(), h/2 + getz());
			Vec3d vc_d(getx(), gety(), getz() - h/2);
			for(int i = 0; i+3 < vertixes.size() ; i += 2) {				
				writeTriangle(vertixes[i+1], vertixes[i+3], vertixes[i+2], out);	
				writeTriangle(vertixes[i+2], vertixes[i], vertixes[i+1], out);
				writeTriangle(vertixes[i], vertixes[i+2], vc_u, out);
				writeTriangle(vertixes[i+1], vc_d, vertixes[i+3], out);
			}	
		} 
};

class Cube :  public Shape {
	private:
		double size;
		vector<Vec3d> vertixes;
	public:
		Cube(double x, double y, double z, double size) : Shape(x, y, z), size(size) {
			vertixes.push_back(Vec3d (getx() - size/2, gety() - size/2, getz() - size/2));
			vertixes.push_back(Vec3d (getx() - size/2, gety() + size/2, getz() - size/2));
			vertixes.push_back(Vec3d (getx() + size/2, gety() + size/2, getz() - size/2));
			vertixes.push_back(Vec3d (getx() + size/2, gety() - size/2, getz() - size/2));
			vertixes.push_back(Vec3d (getx() - size/2, gety() - size/2, getz() + size/2));
			vertixes.push_back(Vec3d (getx() - size/2, gety() + size/2, getz() + size/2));
			vertixes.push_back(Vec3d (getx() + size/2, gety() + size/2, getz() + size/2));
			vertixes.push_back(Vec3d (getx() + size/2, gety() - size/2, getz() + size/2));
		}

		void write(ofstream& out) override {
			writeTriangle(vertixes[0],vertixes[1],vertixes[2], out);
			writeTriangle(vertixes[2],vertixes[3],vertixes[0], out);
			writeTriangle(vertixes[6],vertixes[5],vertixes[4], out);
			writeTriangle(vertixes[4],vertixes[7],vertixes[6], out);
			writeTriangle(vertixes[1],vertixes[5],vertixes[6], out);
			writeTriangle(vertixes[6],vertixes[2],vertixes[1], out);
			writeTriangle(vertixes[0],vertixes[3],vertixes[7], out);
			writeTriangle(vertixes[7],vertixes[4],vertixes[0], out);
			writeTriangle(vertixes[2],vertixes[6],vertixes[7], out);
			writeTriangle(vertixes[7],vertixes[3],vertixes[2], out);
			writeTriangle(vertixes[1],vertixes[0],vertixes[4], out);
			writeTriangle(vertixes[4],vertixes[5],vertixes[1], out);
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
				for( int i = 0; i < shapes.size(); ++i) {
					shapes[i]->write(out);
				}
				out << "endsolid " << s;
				out.close();
			}
		}
};

int main() {
	CAD c;
	c.add(new Cube(0,0,0,  5));
	c.add(new Cylinder(100,0,0,   3, 10, 10));
	c.write("test.stl");

}

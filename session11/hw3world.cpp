#include "Shape.hh"
#include "matrix.hh"
//#include "vec3D.h"
//#include <iostream>
#include <vector>
//#include <math.h>
//#include <string>
using namespace std;

class World{
	vector<Shape*> shapes;
	public:
		World() ;
		void add(Matrix4 m, Shape* s) {
			m.apply(*s);
			shapes.push_back(s);
		}
		/*void addCube(Metrix4 m, Cube* c) {
		}*/

};


int main() {
	World w;
	Matrix4 doublex = Matrix4::scale(2.0, 1.0, 1.0);
	w.add(doublex, new Cube(0,0,0, 10);//create a cube at the origin stretch by factor if 2 in the x

	Matrix4 moveright = Matrix4::translate(10.0, 0.0, 0.0);		
	w.add(moveright, new Cylinder(0,0,0, 5.0, 20.0, 30);//create cylinder at x = 10

//	Metrix4 = rotatex45 = Metrix4::rotateX(45);
//	cout << rotatex45;

//	w.save("test.stl");
}


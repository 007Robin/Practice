//Xin Song -- K-means
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;
class Point {
	public:
		double x, y;
		Point(double x, double y) : x(x), y(y) {}
		
		Point(istream& s){
			s >> x >> y;
		}
    	friend ostream& operator<<(ostream& s, const Point& point) {
			s << point.x << ", " << point.y;
			return s;
		}

};

inline double sq(double x) { return x*x; }
double distance(const Point& a, const Point& b) {
	return sqrt(sq(a.x-b.x) + sq(a.y-b.y)); 
}

//find the sum of the distances to one point
double metric(const vector<Point>& points, const Point& center) {
	double sum = 0;
	for (auto p : points) {
		sum += distance(p, center);
	}
	return sum;
}

// find the sum of the distance to the nearest point
double metric(const vector<Point>& points, const vector<Point>& centers) {
	double sum = 0;
	const double BIG = 1e100; //the original googol!
	for (auto p : points) {
		double min = distance(p, centers[0]);
		Point bestPoint = centers[0];
		for (int i = 1; i < centers.size(); ++i) {
			if (distance(p,centers[i]) < min) {
				min = distance(p,centers[i]);
				bestPoint = centers[i];
			}
		}
		sum += distance(p, bestPoint);    
	}
	return sum;
}

void populatePoints(vector<Point>& points, const char filename[]) {
	ifstream f(filename);
	if (!f.eof()) {
		int x = 0, y = 0;
		while( f >> x >> y)
			points.push_back(Point(x,y));
	}
}

vector<Point> readPoints(const char filename[]) {
	ifstream ifs(filename);
	vector<Point> points;
	if(ifs) {
		int x = 0, y = 0;
		while (ifs >> x >> y) 
			points.push_back(Point(x,y));
	}
	return points;
}

Point findCenter(vector<Point>& points){
	Point p(0, 0);
	for(int i = 0; i < points.size(); i++){
		p.x += points[i].x;
		p.y += points[i].y;
	}
	return Point(p.x/points.size(), p.y/points.size());
}
// k-means clustering

int main() {
	vector<Point> points = readPoints("points.dat");
	Point s1(1,2);
	Point s2(99,5);
	
	vector<Point> centers;
	centers.push_back(s1);
	centers.push_back(s2);

	cout << "the sum of distance to the nearest point : " << metric(points, centers) << endl;
/*	double globalsum = 1e100;
	while(1) {
		vector<Point> s1s;
		vector<Point> s2s;
		Point t1 = s1;
		Point t2 = s2;
		for(int i = 0; i < points.size(); i++){
			//cout << points[i] << endl;
			if (distance(points[i], s1) < distance(points[i], s2)) {
				//points[i] belong s1
				s1s.push_back(points[i]);
			}
			else {
				//points[i] belong s2
				s2s.push_back(points[i]);
			}
		}
		if( metric(s1s, s1) + metric(s2s, s2) < globalsum) {
			globalsum = metric(s1s, s1) + metric(s2s, s2);
		}
		//update s1 to be the center of s1s 
		s1 = findCenter(s1s);
		if( s1.x == t1.y && s1.y == t1.y) break;
		//update s2 to be the center of s2s 
		s2 = findCenter(s2s);
		if( s2.x == t2.x && s2.y == t2.y) break;
		cout << "s1:"<<  s1 << endl;
		cout << "s2:" << s2 << endl;
		cout << globalsum << endl;

		cout << "find the sum of distance to the nearest point : " << metric(points, centers) << endl;
	}
*/

}

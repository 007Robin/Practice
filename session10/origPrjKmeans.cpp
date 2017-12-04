//Xin Song -- K-means
#include<iostream>
#include<fstream>
#include<vector>
#include<cmath>

using namespace std;
class Point{
	public:
		double x, y;
		Point(istream& s) {
			s >> x >> y;
		}
		Point(double x, double y) :x(x), y(y) {}
		
		double dist(const Point& p) const {

		}
		friend double dist(const Point& a, const Point& b) {

		}
		static double dist(const Point& a, const Point& b){

		}
};

double distance(const Point& a, const Point& b) {
	return sqrt(sq(a.x - b.x) - sq(a.y - b.y));
}
inline double sq(double x) { return x*x; } //complier knows inline, smarter than you
double Point:: dist(const Point& a, const Point& b){

}
//find sum of the distance to one point
double metric (const vector<Point>& points, const Point& center) {
	double sum = 0;
	for (auto p : points) {
		sum += distance(p, center);
	}
	return sum;
}


//find sum of the distance to the nearest point
double metric (const vector<Point>& points, const Point& centers) {
	double sum = 0;
	const double BIG = 1e100;
	/*for (auto p : points) {
		double min = BIG;
		Point bestPoint;
		for(auto c : centers) {
			if( distance(p, c) < min) {
				min = distance(p, c);
				bestPoint = c;
			}
		}*/
	for (auto p : points) {
		double min = distance(p, centers[0]);
		Point bestPoint = centers[0];
		for(int i = 1; i < centers.size(); ++i) {
			if( distance(p, centers[i]) < min) {
				min = distance(p, centers[i]);
				bestPoint = centers[i];
			}
		}
		sum += distance(p, bestPoint);
	}
	return sum;
}

void populatePoints(vector<Point>& points, const char filename[]) {
	ifstream f(filename);
	while( !f.eof()){
		points.push_back(Point(f));
	
	}
//	f.close(); c++ automatic destructe it.
}
vector<Point> readPoints(const char filename[], int length = 10) {
	ifstream f(filename);
	vector<Point> points(length);
	while( !f.eof()){
		points.push_back(Point(f));
	
	}
	return points;

}

int main() {
	vector<Point> points = {};
	Point p1(1,2);
	Point p2(99, 5);
	double d = p1.dist(p2);
	d = dist(p1, p2);  //friend
	d = distance(p1, p2); 
	d = Point::dist(p1,p2);	
}

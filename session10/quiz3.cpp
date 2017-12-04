class Shape{
	private:
		double x,y;
	public:
		Shape(double x, double y) : x(x), y(y) {}
		double getX() {}
		double getY() {}
		virtual void print() const = 0;
		virtual double area() const = 0;
		
		virtual void info() const = 0;
		virtual bool contains(double x, double y) const = 0;
};
class Rect : public Shape {
	private:
		double w, h;
	public:
		Rect(double x, double y, double w, double h) : Shape(x, y), w(w), h(h) {}
		virtual void print() const {
			cout << getX() << " " << getY() << " " << w << " " << z;
		}
		virtual double area() const {
			return h*w;
		}
		
		virtual void info() const {
			print();
		}
		virtual bool contains(double x, double y) const {
			
			return (x >= getX() - w/2 && x <= getX() + w/2 && y >= getY() + h/2 && y <= getY() + h/2) 
		}

};
class Circle : public Shape {
	private:
		double r;
	public:
		Circle(double x, double y, double r) : Shape(x, y), r(r) {}
		virtual void print() const {
			cout << getX() << " " << getY() << " " << x;
		}
		virtual double area() const {
			return M_PI * r*r;
		}
		
		
		virtual void info() const {
			print();
		}
		
		virtual bool contains(double x, double y) const {
			double dx = x -getX(), dy = y - getY();
			return dx*dx + dy*dy <= r*r;
		}
};
class Drawing {
	private:
		vector<Shape*> s;
	public:
		Drawing() : shapes() {}
		~Drawing() {
			for( int i = 0; i < s.size(); i++)
				delete s[i];
		}
}
int main() {
	vector<Shape*> shapes;
	shapes.push_back(new Circle (50, 100, 20));
	shapes.push_back(new Rect (50, 100, 20));

	for(auto s : shapes) {
		s->info();
	}

}

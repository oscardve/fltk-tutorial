#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Slider.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Text_Display.H>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <math.h>
#define PI 3.14159265

using namespace std;
using Callback = void(*)(Fl_Widget*, void*);
typedef double Fct(double,double);
int w{Fl::w()/2}, h{Fl::h()};
struct Windows;

struct Point {
	int x, y;
	Point(int int1, int int2) : x(int1), y(int2) {}
};

struct Shape {
	int line_width, line_color, fill_color;
	vector<Point> pts;
	Shape(){}
	Shape(int lw, int lc, int fc)
	: line_width(lw), line_color(lc), fill_color(fc) {}
	void add(Point p) { pts.push_back(p); }
	void move(int dx, int dy) {
		for(int i=0; i<pts.size(); i++) {
			pts[i].x += dx;
			pts[i].y += dy;
		}
	}
	virtual void draw() {}
    void clear(){pts.clear();}
};

struct Function : Shape {
	Function(Fct f, double r1, double r2, Point xy, int count, double lx, double ly)
    :xy(xy),lx(lx),ly(ly),count(count){
		double dist = (r2-r1)/count;
		double r = r1;
		for (int i = 0; i<count; ++i) {
			add(Point(xy.x+r*lx,xy.y-f(r,1)*ly));
			r += dist;
		}
    }
    void replot(Fct f, double r1, double r2, double alpha){
		double dist = (r2-r1)/count;
		double r = r1;
        clear();
		for (int i = 0; i<count; ++i) {
			add(Point(xy.x+r*lx,xy.y-f(r,alpha)*ly));
			r += dist;
		}
    }
	void draw() {
		fl_color(FL_WHITE);
        if (1<pts.size())
        for (unsigned int i=1; i<pts.size(); ++i)
            fl_line(pts[i-1].x,pts[i-1].y,pts[i].x,pts[i].y);
	}
    Point xy;
    int count;
    double lx,ly;
};

double gaussian(double x, double alpha){ return exp(-x*x/alpha); }
Function sf1{gaussian,-PI,PI,Point{w/2,3*h/4},1000,w/6,h/4};

struct Widget {
	int width, height;
	string label;
	Point xy;
	Callback do_it;
	Windows *own;
	Widget(Point p, int w, int h, string s, Callback cb)
	: xy(p), width(w), height(h), label(s), do_it(cb) {}
	virtual void attach(Windows&) {}
	virtual int get_value() {}
};

struct Slider : Widget {
	Fl_Slider* pw;
	Slider(Point p, int w, int h, string s, Callback cb)
	: Widget(p, w, h, s, cb) {}
	void set_value(int v) { pw->value(v); }
	int get_value() { return pw->value(); }
	void set_bounds(int b1, int b2) { pw->bounds(b1, b2); }
	void attach(Windows &window) {
		pw = new Fl_Slider(xy.x, xy.y, width, height, label.c_str());
		pw->type(FL_HOR_NICE_SLIDER);
		pw->align(FL_ALIGN_RIGHT);
		pw->labelfont(FL_COURIER_ITALIC);
		pw->labelcolor(FL_WHITE);
		pw->labelsize(14);
		pw->callback(do_it);
		own = &window;
	}
};

void call1(Fl_Widget*, void*);
Slider slider1(Point(50,80),100,30,"Width",call1);
void call1(Fl_Widget*, void*) {
    sf1.replot(gaussian,-PI,PI,slider1.get_value());
    Fl::redraw();
}

struct Windows : Fl_Double_Window {
	Windows(Point topleft, int width, int height, string title)
	: Fl_Double_Window(topleft.x, topleft.y, width, height, title.c_str()) {
		color(FL_BLACK);
		show();
	}
	vector<Shape*> shapes;
	void attach(Shape& s) { shapes.push_back(&s); }
	void attach(Widget& w) {
		begin();
		w.attach(*this);
		end();
	}
	void draw() {
		Fl_Double_Window::draw();
		for(int i=0;i<shapes.size();i++)
			shapes[i]->draw();
	}
};

Windows window(Point(w, 0), w, h, "Part5");

struct Line : Shape {
	Line(Point p1, Point p2, int lw, int lc)
	: Shape(lw, lc, 0) {
		add(p1);
		add(p2);
	}
	void draw() {
		fl_line_style(FL_SOLID,line_width);
		fl_color(line_color);
		fl_line(pts[0].x,pts[0].y,pts[1].x,pts[1].y);
	}
};

int main(){
	window.attach(slider1);
	slider1.set_value(2);
	slider1.set_bounds(1,10);
	window.attach(sf1);
	return Fl::run();
}

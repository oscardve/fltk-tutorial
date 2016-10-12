struct Circle : Shape {
	int radius;
	Circle(Point p, int r, int lw, int lc, int fc)
	: radius(r), Shape(lw, lc, fc) {
		add(p);
		move(-radius,-radius);
	}
	void relocate(int xnew, int ynew) {
		pts[0].x = xnew-radius;
		pts[0].y = ynew-radius;
	}
	void draw() {
		fl_line_style(FL_SOLID,line_width);
		fl_color(fill_color);
		fl_pie(pts[0].x,pts[0].y,2*radius-1,2*radius-1,0,360);
		fl_color(line_color);
		fl_arc(pts[0].x,pts[0].y,2*radius,2*radius,0,360);
	}
};

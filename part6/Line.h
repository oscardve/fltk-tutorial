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

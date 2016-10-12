struct Slider : Widget {
	Fl_Slider* pw;
	Slider(Point p, int w, int h, string s)
	: Widget(p, w, h, s, 0) {}
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
		own = &window;
	}
};

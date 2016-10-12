struct In_box : Widget {
	Fl_Input* pw;
	In_box(Point p, int w, int h, string s)
	: Widget(p, w, h, s, 0) {}
	void set_value(string s) { pw->value(s.c_str()); }
	string get_value() { return string(pw->value()); }
	void attach(Windows &window) {
		pw = new Fl_Input(xy.x, xy.y, width, height, label.c_str());
		pw->align(FL_ALIGN_RIGHT);
		pw->color(FL_WHITE);
		pw->textfont(FL_COURIER);
		pw->textcolor(FL_BLACK);
		pw->textsize(12);
		pw->labelfont(FL_COURIER_ITALIC);
		pw->labelcolor(FL_WHITE);
		pw->labelsize(14);
		own = &window;
	}
};


struct Out_box : Widget {
	Fl_Text_Display* pw;
	Fl_Text_Buffer* buff;
	Out_box(Point p, int w, int h, string s)
	: Widget(p, w, h, s, 0) {}
	void set_value(string s) { buff->text(s.c_str()); }
	void attach(Windows &window) {
		pw = new Fl_Text_Display(xy.x, xy.y, width, height, label.c_str());
		buff = new Fl_Text_Buffer();
		pw->buffer(buff);
		pw->align(FL_ALIGN_RIGHT);
		pw->color(FL_BLACK);
		pw->textfont(FL_COURIER);
		pw->textcolor(FL_WHITE);
		pw->textsize(12);
		pw->labelfont(FL_COURIER_ITALIC);
		pw->labelcolor(FL_WHITE);
		pw->labelsize(14);
		own = &window;
	}
};

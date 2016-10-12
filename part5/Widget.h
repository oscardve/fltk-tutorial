struct Widget {
	int width, height;
	string label;
	Point xy;
	Callback do_it;
	Windows *own;
	Widget(Point p, int w, int h, string s, Callback cb)
	: xy(p), width(w), height(h), label(s), do_it(cb) {}
	virtual void attach(Windows&) {}
};

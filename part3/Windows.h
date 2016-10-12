struct Windows : Fl_Double_Window {
	Windows(Point topleft, int width, int height, string title)
	: Fl_Double_Window(topleft.x, topleft.y, width, height, title.c_str()) {
		color(FL_BLACK);
		show();
	}
	vector<Shape*> shapes;
	void attach(Shape& s) { shapes.push_back(&s); }
	void draw() {
		Fl_Double_Window::draw();
		for(int i=0;i<shapes.size();i++)
			shapes[i]->draw();
	}
};

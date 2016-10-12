struct Windows : Fl_Double_Window {
	Windows(Point topleft, int width, int height, string title)
	: Fl_Double_Window(topleft.x, topleft.y, width, height, title.c_str()) {
		color(FL_BLACK);
		show();
	}
};

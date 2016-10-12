#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <string>

using namespace std;

int main() {
	int w{Fl::w()/2}, h{Fl::h()};
	string title{"Part 1"};
	Fl_Double_Window *window = new Fl_Double_Window(w, 0, w, h, title.c_str());
	window->color(FL_BLACK);
	window->show();
	return Fl::run();
}

#include "GUI.h"

Windows window(Point(w, 0), w, h, "Part5");
Line line1(Point(0,h/4),Point(w,h/4),3,FL_WHITE);
Line line2(Point(w/2,0),Point(w/2,h/4),3,FL_WHITE);
Text text1(Point(200,50),FL_HELVETICA,25,FL_RED,"INPUT");
Text text2(Point(w/2+200,50),FL_HELVETICA,25,FL_RED,"OUTPUT");

Slider slider1(Point(50,80),100,30,"Particle speed.");
In_box inbox1(Point(50,120),100,30,"Number of particles.");
Out_box outbox1(Point(w/2+50,80),100,30,"Number of collisions.");
Out_box outbox2(Point(w/2+50,120),100,30,"Time elapsed (seconds).");

#include "callback1.h"
Button button1(Point(200,200),100,30,"RUN",callback1);
Button button2(Point(w/2+200,200),100,30,"PLOT",callback1);

int main() {
	srand(time(NULL));
	window.attach(line1);
	window.attach(line2);
	window.attach(text1);
	window.attach(text2);

	window.attach(slider1);
	window.attach(inbox1);
	window.attach(button1);
	window.attach(outbox1);
	window.attach(outbox2);
	window.attach(button2);

	slider1.set_value(500);
	slider1.set_bounds(100,1000);
	inbox1.set_value("10");
	outbox1.set_value("0");
	outbox2.set_value("0");
	return Fl::run();
}

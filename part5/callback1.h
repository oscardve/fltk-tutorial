#include <algorithm>

void callback1(Fl_Widget*, void*) {
	ofstream out{"collisions_vs_time.txt"};
	double R{25};
	double xmin{R}, xmax{w-R}, ymin{h/4+R}, ymax{h-R-30};
	double x0{rand()/double(RAND_MAX)*(xmax-xmin)+xmin}, y0{rand()/double(RAND_MAX)*(ymax-ymin)+ymin};
	vector<double>x, y, vx, vy;
	x.push_back(x0);
	y.push_back(y0);
	Circle circle1(Point(x0,y0),R,1,FL_GREEN,FL_BLUE);
	window.attach(circle1);
	double v0{slider1.get_value()*0.0001}, dt{1};
	double theta{rand()/double(RAND_MAX)*2*3.1416};
	vx.push_back(v0*cos(theta));
	vy.push_back(v0*sin(theta));
	while(true) {
		if(x[0]>xmax) {
			vx[0] *= -1;
			x[0] = xmax;
		}
		else if(x[0]<xmin) {
			vx[0] *= -1;
			x[0] = xmin;
		}
		if(y[0]>ymax) {
			vy[0] *= -1;
			y[0] = ymax;
		}
		else if(y[0]<ymin) {
			vy[0] *= -1;
			y[0] = ymin;
		}
		x[0] += vx[0] * dt;
		y[0] += vy[0] * dt;
		circle1.relocate(x[0], y[0]);
		double v = slider1.get_value()*0.0001;
		v0 = sqrt(vx[0]*vx[0] + vy[0]*vy[0]);
		vx[0] *= v/v0;
		vy[0] *= v/v0;
		Fl::check();
		Fl::redraw();
	}
}



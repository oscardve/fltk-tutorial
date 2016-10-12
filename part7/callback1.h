#include <algorithm>
#include <math.h>
#include <chrono>

using namespace chrono;

int collisions{};
double R{25}, D{2*R}, dt{1};
double xmin{R}, xmax{w-R}, ymin{h/4+R}, ymax{h-R-30};
vector<double>x, y, vx, vy;

void boundary(int i) {
	if(x[i]>xmax) {
		vx[i] *= -1;
		x[i] = xmax;
	}
	else if(x[i]<xmin) {
		vx[i] *= -1;
		x[i] = xmin;
	}
	if(y[i]>ymax) {
		vy[i] *= -1;
		y[i] = ymax;
	}
	else if(y[i]<ymin) {
		vy[i] *= -1;
		y[i] = ymin;
	}
}

void collision(int i, int j) {
	double xij = x[j] - x[i];
	double yij = y[j] - y[i];
	double rij = sqrt(xij*xij + yij*yij);
	if(rij<D) {
		collisions++;
		double xiju = xij/rij;
		double yiju = yij/rij;
		double dv = xiju * (vx[j] - vx[i]) + yiju * (vy[j] - vy[i]);
		vx[i] += xiju * dv;
		vy[i] += yiju * dv;
		vx[j] -= xiju * dv;
		vy[j] -= yiju * dv;
		x[i] += vx[i] * dt;
		y[i] += vy[i] * dt;
		x[j] += vx[j] * dt;
		y[j] += vy[j] * dt;
		xij = x[j] - x[i];
		yij = y[j] - y[i];
		rij = sqrt(xij*xij + yij*yij);
		if(rij < D) {
			x[i] += (D-rij) * xiju;
			y[i] += (D-rij) * yiju;
			x[j] -= (D-rij) * xiju;
			y[j] -= (D-rij) * yiju;
		}
	}
}

void callback1(Fl_Widget*, void*) {
	ofstream out{"collisions_vs_time.txt"};
	int N = stoi(inbox1.get_value());
	double v0{slider1.get_value()*0.0001};
	vector<Circle*> circles;
	for(int i=0;i<N;i++) {
		double x0{rand()/double(RAND_MAX)*(xmax-xmin)+xmin}, y0{rand()/double(RAND_MAX)*(ymax-ymin)+ymin};
		x.push_back(x0);
		y.push_back(y0);
		circles.push_back(new Circle(Point(x0,y0),R,1,FL_GREEN,FL_BLUE));
		window.attach(*circles[i]);
		double theta{rand()/double(RAND_MAX)*2*3.1416};
		vx.push_back(v0*cos(theta));
		vy.push_back(v0*sin(theta));
	}
	steady_clock::time_point t1 = steady_clock::now();
	steady_clock::time_point t2 = steady_clock::now();
	while(true) {
		t2 = steady_clock::now();
		int duration = duration_cast<seconds>(t2 - t1).count();
		out<<duration<<'\t'<<collisions<<endl;
		outbox1.set_value(to_string(collisions));
		outbox2.set_value(to_string(duration));
		for(int i=0;i<N;i++) {
			for(int j=0;j<N && j!=i; j++) {
				boundary(i);
				collision(i,j);
			}
			x[i] += vx[i] * dt;
			y[i] += vy[i] * dt;
			circles[i]->relocate(x[i], y[i]);
			double v = slider1.get_value()*0.0001;
			v0 = sqrt(vx[i]*vx[i] + vy[i]*vy[i]);
			vx[i] *= v/v0;
			vy[i] *= v/v0;
		}
		Fl::check();
		Fl::redraw();
	}
}



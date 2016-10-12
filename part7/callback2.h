#include "gnuplot-iostream.h"

void callback2(Fl_Widget*, void*) {
	Gnuplot gp;
	gp << R"(
		set terminal wxt size 1000,1000 enhanced font 'Verdana,20'
		set title 'Collisions vs Time'
		set xlabel 'Time (s)'
		set ylabel 'Collisions'
		plot 'collisions_vs_time.txt' w l lw 3 notitle
	)";
}

//Function graphing drill:
#include "Window.h"
#include "Graph.h"
#include <cmath>
using namespace Graph_lib;

double one(double x) { return 1; }
double slope(double x) { return x / 2; }
double square(double x) { return x*x; }
double slope_cosine(double x) { return slope(x) + cos(x); }

int main()
{	
	Graph_lib::Window win{ Point{100,100},600,600,"Function graphs." };
	Axis xs{ Axis::x,Point{100,300},400,20,"= = 20 pixels" };
	Axis ys{ Axis::y,Point{300,500},400,20,"" };
	xs.set_color(Color::red);
	ys.set_color(Color::red);
	win.attach(xs);
	win.attach(ys);

	constexpr double r_min = -10;
	constexpr double r_max = 11;
	constexpr double scale_x = 20;
	constexpr double scale_y = 20;
	const Point orig{300,300};
	Function fct1{ one,r_min,r_max,orig ,400,scale_x,scale_y };
	fct1.set_color(Color::black);
	win.attach(fct1);

	Function fct2{ slope,r_min,r_max,orig ,400,scale_x,scale_y };
	Text t1{ Point{300,300},"x / 2" };
	fct2.set_color(Color::green);
	t1.move(r_min*scale_x-scale_x, - slope(r_min*scale_y));
	t1.set_color(Color::green);
	win.attach(fct2);
	win.attach(t1);

	Function fct3{ square,r_min,r_max,orig,400,scale_x,scale_y };
	fct3.set_color(Color::dark_blue);
	win.attach(fct3);

	Function fct4{ std::cos,r_min,r_max,orig,400,scale_x,scale_y };
	fct4.set_color(Color::blue);
	win.attach(fct4);

	Function fct5{ slope_cosine ,r_min,r_max,orig,400,scale_x,scale_y };
	fct5.set_color(Color::yellow);
	win.attach(fct5);

	gui_main();
	
	return 0;
}
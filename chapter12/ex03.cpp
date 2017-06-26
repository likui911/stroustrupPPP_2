#include "Simple_window.h" 
#include "Graph.h" 
#include "Window.h"
using namespace Graph_lib;

/*
Draw your initials 150 pixels high. Use a thick line. Draw each initial in a different color.
My initial "L K"
*/
int main()
{
	Simple_window win{ Point{100,100},500,400,"Initials" };
	Line l1{ Point{50,50},Point{50,200} };
	l1.set_color(Color::red);
	Line l2{ Point{50,200},Point{150,200} };
	l2.set_color(Color::green);
	Line l3{ Point{200,200},Point{200,50} };
	l3.set_color(Color::blue);
	Line l4{ Point{200,125},Point{300,50} };
	l4.set_color(Color::dark_yellow);
	Line l5{ Point{200,125},Point{300,200} };
	l5.set_color(Color::dark_green);
	win.attach(l1);
	win.attach(l2);
	win.attach(l3);
	win.attach(l4);
	win.attach(l5);
	win.wait_for_button();
}
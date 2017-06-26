#include "Simple_window.h" 
#include "Graph.h" 
#include "Window.h"
using namespace Graph_lib;

/*
Draw a rectangle as a Rectangle and as a Polygon. Make the lines of the Polygon red and the lines of the Rectangle
blue.
*/
int main()
{
	Simple_window win{ Point{100,100},500,400,"ex01" };
	Polygon poly;
	poly.add(Point{200,30});
	poly.add(Point{ 290,100 });
	poly.add(Point{ 240,200 });
	poly.add(Point{ 150,300 });
	poly.add(Point{ 100,100 });
	poly.set_color(Color::red);
	Rectangle rect{ Point{50,50},Point{150,200} };
	rect.set_color(Color::blue);
	win.attach(poly);
	win.attach(rect);
	win.wait_for_button();
}


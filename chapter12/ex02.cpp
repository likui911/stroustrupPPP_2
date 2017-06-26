#include "Simple_window.h" 
#include "Graph.h" 
#include "Window.h"
using namespace Graph_lib;

/*
Draw a 100-by-30 Rectangle and place the text “Howdy!” inside it.
*/
int main()
{
	Simple_window win{ Point{ 100,100 },500,400,"ex02" };
	Rectangle rect{ Point{100,100},Point{300,300} };
	rect.set_color(Color::black);
	Text t{ Point{150,200},"Hello Graphics !" };
	t.set_color(Color::red);
	win.attach(rect);
	win.attach(t);
	win.wait_for_button();
}

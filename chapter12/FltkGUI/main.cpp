#include "Simple_window.h" 
#include "Graph.h" 
#include "Window.h"

using namespace Graph_lib;

int main()
{
	Point tl{ 100,100 };
	Simple_window win(tl, 600, 400, "Cavas #1");
	win.wait_for_button();

	Axis xa(Axis::x, Point{ 20,300 }, 280, 20, "x axis");
	win.attach(xa);
	win.set_label("Cavas #2");
	win.wait_for_button();

	Axis ya(Axis::y, Point{ 20,300 }, 280, 20, "y axis");
	win.attach(ya);
	win.set_label("Cavas #3");
	win.wait_for_button();

	Function sine{ sin,0,100, Point{ 20,150 },1000,50,50 };
	win.attach(sine);
	win.set_label("Cavas #4");
	win.wait_for_button();

	Polygon poly;
	poly.add(Point{ 300,200 });
	poly.add(Point{ 350,100 });
	poly.add(Point{ 400,200 });
	poly.set_color(Color::red);
	poly.set_style(Line_style::dash);
	win.attach(poly);
	win.set_label("Cavas #5");
	win.wait_for_button();

	Rectangle rect{ Point{200,200},100,50 };
	win.attach(rect);
	win.set_label("Cavas #6");
	win.wait_for_button();

	Closed_polyline closed_poly;
	closed_poly.add(Point(100, 50));
	closed_poly.add(Point(200, 50));
	closed_poly.add(Point(200, 100));
	closed_poly.add(Point(100, 100));
	closed_poly.add(Point{ 50,75 });
	win.attach(closed_poly);

	rect.set_fill_color(Color::yellow);
	closed_poly.set_style(Line_style(Line_style::dash, 4));
	closed_poly.set_fill_color(Color::green);
	poly.set_style(Line_style(Line_style::dash,4));
	poly.set_color(Color::red);
	win.set_label("Cavas #7");
	win.wait_for_button();

	Text t{ Point{150,150},"Hello, graphical world!" };
	win.attach(t);
	win.set_label("Cavas #8");
	win.wait_for_button();

	t.set_font(Font::times_bold);
	t.set_font_size(20);
	win.set_label("Cavas #9");
	win.wait_for_button();

	Image ii{ Point{100,50},"image.jpg" };
	win.attach(ii);
	win.set_label("Cavas #10");
	win.wait_for_button();

	ii.move(100,200);
	win.set_label("Cavas #11");
	win.wait_for_button();

	Circle c{ Point{ 100,200 },50 };
	Ellipse e{ Point{ 100,200 }, 75,25 };
	e.set_color(Color::dark_red);
	Mark m{ Point{ 100,200},'x' };
	ostringstream oss;
	oss << "screen size: " << x_max() << "*" << y_max()
		<< "; window size: " << win.x_max() << "*" << win.y_max();
	Text sizes{ Point{ 100,20 },oss.str() };
	Image cal{ Point{ 225,225 },"snow_cpp.jpg" }; // 320*240-pixel gif
	cal.set_mask(Point{ 40,40 },200,150); // display center part of image
	win.attach(c);
	win.attach(m);
	win.attach(e);
	win.attach(sizes);
	win.attach(cal);
	win.set_label("Canvas #12");
	win.wait_for_button();

}



#include "Simple_window.h"
#include "Window.h"
#include "Graph.h"

//Draw a box with rounded corners. Define a class Box, consisting of four lines and four arcs.
namespace Graph_lib
{
	struct Box :Shape
	{
		Box(Point p, int ww, int hh, int dc = 10) :w{ ww }, h{ hh }, c{dc}
		{
			if (h <= 0 || w <= 0) error("Bad rectangle: non-positive side");
			if (h/2 < c || w/2 < c)error("Bad corner: corner too long");
			add(p);
		}

		void draw_lines()const
		{
			//const int border = 1;
			if (color().visibility())
			{
				fl_color(color().as_int());
				fl_line(point(0).x + c, point(0).y, point(0).x + w - c, point(0).y);
				fl_line(point(0).x + c, point(0).y+h, point(0).x + w - c, point(0).y+h);
				fl_line(point(0).x, point(0).y+c, point(0).x, point(0).y+h-c);
				fl_line(point(0).x+w, point(0).y + c, point(0).x+w, point(0).y + h - c);

				fl_arc(point(0).x,point(0).y,2*c,2*c,90,180);
				fl_arc(point(0).x+w-2*c, point(0).y, 2 * c, 2 * c, 0, 90);
				fl_arc(point(0).x, point(0).y+h-2*c, 2 * c, 2 * c, 180, 270);
				fl_arc(point(0).x+w-2*c, point(0).y+h-2*c, 2 * c, 2 * c, 270, 360);
			}
			if (fill_color().visibility())
			{
				//fill rectangles
				fl_color(fill_color().as_int());
				fl_rectf(point(0).x + c, point(0).y+1, w - 2 * c, c);
				fl_rectf(point(0).x + c, point(0).y+h-c, w - 2 * c, c);
				fl_rectf(point(0).x+1, point(0).y +c, w-1 , h-2*c);
				//fill corners
				fl_pie(point(0).x+1, point(0).y+1, 2 * c, 2 * c, 90, 180);
				fl_pie(point(0).x + w - 2 * c-1, point(0).y+1, 2 * c, 2 * c, 0, 90);
				fl_pie(point(0).x+1, point(0).y + h - 2 * c-1, 2 * c, 2 * c, 180, 270);
				fl_pie(point(0).x + w - 2 * c-1, point(0).y + h - 2 * c-1, 2 * c, 2 * c, 270, 360);
			}
		}

	private:
		int w;
		int h;
		int c;
	};

}
using namespace Graph_lib;

int main()
{
	Simple_window win{ Point{100,100},600,400,"EX01" };
	Box b{ Point{100,100},200,100,30 };
	b.set_color(Color::red);
	b.set_fill_color(Color::blue);
	win.attach(b);
	win.wait_for_button();

	return 0;
}
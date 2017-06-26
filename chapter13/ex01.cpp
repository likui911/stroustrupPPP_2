#include "Simple_window.h"
#include "Window.h"
#include "Graph.h"

//Define a class Arc, which draws a part of an ellipse. Hint: fl_arc().
namespace Graph_lib
{
	struct Arc :Shape
	{
		Arc(Point p, int ww, int hh, double aa, double bb) :w{ ww }, h{hh}, a{ aa }, b{ bb }
		{
			add(Point{ p.x - ww,p.y - hh });
		}

		void draw_lines()const
		{
			if (fill_color().visibility())
			{
				fl_color(fill_color().as_int());
				fl_pie(point(0).x, point(0).y, w + w - 1, h + h - 1, a, b);
				fl_color(color().as_int());	// reset color
			}
			if (color().visibility())
			{
				fl_color(color().as_int());
				fl_arc(point(0).x, point(0).y, w + w, h + h, a, b);
			}
		}

		Point center() const { return{ point(0).x + w, point(0).y + h }; }

		void set_major(int ww) { w = ww; }
		int major() const { return w; }
		void set_minor(int hh) { h = hh; }
		int minor() const { return h; }

	private:
		int w;
		int h;
		double a;
		double b;
	};

}
using namespace Graph_lib;

int main()
{
	Simple_window win{ Point{100,100},600,400,"EX01" };
	Arc arc{ Point{300,180},90,50,20,270 };
	arc.set_color(Color::red);
	win.attach(arc);
	win.wait_for_button();

	return 0;
}
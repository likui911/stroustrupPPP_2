/*
Define two classes Smiley and Frowny, which are both derived from class Circle and have two eyes and a mouth. Next,
derive classes from Smiley and Frowny which add an appropriate hat to each.
*/
#include "Simple_window.h"
#include "Graph.h"

class Smiley :public Circle
{
public:
	Smiley(Point p, int rr) :Circle(p, rr), r{ rr } {}
	virtual void draw_lines() const override;
private:
	int r;
};

void Smiley::draw_lines()const
{
	if (color().visibility())
	{
		//draw circle
		Circle::draw_lines();
		//draw mouth and eyes
		fl_arc(point(0).x +r/2, point(0).y+r/2 , r, r, 225, 315);
		fl_arc(point(0).x + r / 2, point(0).y + r / 2, r / 3, r / 3, 0, 360);
		fl_arc(point(0).x + r * 7 / 6, point(0).y + r / 2, r / 3, r / 3, 0, 360);
	}
}

class Frowny :public Circle
{
public:
	Frowny(Point p, int rr) :Circle{ p, rr }, r{ rr } {}
	virtual void draw_lines()const override;
private:
	int r;
};

void Frowny::draw_lines()const
{
	if (color().visibility())
	{
		//draw circle
		Circle::draw_lines();
		//draw mouth and eyes
		fl_arc(point(0).x + r / 2, point(0).y + r / 2, r, r, 225, 315);
		fl_arc(point(0).x + r / 2, point(0).y + r / 2, r / 3, r / 6, 0, 360);
		fl_arc(point(0).x + r * 7 / 6, point(0).y + r / 2, r / 3, r / 6, 0, 360);
	}

}

class SmileHat :public Smiley 
{
public:
	SmileHat(Point p, int rr) :Smiley{ p,rr }, r{ rr } {}
	void draw_lines()const override;
private:
	int r;
};

void SmileHat::draw_lines()const
{
	if (color().visibility())
	{
		Smiley::draw_lines();
		//draw hat
		Point top{ point(0).x + r,point(0).y };
		Point left{ point(0).x,point(0).y + r / 2 };
		Point right{ point(0).x+2*r,point(0).y + r / 2 };
		fl_line(top.x, top.y, left.x, left.y);
		fl_line(top.x, top.y, right.x, right.y);
	}
}

class FrownyHat :public Frowny
{
public:
	FrownyHat(Point p, int rr) :Frowny{ p,rr }, r{ rr } {}
	void draw_lines()const override;
private:
	int r;
};

void FrownyHat::draw_lines()const
{
	if (color().visibility())
	{
		Frowny::draw_lines();
		//draw hat
		Point top{ point(0).x + r,point(0).y };
		Point left{ point(0).x,point(0).y + r / 2 };
		Point right{ point(0).x + 2 * r,point(0).y + r / 2 };
		fl_line(top.x, top.y, left.x, left.y);
		fl_line(top.x, top.y, right.x, right.y);
	}
}

int main()
{	
	Simple_window win{ Point{100,100},400,300,"Similey" };
	SmileHat smi{ Point{100,100},60 };
	smi.set_color(Color::red);
	win.attach(smi);

	FrownyHat fri{ Point{ 300,100 },60 };
	fri.set_color(Color::red);
	win.attach(fri);
	win.wait_for_button();
	return 0;
}
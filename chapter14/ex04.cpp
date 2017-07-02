
#include "Simple_window.h"
#include "Graph.h"

class Immobile_Circle :public Circle
{
public:
	Immobile_Circle(Point p, int rr) :Circle(p, rr), r{ rr } {}
	void move(int dx,int dy) {}

private:
	int r;
};

int main()
{	
	Simple_window win{ Point{100,100},400,300,"Similey" };
	Immobile_Circle immobile{ Point{100,100},50 };
	win.attach(immobile);
	win.wait_for_button();
	immobile.move(50, 50);
	win.wait_for_button();
	return 0;
}
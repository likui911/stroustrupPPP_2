#include "Window.h"
#include "Gui.h"
#include "Graph.h"
using namespace Graph_lib;

struct Lines_Window :Window
{
	Lines_Window(Point xy,int w,int h,const string&label);
	Open_polyline lines;
	Menu color_menu;
	Button menu_button;
private:
	Button nextButton;
	Button quitButton;
	In_box next_x;
	In_box next_y;
	Out_box xy_out;
	void next();
	void quit();
	void press_red() { set_color(Color::red); hide_menu(); }
	void press_blue() { set_color(Color::blue); hide_menu();}
	void press_black() { set_color(Color::black); hide_menu();}
	void set_color(Color c);
	void show_menu();
	void hide_menu();
};

Lines_Window::Lines_Window(Point xy, int w, int h, const string&label)
	:Window(xy, w, h, label), 
	nextButton{ Point{x_max() - 150,0},70,20,"Next",[](void*,void* pw) {static_cast<Lines_Window*>(pw)->next(); } },
	quitButton{ Point{x_max() - 70,0},70,20,"Quit",[](void*,void* pw) {static_cast<Lines_Window*>(pw)->quit(); } },
	next_x{ Point{x_max() - 310,0},50,20,"next x:" },
	next_y{ Point{ x_max() - 210,0 },50,20,"next y:" },
	xy_out{ Point{100,0},100,20,"current (x,y)" },
	color_menu{Point{x_max()-70,40},70,20,Menu::vertical,"Color"},
	menu_button{ Point{x_max() - 80,40},80,20,"Color Menu",[] (void*,void* pw){static_cast<Lines_Window*>(pw)->show_menu(); }  }
{
	attach(nextButton);
	attach(quitButton);
	attach(next_x);
	attach(next_y);
	attach(xy_out);

	lines.set_color(Color::black);
	attach(lines);

	attach(menu_button);

	color_menu.attach(new Button{ Point{0,0},70,20,"Red",[](void*,void* pw) {static_cast<Lines_Window*>(pw)->press_red(); } });
	color_menu.attach(new Button{ Point{ 0,0 },70,20,"Blue",[](void*,void* pw) {static_cast<Lines_Window*>(pw)->press_blue(); } });
	color_menu.attach(new Button{ Point{ 0,0 },70,20,"Black",[](void*,void* pw) {static_cast<Lines_Window*>(pw)->press_black(); } });
	attach(color_menu);
	color_menu.hide();
}

void Lines_Window::next()
{
	int x = next_x.get_int();
	int y = next_y.get_int();
	lines.add(Point{ x,y });

	ostringstream ss;
	ss << "(" << x << "," << y << ")";
	xy_out.put(ss.str());
	redraw();
}

void Lines_Window::quit()
{
	hide();
}

void Lines_Window::set_color(Color c)
{
	lines.set_color(c);
	redraw();
}

void Lines_Window::hide_menu()
{
	color_menu.hide();
	menu_button.show();
}

void Lines_Window::show_menu()
{
	menu_button.hide();
	color_menu.show();
}

int main()
try {
	Lines_Window win{ Point{ 100,100 },600,400,"lines" };
	return gui_main();
}
catch (exception& e) {
	cerr << "exception: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Some exception\n";
	return 2;
}
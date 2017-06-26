#include "Simple_window.h"
#include "Window.h"
using namespace Graph_lib;

int main()
{
	Simple_window win{ Point{100,100},500,500,"My Window" };
	Lines lines;

	//横向格子
	for (int i = 1; i <=9; ++i)
	{
		lines.add(Point{50,i*50}, Point{ 450,i*50 });
	}
	//竖向格子
	for (int i = 1; i <=9; ++i)
	{
		lines.add(Point{ i*50,50 }, Point{ i*50,450 });
	}
	lines.set_color(Color::dark_green);
	win.attach(lines);

	Rectangle rect{ Point{50,50} ,Point{250,150} };
	rect.set_color(Color::red);
	rect.set_fill_color(Color::red);
	win.attach(rect);

	Image img1{ Point{50,150},"snow_cpp.jpg" };
	img1.set_mask(Point{10,110}, 100, 100);
	Image img2{ Point{ 150,250 },"snow_cpp.jpg" };
	img2.set_mask(Point{ 10,110 },100, 100);
	Image img3{ Point{ 50,350 },"snow_cpp.jpg" };
	img3.set_mask(Point{ 10,110 }, 100, 100);
	win.attach(img1);
	win.attach(img2);
	win.attach(img3);

	win.wait_for_button();
	Image img4{ Point{0,0},"th.jpg" };
	win.attach(img4);
	for (int i = 0; i < 8; ++i)
	{
		img4.move(0, 50);//下降一行
		for (int j = 0; j < 8; ++j)
		{
			img4.move(50, 0);
			win.wait_for_button();
		}
		img4.move(-400, 0);	//左移到第一列
	}
}
#define _USE_MATH_DEFINES
#include<iostream>
#include"Rectangle.h"
#include "Triangle.h"
#include "Circle.h"
using namespace std;
#ifdef ddd
namespace Geometry
{
	class Circle :public Shape
	{
		double radius;
	public:
		Circle(double radius, SHAPE_TAKE_PARAMETERS) : Shape(SHAPE_GIVE_PARAMETERS)
		{
			setRADIUS(radius);
		}
		~Circle() {}
		double getRADIUS()const
		{
			return radius;
		}
		void setRADIUS(double radius)
		{
			this->radius = radius;
		}
		double perimeter()const override
		{
			return radius * M_PI * 2;
		}
		double area()const override
		{
			return radius * radius * M_PI;
		}
		void info()const override
		{
			cout << typeid(*this).name() << endl;
			cout << "Radius: " << radius << endl;
			Shape::info();
		}
		void draw()const override
		{
			//HWND hwnd = FindWindow(NULL, LPCWSTR("inheritance - Microsoft Visual Studio"));
			HWND hwnd = GetConsoleWindow();
			HDC hdc = GetDC(hwnd);
			HPEN hpen = CreatePen(PS_SOLID, linewidth, setRGB(getCOLOR()));
			HBRUSH hbrush = CreateSolidBrush(setRGB(getCOLOR()));
			SelectObject(hdc, hpen);
			SelectObject(hdc, hbrush);
			Ellipse(hdc, start_x, start_y, start_x + radius * 2, start_y + radius * 2);
			DeleteObject(hpen);
			DeleteObject(hbrush);
			ReleaseDC(hwnd, hdc);
		}
	};
}
#endif // ddd

#define Figure_check
void main()
{
#ifdef Figure_check
	Geometry::Square square(50, 400, 70, 5, Geometry::Color::CONSOLE_RED);
    square.info();
    Geometry::Rectangle rect{ 150, 80, 400,150, 5, Geometry::Color::CONSOLE_YELLOW};
    rect.info();
	Geometry::EquilateralTriangle tri(80, 600, 200, 5, Geometry::Color::CONSOLE_GREEN);
	tri.info();
	Geometry::IsoscelesTriangle tri2(80, 100, 700, 200, 5, Geometry::Color::CONSOLE_RED);
	tri2.info();
	Geometry::RectangularTriangle tri3(70, 80, 800, 200, 5, Geometry::Color::CONSOLE_YELLOW);
	tri3.info();
	Geometry::Circle circ(40, 400,260,5, Geometry::Color::CONSOLE_BLUE);
	circ.info();

	cout << "Number of shapes: " << Geometry::Shape::getCOUNT() << endl;
#endif
}
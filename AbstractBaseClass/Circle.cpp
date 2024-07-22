#include"Circle.h"
namespace Geometry
{
	    Circle::Circle(double radius, SHAPE_TAKE_PARAMETERS) : Shape(SHAPE_GIVE_PARAMETERS)
		{
			setRADIUS(radius);
		}
		Circle::~Circle() {}
		double Circle::getRADIUS()const
		{
			return radius;
		}
		void Circle::setRADIUS(double radius)
		{
			this->radius = radius;
		}
		double Circle::perimeter()const
		{
			return radius * M_PI * 2;
		}
		double Circle::area()const 
		{
			return radius * radius * M_PI;
		}
		void Circle::info()const
		{
			cout << typeid(*this).name() << endl;
			cout << "Radius: " << radius << endl;
			Shape::info();
		}
		void Circle::draw()const
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
	
}
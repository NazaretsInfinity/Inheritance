#define _USE_MATH_DEFINES
#include<iostream>
#include<Windows.h>
#include"Shape.h"
using namespace std;
namespace Geometry
{
	int Shape::count = 0;
	class Rectangle :public  Shape
	{
		double width, height;
	public:
		Rectangle(double width, double height, SHAPE_TAKE_PARAMETERS) : Shape(SHAPE_GIVE_PARAMETERS) 
		{
			setWIDTH(width);
			setHEIGHT(height);
		}
		~Rectangle() {}
		void setWIDTH(double width)
		{
			this->width = filtersize(width);
		}
		void setHEIGHT(double height)
		{
			this->height = filtersize(height);
		}
		double area()const override
		{
			return width * height;
		}
		double perimeter()const override
		{
			return (width * height) * 2;
		}
		void draw()const override
		{
			HWND hwnd = GetConsoleWindow();
			HDC hdc = GetDC(hwnd);
			HPEN hPen = CreatePen(PS_SOLID, 5, setRGB(getCOLOR()));
			HBRUSH hBrush = CreateSolidBrush(setRGB(getCOLOR()));
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);
			::Rectangle(hdc, start_x,start_y,start_x+width,start_y+height);
			DeleteObject(hPen);
			DeleteObject(hBrush);
			ReleaseDC(hwnd, hdc);
		}

		void info()const override
		{
			cout << typeid(*this).name() << endl;
			Shape::info(); 
		}
	};
	class Square :public Rectangle
	{
	public:
		Square(double side, SHAPE_TAKE_PARAMETERS) :Rectangle(side, side, SHAPE_GIVE_PARAMETERS) {}
		~Square() {}
	};
	class Triangle : public Shape
	{
	public:
		Triangle(SHAPE_TAKE_PARAMETERS):Shape(SHAPE_GIVE_PARAMETERS){}
		~Triangle(){}
		virtual double getHEIGHT()const = 0;
	};
	class EquilateralTriangle : public Triangle
	{
		double side;
	public:
		EquilateralTriangle(double side, SHAPE_TAKE_PARAMETERS) : Triangle(SHAPE_GIVE_PARAMETERS)
		{
			setSIDE(side);
		}
	~EquilateralTriangle(){}
		double getSIDE()const
		{
			return side;
		}
		void setSIDE(double side)
		{
			this->side = filtersize(side);
		}
		double getHEIGHT()const override
		{
			return sqrt(side * side - side / 2 * side / 2);
		}
		double area()const override
		{
			return side * getHEIGHT() / 2;
		}
		double perimeter()const override
		{
			return side * 3;
		}
		void draw()const override
		{
			HWND hwnd = GetConsoleWindow();
			HDC hdc = GetDC(hwnd);

			HPEN hPen = CreatePen(PS_SOLID, linewidth, setRGB(color));
			HBRUSH hbrush = CreateSolidBrush(setRGB(color));
			POINT apt[] =
			{
				{start_x ,start_y+side},
				{start_x+side, start_y+side},
				{start_x+side/2,start_y+side-getHEIGHT()}
			};
			SelectObject(hdc, hPen);
			SelectObject(hdc, hbrush);
			Polygon(hdc, apt, 3);
			DeleteObject(hPen);
			DeleteObject(hbrush);
			ReleaseDC(hwnd, hdc);
		}
		void info()const override
		{
			cout << typeid(*this).name() << endl;
			cout << "Side: " << side << endl;
			Shape::info();
		}
	};
	class IsoscelesTriangle : public Triangle
	{
		double side,latside;
	public: 
		IsoscelesTriangle(double side, double latside, SHAPE_TAKE_PARAMETERS) :Triangle(SHAPE_GIVE_PARAMETERS)
		{
			setSIDE(side);
			setLATSIDE(latside);
		}
		~IsoscelesTriangle() {}
		 void setSIDE(double side)
		{
			this->side = side;
		}
		void setLATSIDE(double latside)
		{
			this->latside = latside;
		}
		double getHEIGHT()const override
		{
			return sqrt(latside * latside - side / 2 * side / 2);
		}
		double perimeter()const override
		{
			return 2 * latside + side;
	    }
		double area()const override
		{
			return side * getHEIGHT() / 2;
		}
		void draw()const override
		{
			HWND hwnd = GetConsoleWindow();
			HDC hdc = GetDC(hwnd);
			HPEN hpen = CreatePen(PS_SOLID, linewidth, setRGB(color));
			HBRUSH hbrush = CreateSolidBrush(setRGB(color));
			POINT apt[] =
			{
				{start_x + side / 2,start_y - getHEIGHT()},
				{start_x,start_y},
				{start_x + side,start_y}
			};
			SelectObject(hdc, hpen);
			SelectObject(hdc, hbrush);
			Polygon(hdc, apt, 3);
			DeleteObject(hpen);
			DeleteObject(hbrush);
			ReleaseDC(hwnd, hdc);
		}
		void info()const override
		{
			cout << typeid(*this).name() << endl;
			cout << "Side: " << side << "\tLateral side: " << latside << endl;
			Shape::info();
		}
	};
	class RectangularTriangle :public Triangle
	{
		double fside, sside;
	public:
	RectangularTriangle(double fside,double sside, SHAPE_TAKE_PARAMETERS):Triangle(SHAPE_GIVE_PARAMETERS),fside(fside),sside(sside){}
	~RectangularTriangle(){}
	void setFSIDE(double fside)
	{
		this->fside = filtersize(fside);
	}
	void setSSIDE(double sside)
	{
		this->sside = filtersize(sside);
	}
	double  getHYPOTENUS()const
	{
		return sqrt(fside * fside + sside * sside);
	}
	double getHEIGHT()const override
	{
		return fside * sside / getHYPOTENUS();
	}
	double perimeter()const override
	{
		return fside + sside + getHYPOTENUS();
	}
	double area()const override
	{
		return fside * sside / 2;
	}
	void draw()const override
	{
	    //HWND hwnd = FindWindow(NULL, LPCWSTR("inheritance - Microsoft Visual Studio"));
		HWND hwnd = GetConsoleWindow();
		HDC hdc = GetDC(hwnd);
		HPEN hpen = CreatePen(PS_SOLID, linewidth, setRGB(color));
		HBRUSH hbrush = CreateSolidBrush(setRGB(color));
		POINT apt[] =
		{
			{start_x,start_y-fside},
			{start_x,start_y},
			{start_x + sside,start_y}
		};
		SelectObject(hdc, hpen);
		SelectObject(hdc, hbrush);
		Polygon(hdc, apt, 3);
		DeleteObject(hpen);
		DeleteObject(hbrush);
		ReleaseDC(hwnd, hdc);
	}
	void info()const override
	{
		cout << typeid(*this).name() << endl;
		cout << "1st leg: " << fside << "\t2nd leg: " << sside << endl;
		Shape::info();
	}
	};
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
			Ellipse(hdc, start_x,start_y, start_x+radius*2,start_y+radius*2);
			DeleteObject(hpen);
			DeleteObject(hbrush);
			ReleaseDC(hwnd, hdc);
		}
	};
}
#define Figure_check
void main()
{
#ifdef Figure_check
    Geometry::Square square(50, 400 , 70, 5, Geometry::Color::CONSOLE_RED);
    square.info();
    Geometry::Rectangle rect{ 150, 80, 400,150, 5, Geometry::Color::CONSOLE_YELLOW};
    rect.info();
	Geometry::EquilateralTriangle tri(80, 600, 200, 5, Geometry::Color::CONSOLE_GREEN);
	tri.info();
	Geometry::IsoscelesTriangle tri2(80, 100, 700, 200, 5, Geometry::Color::CONSOLE_RED);
	tri2.info();
	Geometry::RectangularTriangle tri3(70, 80, 800, 200, 5, Geometry::Color::CONSOLE_YELLOW);
	tri3.info();
	Geometry::Circle circ(40, 400,260,1, Geometry::Color::CONSOLE_BLUE);
	circ.info();

	cout << "Number of shapes: " << Geometry::Shape::getCOUNT() << endl;
#endif
}
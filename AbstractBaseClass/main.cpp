#define _USE_MATH_DEFINES
#include<iostream>
#include<Windows.h>
using namespace std;
#ifdef AnimalAbstract
class Animal
{
public:
	virtual void sound() = 0;
};
class Cat : Animal {}; // Abstract either
class Tiger : Cat
{
public:
	void sound()override
	{
		cout << "RAAAAWR ROOOOOOOAR" << endl;
	}
};
class HomeCat : Cat
{
public:
	void sound()override
	{
		cout << "MEeeeEEEOoOoOW" << endl;
	}
};
#endif
namespace Geometry
{
	enum Color //enum(enumeration). It's a set of integer constants
	{
		CONSOLE_BLUE = 0x11,
		CONSOLE_GREEN = 0xAA,
		CONSOLE_RED = 0xCC,
		CONSOLE_YELLOW = 0x66,
		CONSOLE_DEFAULT = 0x07,
	};
#define SHAPE_TAKE_PARAMETERS	unsigned int start_x, unsigned int start_y, unsigned int linewidth, Color color
#define SHAPE_GIVE_PARAMETERS	start_x, start_y, linewidth, color
	class Shape
	{
	protected:
		Color color;
		int start_x, start_y, linewidth;

		static const int MINX = 100;
		static const int MAXX = 1000;
		static const int MINY = 100;
		static const int MAXY = 700;
		static const int MINLINE = 1;
		static const int MAXLINE = 32;
		static const int MINSIZE = 50;
		static const int MAXSIZE = 550;
		static int count;
	public:
		Shape(SHAPE_TAKE_PARAMETERS) : color(color)
		{
			set_start_x(start_x);
			set_start_y(start_y);
			set_line_width(linewidth);
			count++;
		}
		virtual ~Shape() {count--;}
		virtual double area()const = 0;
		virtual double perimeter()const = 0;
		virtual void draw()const = 0;
		//INCAPSULATION
		static int getCOUNT()
		{
			return count;
		}
		Color getCOLOR()const
		{
			return color;
		}
		unsigned int getX()const
		{
			return start_x;
		}
		unsigned int getY()const
		{
			return start_y;
		}
		unsigned int get_linewidth()const
		{
			return linewidth;
		}
		void set_start_x(unsigned int start_x)
		{
			if (start_x < MINX)start_x = MINX;
			if (start_x > MAXX) start_x = MAXX;
		   this->start_x = start_x;
		}
		void set_start_y(unsigned int start_y)
		{
			if (start_y < MINY)start_y = MINY;
			if (start_y > MAXY)start_y = MAXY;
			this->start_y = start_y;
		}
		void set_line_width(unsigned int line_width)
		{
			if (line_width < MINLINE)line_width = MINLINE;
			if (line_width > MAXLINE)line_width = MAXLINE;
			this->linewidth = line_width;
		}
		double filtersize(double size)
		{
			if (size < MINSIZE)size = MINSIZE;
			if (size > MAXSIZE)size = MAXSIZE;
			return size;
		}
		void setCOLOR(Color color)
		{
			this->color = color;
		}
		COLORREF setRGB(Color color)const
		{
			switch (color)
			{
			case CONSOLE_BLUE: return 0xFF0000; break;
			case CONSOLE_RED: return 0x0000FF; break;
			case CONSOLE_GREEN: return 0x00FF00; break;
			case CONSOLE_YELLOW: return 0x0000FFFF; break;
			}
		}
		virtual void info()const
		{

			cout << "Area of figure: " << area() << endl;
			cout << "Perimeter of figure: " << perimeter() << "\n\n";
			draw();
		}
	}; int Shape::count = 0;
#ifdef SQUARE
	class Square : public Shape
	{
		double side;
	public:
		Square(double side, Color color) : Shape(color), side(side) {}
		virtual ~Square() {}
		double area()const override
		{
			return side * side;
		}
		double perimeter()const override
		{
			return side * 4;
		}
		void draw()const override
		{
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, (getCOLOR()));
			for (int i = 0; i < side; i++)
			{
				for (int i = 0; i < side; i++)
					cout << "* ";
				cout << endl;
			}
			SetConsoleTextAttribute(hConsole, CONSOLE_DEFAULT);
		}
		double getSIDE()const
		{
			return side;
		}
		void setSIDE(double side)
		{
			this->side = side;
		}
		void info()const override
		{
			cout << typeid(*this).name() << endl;
			cout << "The lenght of the side" << side << endl;
			Shape::info();
		}
	};
#endif 

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
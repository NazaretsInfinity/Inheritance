#include<Windows.h>
#include<iostream>
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
	public:
		Shape(SHAPE_TAKE_PARAMETERS) : color(color),start_x(start_x),start_y(start_y),linewidth(linewidth) {}
		virtual ~Shape() {}
		virtual double area()const = 0;
		virtual double perimeter()const = 0;
		virtual void draw()const = 0;
		//INCAPSULATION
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
			this->start_x = start_x;
		}
		void set_start_y(unsigned int start_y)
		{
			this->start_y = start_y;
		}
		void set_line_width(unsigned int line_width)
		{
			this->linewidth = linewidth;
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
			case CONSOLE_YELLOW: return 0x00FFFF; break;
			}
		}
		virtual void info()const
		{

			cout << "Area of figure: " << area() << endl;
			cout << "Perimeter of figure: " << perimeter() << endl;
			draw();
		}
	};
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

	class Rectangle : Shape
	{
		double width, height;
	public:
		Rectangle(double width, double height, SHAPE_TAKE_PARAMETERS) : Shape(SHAPE_GIVE_PARAMETERS), width(width), height(height) {}
		~Rectangle() {}

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
			Shape::info(); cout << endl;
		}
	};
	class Square :public Rectangle
	{
	public:
		Square(double side, SHAPE_TAKE_PARAMETERS) :Rectangle(side, side, SHAPE_GIVE_PARAMETERS) {}
		~Square() {}
	};
#ifdef Triangle_3side_members
	class Triangle : public Shape
	{
		int f_side, sec_side, thrd_side;
	public:
		Triangle(int fs, int ss, int ts, Color color) : Shape(color), f_side(fs), sec_side(ss), thrd_side(ts) {}
		~Triangle() {}
		double perimeter()const override { return f_side + sec_side + thrd_side; }
		double area()const override
		{
			double p = perimeter() / 2;
			return sqrt(p * (p - f_side) * (p - sec_side) * (p - thrd_side));
		}
		void info()const override
		{
			cout << typeid(*this).name() << endl;
			cout << "1st side: " << f_side << "\t2nd side: " << sec_side << "\t3rd side: " << thrd_side << endl;
			Shape::info(); cout << endl;
		}
		void draw()const override
		{
			HWND hwnd = GetConsoleWindow();
			HDC hdc = GetDC(hwnd);
			HPEN hPen = CreatePen(PS_SOLID, 5, setRGB(getCOLOR()));

			HBRUSH hBrush = CreateSolidBrush(setRGB(getCOLOR()));

			const POINT verts[3] = { {650,50}, {600,150}, {700,150} };
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);
			Polygon(hdc, verts, 3);
			DeleteObject(hPen);
			DeleteObject(hBrush);
			ReleaseDC(hwnd, hdc);
		}
	};
#endif 
	class Circle : Shape
	{
		double radius; 
	public: 
		Circle(double radius, SHAPE_TAKE_PARAMETERS) : Shape(SHAPE_GIVE_PARAMETERS), radius(radius){}
		~Circle() {}
		double perimeter()const override
		{
			return radius * 3.14 * 2;
		}
		double area()const override
		{
			return radius * radius * 3.14;
		}
		void info()const override
		{
			cout << typeid(*this).name() << endl; 
			cout << "Radius: " << radius << endl;
			Shape::info(); cout << endl;
	    }
		void draw()const override
		{
			HWND hwnd = GetConsoleWindow();
			HDC hdc = GetDC(hwnd);
			HPEN hpen = CreatePen(PS_SOLID, 5, setRGB(getCOLOR()));
			HBRUSH hbrush = CreateSolidBrush(setRGB(getCOLOR()));
			SelectObject(hdc, hpen);
			SelectObject(hdc, hbrush);
			Ellipse(hdc, start_x,start_y, start_x+radius,start_y+radius);
			DeleteObject(hpen);
			DeleteObject(hbrush);
			ReleaseDC(hwnd, hdc);
		}
	};

}
void main()
{
    //Geometry::Square square(5, Geometry::Color::CONSOLE_RED);
    //square.info();
    Geometry::Rectangle rect{ 15, 8, Geometry::Color::CONSOLE_BLUE};
    rect.info();
	Geometry::Triangle tri(3, 4, 5, Geometry::Color::CONSOLE_GREEN);
	tri.info();
	Geometry::Circle circ(4, Geometry::Color::CONSOLE_YELLOW);
	circ.info();
}
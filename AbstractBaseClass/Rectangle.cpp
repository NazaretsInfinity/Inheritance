#include"Rectangle.h"
    Geometry::Rectangle::Rectangle(double width, double height, SHAPE_TAKE_PARAMETERS) : Shape(SHAPE_GIVE_PARAMETERS)
	{
		setWIDTH(width);
		setHEIGHT(height);
	}
	Geometry::Rectangle::~Rectangle() {}
	void Geometry::Rectangle::setWIDTH(double width)
	{
		this->width = filtersize(width);
	}
	void Geometry::Rectangle::setHEIGHT(double height)
	{
		this->height = filtersize(height);
	}
	double Geometry::Rectangle::area()const
	{
		return width * height;
	}
	double Geometry::Rectangle::perimeter()const
	{
		return (width * height) * 2;
	}
	void Geometry::Rectangle::draw()const
	{
		HWND hwnd = GetConsoleWindow();
		HDC hdc = GetDC(hwnd);
		HPEN hPen = CreatePen(PS_SOLID, 5, setRGB(getCOLOR()));
		HBRUSH hBrush = CreateSolidBrush(setRGB(getCOLOR()));
		SelectObject(hdc, hPen);
		SelectObject(hdc, hBrush);
		::Rectangle(hdc, start_x, start_y, start_x + width, start_y + height);
		DeleteObject(hPen);
		DeleteObject(hBrush);
		ReleaseDC(hwnd, hdc);
	}

	void Geometry::Rectangle::info()const
	{
		cout << typeid(*this).name() << endl;
		Shape::info();
	}

	Geometry::Square::Square(double side, SHAPE_TAKE_PARAMETERS) :Rectangle(side, side, SHAPE_GIVE_PARAMETERS) {}
	Geometry::Square::~Square() {}
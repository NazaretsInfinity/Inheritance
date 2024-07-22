#include"Triangle.h"
namespace Geometry
{
	Triangle::Triangle(SHAPE_TAKE_PARAMETERS) : Shape(SHAPE_GIVE_PARAMETERS) {}
	Triangle::~Triangle() {}

	EquilateralTriangle::EquilateralTriangle(double side, SHAPE_TAKE_PARAMETERS) : Triangle(SHAPE_GIVE_PARAMETERS)
	{
		setSIDE(side);
	}
	EquilateralTriangle::~EquilateralTriangle() {}
	double EquilateralTriangle::getSIDE()const
	{
		return side;
	}
	void EquilateralTriangle::setSIDE(double side)
	{
		this->side = filtersize(side);
	}
	double EquilateralTriangle::getHEIGHT()const
	{
		return sqrt(side * side - side / 2 * side / 2);
	}
	double EquilateralTriangle::area()const
	{
		return side * getHEIGHT() / 2;
	}
	double EquilateralTriangle::perimeter()const
	{
		return side * 3;
	}
	void EquilateralTriangle::draw()const
	{
		HWND hwnd = GetConsoleWindow();
		HDC hdc = GetDC(hwnd);

		HPEN hPen = CreatePen(PS_SOLID, linewidth, setRGB(color));
		HBRUSH hbrush = CreateSolidBrush(setRGB(color));
		POINT apt[] =
		{
			{start_x ,start_y + side},
			{start_x + side, start_y + side},
			{start_x + side / 2,start_y + side - getHEIGHT()}
		};
		SelectObject(hdc, hPen);
		SelectObject(hdc, hbrush);
		Polygon(hdc, apt, 3);
		DeleteObject(hPen);
		DeleteObject(hbrush);
		ReleaseDC(hwnd, hdc);
	}
	void EquilateralTriangle::info()const
	{
		cout << typeid(*this).name() << endl;
		cout << "Side: " << side << endl;
		Shape::info();
	}
	IsoscelesTriangle::IsoscelesTriangle(double side, double latside, SHAPE_TAKE_PARAMETERS) :Triangle(SHAPE_GIVE_PARAMETERS)
	{
		setSIDE(side);
		setLATSIDE(latside);
	}
	IsoscelesTriangle::~IsoscelesTriangle() {}
	void IsoscelesTriangle::setSIDE(double side)
	{
		this->side = side;
	}
	void IsoscelesTriangle::setLATSIDE(double latside)
	{
		this->latside = latside;
	}
	double IsoscelesTriangle::getHEIGHT()const
	{
		return sqrt(latside * latside - side / 2 * side / 2);
	}
	double IsoscelesTriangle::perimeter()const
	{
		return 2 * latside + side;
	}
	double IsoscelesTriangle::area()const
	{
		return side * getHEIGHT() / 2;
	}
	void IsoscelesTriangle::draw()const
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
	void IsoscelesTriangle::info()const
	{
		cout << typeid(*this).name() << endl;
		cout << "Side: " << side << "\tLateral side: " << latside << endl;
		Shape::info();
	}
	RectangularTriangle::RectangularTriangle(double fside, double sside, SHAPE_TAKE_PARAMETERS) :Triangle(SHAPE_GIVE_PARAMETERS), fside(fside), sside(sside) {}
	RectangularTriangle::~RectangularTriangle() {}
	void RectangularTriangle::setFSIDE(double fside)
	{
		this->fside = filtersize(fside);
	}
	void RectangularTriangle::setSSIDE(double sside)
	{
		this->sside = filtersize(sside);
	}
	double  RectangularTriangle::getHYPOTENUS()const
	{
		return sqrt(fside * fside + sside * sside);
	}
	double RectangularTriangle::getHEIGHT()const
	{
		return fside * sside / getHYPOTENUS();
	}
	double RectangularTriangle::perimeter()const
	{
		return fside + sside + getHYPOTENUS();
	}
	double RectangularTriangle::area()const
	{
		return fside * sside / 2;
	}
	void RectangularTriangle::draw()const
	{
		//HWND hwnd = FindWindow(NULL, LPCWSTR("inheritance - Microsoft Visual Studio"));
		HWND hwnd = GetConsoleWindow();
		HDC hdc = GetDC(hwnd);
		HPEN hpen = CreatePen(PS_SOLID, linewidth, setRGB(color));
		HBRUSH hbrush = CreateSolidBrush(setRGB(color));
		POINT apt[] =
		{
			{start_x,start_y - fside},
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
	void RectangularTriangle::info()const
	{
		cout << typeid(*this).name() << endl;
		cout << "1st leg: " << fside << "\t2nd leg: " << sside << endl;
		Shape::info();
	}
}
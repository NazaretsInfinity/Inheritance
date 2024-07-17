#include<iostream>
#include<Windows.h>
using namespace std;
#ifdef FIGURES
class Figures
{
public:
	virtual double perimeter() = 0;
	virtual double square() = 0;
	virtual void info() = 0;
};
class Polygon : public Figures
{
public:
	void info()override
	{
		cout << "Perimeter: " << perimeter() << "\t" << "Area: " << square() << "\n\n";
	}
};
class Round : Figures {};

class Rectangle : public Polygon
{
	int width, height;
public:
	//constr
	Rectangle(int width, int height) : height(height), width(width)
	{
		cout << "RectangleConstr\t" << this << endl;
	}
	//meth
	double perimeter()override
	{
		return 2 * (height + width);
	}

	double square()override
	{
		return height * width;
	}

	void info()override
	{
		cout << "Width: " << width << endl;
		cout << "Height: " << height << endl;
		Polygon::info();
	}
	//destr
	~Rectangle()
	{
		cout << "RectnglDestr:\t" << this << endl;
	}
};
class Square : public Rectangle
{
public:
	Square(int size) : Rectangle(size, size)
	{
		cout << "SquareConstr:\t" << this << endl;
	}
	~Square()
	{
		cout << "SquareDestr:\t" << this << endl;
	}
};


class Triangle : public Polygon
{
	int f_side, sec_side, thrd_side;
public:
	Triangle(int fs, int ss, int ts) : f_side(fs), sec_side(ss), thrd_side(ts)
	{
		cout << "TriangleConstr:\t" << this << endl;
	}
	~Triangle()
	{
		cout << "TriangleDestr:\t" << this << endl;
	}
	double perimeter()override { return f_side + sec_side + thrd_side; }
	double square()override
	{
		double p = perimeter() / 2;
		return sqrt(p * (p - f_side) * (p - sec_side) * (p - thrd_side));
	}
	void info()override
	{
		cout << "First side: " << f_side << endl << "Second side: " << sec_side << endl << "Third side: " << thrd_side << endl;
		Polygon::info();
	}
};

class Circle : public Round
{
	int radius;
public:
	Circle(int radius) : radius(radius)
	{
		cout << "CircleConstr:\t" << this << endl;
	}
	double perimeter()override
	{
		return radius * 3.14 * 2;
	}
	double square()override
	{
		return radius * radius * 3.14;
	}
	void info()override
	{
		cout << "Radius: " << radius << endl;
		cout << "Lenght: " << perimeter() << "\t" << "Area: " << square() << "\n\n";
	}
};
#endif // CLASSES
void main()
{
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
for (int i = 0; i < 256; i++)
{
   SetConsoleTextAttribute(hConsole, i);
   cout << i << ": Hey! Ho! Let's go!" << endl;
}
}
#pragma once
#define _USE_MATH_DEFINES
#include<iostream>
#include<Windows.h>
using namespace std;
namespace Geometry
{
	enum Color
	{
		CONSOLE_BLUE = 0x11,
		CONSOLE_GREEN = 0xAA,
		CONSOLE_RED = 0xCC,
		CONSOLE_YELLOW = 0x66,
		CONSOLE_DEFAULT = 0x07
	};
#define SHAPE_TAKE_PARAMETERS	unsigned int start_x, unsigned int start_y, unsigned int linewidth, Geometry::Color color
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
		Shape(SHAPE_TAKE_PARAMETERS);
		virtual ~Shape();
		virtual double area()const = 0;
		virtual double perimeter()const = 0;
		virtual void draw()const = 0;
		//INCAPSULATION
		static int getCOUNT();
		Color getCOLOR()const;
		unsigned int getX()const;
		unsigned int getY()const;
		unsigned int get_linewidth()const;
		void set_start_x(unsigned int start_x);
		void set_start_y(unsigned int start_y);
		void set_line_width(unsigned int line_width);
		double filtersize(double size);
		void setCOLOR(Color color);
		COLORREF setRGB(Color color)const;
		virtual void info()const;
	}; 
	class Triangle : public Shape
	{
	public:
		Triangle(SHAPE_TAKE_PARAMETERS);
		~Triangle();
		virtual double getHEIGHT()const = 0;
	};
}
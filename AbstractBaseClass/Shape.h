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
		virtual ~Shape() { count--; }
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
	};
}